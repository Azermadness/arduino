#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <ArduinoOTA.h>
#include <LittleFS.h>

//Wifi connection & server
#define SSID "FREEBOX_SUZANNE_JG" //Wifi SSID 
#define PASS "llebant-litati-forti1-endum" //Wifi Password
const long utcOffsetInSeconds = 7200 ;
ESP8266WebServer server(80);
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

//Screen setup
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// setup DHT
#define DHTPIN 5
#define DHTTYPE 11
DHT dht(DHTPIN, DHTTYPE);

void OTA() //Allow update from network
{
	ArduinoOTA.handle();
	ArduinoOTA.setPort(8266);
	ArduinoOTA.setHostname("meteo_Station");
	ArduinoOTA.setPassword("Password");
	ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH)
      type = "sketch";
    else // littleFS
      type = "filesystem";
	  Serial.println("Start updating " + type);
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });
  ArduinoOTA.begin();
}

void NTP() //Get Hour from NTP
{
	timeClient.begin();
  	timeClient.update();
	display.clearDisplay();
	display.setCursor(5, 0);
	display.setTextSize(2);
	display.println(timeClient.getFormattedTime());
	display.display();
  	delay(10000);
}

void WIFI() //Connect to network
{
	while (WiFi.status() != WL_CONNECTED)
  {
	display.clearDisplay();
	display.setTextSize(2);
	display.setCursor(5,0);
	display.println("Connecting to: ");
	display.println(SSID);
	display.display();
	Serial.print("Connecting...");
	WiFi.begin(SSID, PASS);
	delay(10000);
  }
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(5,0);
  display.println("Network IP:");
  display.println(WiFi.localIP());
  display.display();
  delay(5000);
}

float Temp() //Get temperature 
{
 	float Temp = 0;
 	Temp = dht.readTemperature();
	return Temp;
}

float Humi() //Get Humidity
{
	float Hum = 0;
	Hum = dht.readHumidity();
	return Hum;
}

void Local_temp() //Show on Oled screen local temp and hum
{
	display.clearDisplay();
  	display.setTextSize(2);
  	display.setCursor(5, 10);
  	display.println("Temp:");
	display.setCursor(65, 10);
	display.println(Temp());
	display.setCursor(5, 30);
	display.println("Hum:");
	display.setCursor(55, 30);
	display.println(Humi());
	display.display();
	delay(2500);
}

String SendHTML(float Temperature,float humidity)
{
	String ptr = "<!DOCTYPE html> <html>\n";
	ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
	ptr +="<title>ESP8266 Weather Station</title>\n";
	ptr +="<style>{html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
	ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;}\n";
	ptr +="p {font-size: 24px;color: #444444;margin-bottom: 10px;}}\n";
	ptr +="</style>\n";
	ptr +="</head>\n";
	ptr +="<body>\n";
	ptr +="<div id=\"webpage\">\n";
	ptr +="<h1>ESP8266 Weather Station</h1>\n";
	ptr +="<p>Temperature: ";
	ptr +=Temperature;
	ptr +="&deg;C</p>";
	ptr +="<p>Humidity: ";
	ptr +=humidity;
	ptr +="</div>\n";
	ptr +="</body>\n";
	ptr +="</html>\n";
	return ptr;
}

void handleRoot()
{
	server.send(200, "text/plain", SendHTML(Temp(), Humi
()));
}

void http() //WebServer 
{
	server.on("/", handleRoot);
	server.begin();
}

void setup() //Setup loop
{
	Wire.begin(2,14);
	Serial.begin(9600);
	dht.begin();
	display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  	delay(2000);
  	display.setFont();
  	display.setTextColor(WHITE);
	delay(2000);
	LittleFS.begin();
	http();
}

void loop() 
{
	OTA();
	WIFI();
	OTA();
	NTP();
	OTA();
  	Local_temp();
	OTA();
	server.handleClient();
}

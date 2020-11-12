#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <ArduinoOTA.h>
#include <LittleFS.h>
#include <FS.h>
#include <JSON.h>

//Wifi connection & server
#define SSID "Redmi Note 9" //Wifi SSID 
#define PASS "plus simple" //Wifi Password
ESP8266WebServer server(80);
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "fr.pool.ntp.org");

//Screen setup
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// setup DHT
#define DHTPIN 5
#define DHTTYPE 11
DHT dht(DHTPIN, DHTTYPE);

// api setup
String jsonweather;
String city = "Reims";
String country = "FR";
String weather_KEY = "3aeca48a574d432bbca92351a2c9a270"; // API key for weatherbit
String weather_server = "http://api.weatherbit.io/v2.0/current?city="+city+"&country="+country+"&key="+weather_KEY;

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
	HTTPClient http;

}

void OTA() //Allow update from network
{
	/*server.serveStatic("/update", LittleFS, "/update.html");
	server.on(/update);JSON 
	
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
  ArduinoOTA.begin();*/
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
	delay(5000);
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
 	float Temp = dht.readTemperature();
	return Temp;
}

float Humi() //Get Humidity
{
	float Hum = dht.readHumidity();
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

void http() //WebServer 
{
	server.serveStatic("/", LittleFS, "/index.html");
	/*	server.serveStatic("/", LittleFS, "/style.css");
	server.serveStatic("/", LittleFS, "/script.js");*/
	server.handleClient();
	server.begin();
}

void loop() 
{
	WIFI();
	NTP();
  	Local_temp();
	http();
}

void API() //API key 
{
	/*JSONVar weather =  http.begin(weather_server.c_str());
	weather = JSON.parse(weather);
	Serial.print(weather["data"]["temp"]);
	Serial.print(weather["data"]["pres"]);
*/
}
#include <Wire.h>
#include "SSD1306Wire.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <Brain.h>
#include "forms.h"

SSD1306Wire  display(0x3c, D1, D2);

char* curSSID = "MindControlDevice";
char* curPASS = "4g6Hkj9%";
IPAddress curIP;
int intServerStatus = 0; //0=not initialized, 1=AP mode, 2=Station;
int intPushMode = 0; //0=no push, 1= push to ip, 2=push to service
IPAddress pushIP;



ESP8266WebServer server(80);

void handleRoot() {
  Serial.println("Device COnnected");
  if(server.hasArg("ssid")&&server.hasArg("pass")){
    
    server.arg("ssid").toCharArray(curSSID, server.arg("ssid").length());
    server.arg("pass").toCharArray(curPASS, server.arg("pass").length());
    Serial.print(curSSID);
    connectToNetwork();
  }
  
  
  server.send(200, "text/html", frmConnect);
}

void handleFeed() {
  Serial.println("Device COnnected");
  Serial.println("returnfeed");
  server.send(200, "application/json", "{}");
}

void connectToNetwork(){
    Serial.print("Attempting to connect to network, SSID: ");
    Serial.println(curSSID);
    WiFi.mode(WIFI_STA);
    WiFi.begin(curSSID, curPASS);
}

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  //TODO: Initialize ESP8266
  display.init();
  display.flipScreenVertically();
  display.clear();
  display.setFont(ArialMT_Plain_16);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  //TODO: Splash Screen
  display.drawString(0,10,"D3BUGd D3VIC3");
  display.display();
  delay(500);
  //TEMP: setup AP:
  WiFi.mode(WIFI_AP);
  WiFi.softAP(curSSID, curPASS);
  curIP = WiFi.softAPIP();
  Serial.println(curIP);
  
  server.on("/", handleRoot);
  server.begin();

  
  display.clear();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(0,0,"SSID:");
  display.drawString(30,0,curSSID);
  display.drawString(0,10,"pass:");
  display.drawString(30,10,curPASS);
  display.drawString(0,20,"IP:");
  display.drawString(30,20,curIP.toString());
 
  
  display.display();
  
  //TODO: Scan for exhisting connection
    //TODO: if no conn Generate random CODE 
    //TODO: if no conn Display:HOSTNAME, CODE and IP REQ Addr
  Serial.println("READY");
}

void loop() {
  // put your main code here, to run repeatedly:
  //TODO: check for connection
  //TODO: If device connected serve form to set new wifi
  //TODO: if in station mode 
    //TODO: display IP
    //TODO: Read/store serial 
    //TODO: if set to push data
      //TODO: push data to service on network
    //TODO: If connection to server, serve stored data
    //TODO: display serial.
 server.handleClient();
 display.display();
}

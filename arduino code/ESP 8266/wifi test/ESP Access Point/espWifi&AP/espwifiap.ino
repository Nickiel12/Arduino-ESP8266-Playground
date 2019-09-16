#include <ESP8266WiFi.h>        // Include the Wi-Fi library

const char *ssidap = "ESP8266 Access Point"; // The name of the Wi-Fi network that will be created
const char *passwordap = "supersecure";   // The password required to connect to it, leave blank for an open network

const char *ssid = "Guest";
const char *password = "Twyckenham";

void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  delay(10);
  Serial.println('\n');

  WiFi.begin(ssid, password);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  WiFi.softAP(ssidap, passwordap);             // Start the access point
  Serial.print("Access Point \"");
  Serial.print(ssid);
  Serial.println("\" started");

  Serial.print("IP address:\t");
  Serial.println(WiFi.softAPIP());         // Send the IP address of the ESP8266 to the computer
}

void loop() { }
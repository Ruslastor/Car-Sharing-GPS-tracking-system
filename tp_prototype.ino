#include <SoftwareSerial.h>
#include <GyverPower.h>
// SIM800L module connections
#define SIM800_RX_PIN 5
#define SIM800_TX_PIN 4

// GPS module connections
#define GPS_RX_PIN 3
#define GPS_TX_PIN 2

// Digital pin for checking low-level signal
#define SIGNAL_PIN 0

#define SIM800_POWER_PIN 6
#define GPS_POWER_PIN 7


SoftwareSerial sim800(SIM800_TX_PIN, SIM800_RX_PIN);
SoftwareSerial gps(GPS_TX_PIN, GPS_RX_PIN);

const char* phoneNumber = "+48_________";

void setup() {
  power.setSleepMode(POWERDOWN_SLEEP);
  sim800.begin(9600);
  gps.begin(9600);

  pinMode(SIGNAL_PIN, INPUT_PULLUP);

  pinMode(SIM800_POWER_PIN, OUTPUT);
  pinMode(GPS_POWER_PIN, OUTPUT);

  digitalWrite(SIM800_POWER_PIN, HIGH);
  digitalWrite(GPS_POWER_PIN, HIGH);


  delay(2000);
}

void loop() {
  if (!digitalRead(SIGNAL_PIN)) {
    sendSMS(getGPSLocation());
    delay(1000); // Delay to avoid multiple SMS sending for a single low-level signal
  }

  // Other code or tasks to perform in the loop
}

String getGPSLocation() {
  String latitude, longitude;

  while (gps.available()) {
    char c = gps.read();
    if (c == '$') {
      String gpsData = gps.readStringUntil('\n');
      if (gpsData.startsWith("$GPRMC")) {
        // Parse latitude and longitude from GPS data
        int commaIndex1 = gpsData.indexOf(',', 20);
        int commaIndex2 = gpsData.indexOf(',', commaIndex1 + 1);
        int commaIndex3 = gpsData.indexOf(',', commaIndex2 + 1);
        int commaIndex4 = gpsData.indexOf(',', commaIndex3 + 1);
        int commaIndex5 = gpsData.indexOf(',', commaIndex4 + 1);

        if (commaIndex1 > 0 && commaIndex2 > 0 && commaIndex3 > 0 && commaIndex4 > 0 && commaIndex5 > 0) {
          latitude = gpsData.substring(commaIndex3 + 1, commaIndex4);
          longitude = gpsData.substring(commaIndex5 + 1, commaIndex5 + 10);
        }
      }
    }
  }

  return "GPS Location: Latitude - " + latitude + ", Longitude - " + longitude;
}

void sendSMS(String message) {
  sim800.println("AT");
  delay(100);
  sim800.println("AT+CMGF=1");
  delay(100);
  sim800.println("AT+CMGS=\"" + String(phoneNumber) + "\"");
  delay(100);
  sim800.println(message);
  delay(100);
  sim800.println((char)26);
  delay(100);
}

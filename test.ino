// define the led pin postion
const int ledPin = 11;
// DHT sensor
#include "DHT.h"
//connect digital pin to the DHT sensor
#define DHTPIN 21

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(38400);
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();

  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(ledPin, HIGH);
  Serial.println("LED ON");
  delay(1000);
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if(isnan(h) || isnan(t) || isnan(f)){
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  float hif = dht.computeHeatIndex(f,h);
  float hic = dht.computeHeatIndex(t, h, false);
  
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
  
  
  digitalWrite(ledPin, LOW);
  Serial.println("LED OFF");
  delay(1000);

  
}

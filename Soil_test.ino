const int ledPin = 11;
const int soilPin = 20;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9800);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(soilPin);
  Serial.print("Soil: ");
  Serial.println(val);
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}

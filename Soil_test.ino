const int ledPin = 12;
const int soilPin = 20;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9800);
  # Connect to Bluetooth
  Serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial1.available() > 0){
    int val = analogRead(soilPin);
    Serial.print("Soil: ");
    Serial.println(val);
    Serial1.print("Soil: ");
    Serial1.println(val);
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
  }
}

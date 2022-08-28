const int ledPin = 11;
  #define rxPin 7
  #define txPin 8
  void setup() {
  // Setup serial for monitor and Setup Serial1 for BlueTooth
  Serial.begin(9600);  
  Serial1.begin(9600); 
  pinMode(ledPin, OUTPUT);
  }
  
  void loop() {
  // Process commands from bluetooth first.
    if(Serial1.available() > 0){
      String str = Serial1.readString();
      // str.trim();      
      if(str == "on"){
      digitalWrite(ledPin, HIGH);
      }
      else if(str == "off"){
    digitalWrite(ledPin, LOW);
   
  }
  }   
  }

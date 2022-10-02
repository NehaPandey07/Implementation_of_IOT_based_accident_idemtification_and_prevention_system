
//IR Sensor config 
int IRSensor = 2; // connect ir sensor to arduino pin 2
int LED = 13; // conect Led to arduino pin 13
int buzzer=10;

//Alcohol  Sensor config 
#define Sober 50   // Define max value that we consider sober
#define Drunk 100  // Define min value that we consider drunk
#define MQ3pin 0

float sensorValue;  //variable to store sensor value


void setup() {
  //IR Sensor pin config 
  pinMode (IRSensor, INPUT); // sensor pin INPUT
  pinMode (LED, OUTPUT); // Led pin OUTPUT
   pinMode (buzzer, OUTPUT); //buzzer config

  //Alcohol Sensor Pin config
  Serial.begin(9600); // sets the serial port to 9600
  Serial.println("MQ3 warming up!");
  delay(2000); // allow the MQ3 to warm up
//  digitalWrite(Relay,HIGH);

}

void loop() {
  
// digitalWrite(Relay,HIGH);
  ///IR sensor logic
  int statusSensor = digitalRead (IRSensor);
  if (statusSensor == 1){
    digitalWrite(LED, HIGH); // LED LOW
  }
  else
  {
    digitalWrite(LED,LOW);
  }
  
  
  if( statusSensor == LOW){
  

//  //Alcohol Logic 
 
  

 sensorValue = analogRead(MQ3pin); // read analog input pin 0
 /////////////
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  
  // Determine the status
  if (sensorValue < Sober) {
    Serial.println("  |  Status: Stone Cold Sober");
    digitalWrite(buzzer, LOW);
    
  } else if (sensorValue >= Sober && sensorValue < Drunk) {
    Serial.println("  |  Status: Drinking but within legal limits");
    digitalWrite(buzzer, LOW);
   
  } else {
    Serial.println("  |  Status: DRUNK");
    
    digitalWrite(buzzer, HIGH);
 
  }
  
  delay(2000); // wait 2s for next reading

}
}

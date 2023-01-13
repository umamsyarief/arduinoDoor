// defines pins numbers
#include <Servo.h>
#define ldr A2 //Deklarasi variabel ldr untuk PIN A0
const int trigPin = 10;
const int echoPin = 9;
const int buzzer = 11;
const int ledPin = 13;
    
Servo myservo;        
// defines variables
long duration;
int distance;
int safetyDistance;
int dataLDR; //Variabel untuk menyimpan data dari sensor cahaya



void setup() {
  myservo.attach(5);
  pinMode(ldr, INPUT); //Menetapkan ldr sebagai inputan  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  dataLDR = analogRead(ldr);
  Serial.print("Cahaya: ");
  Serial.println(dataLDR);
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(20);
  
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  
  duration = pulseIn(echoPin, HIGH);
  
  distance= duration*0.034/2;
  
  safetyDistance = distance;
  if (safetyDistance <= 5){ //jika jarak nya dekat maka
    tone(buzzer, 100); //buzzer nyala
    if(dataLDR <= 750){
      digitalWrite(ledPin, HIGH); // lmapu nyala
    }else{
      myservo.write(180); 
    } 
  }
  else{
    noTone(buzzer);
    digitalWrite(ledPin, LOW);
    myservo.write(0);
  }
  
  
  Serial.print("Distance: ");
  Serial.println(distance);
}
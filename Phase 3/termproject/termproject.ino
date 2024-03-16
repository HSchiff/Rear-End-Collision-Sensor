#include <LiquidCrystal.h>
const int trigPin = 9;
const int echoPin = 10;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int buzzerPin = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int tailgating_distance = 6;
long duration;
int distance;
int distance2 = -1;
int i = 0;
int distance_diff = 0;
bool b_switch = true; // turn buzzer on and off

void warning(bool b_switch) {
  // print warning to lcd
  lcd.print("WARNING");
  // buzzer output
  if (b_switch) {
    for (int i = 0; i < 3; i++) {
      buzz();
      delay(200); // Adjust the delay between buzzes if needed
    }
  }
  
  // delay for five seconds
  delay(5000);
  // clear lcd
  lcd.clear();
}

void incoming(bool b_switch) {
  // print to lcd
  lcd.print("INCOMING CAR");
  // buzzer output
  if (b_switch) {
    for (int i = 0; i < 5; i++) {
      buzz();
      delay(100); // Adjust the delay between buzzes if needed
    }
  }
  // delay for five seconds that programs starts again
  delay(5000);
  // clear lcd
  lcd.clear();
}

void buzz() {
  // Generate a buzz by toggling the buzzer pin

  digitalWrite(buzzerPin, HIGH);
  delay(100); // Adjust the duration of the buzz if needed
  digitalWrite(buzzerPin, LOW);

}

void setup() {
  // put your setup code here, to run once:
  /*
  Setup buzzer
  List different outputs for buzzer
  Set up sensors
    Ultrasonic sensor -> distance
  */
  lcd.begin(16, 2);
  // lcd.print("Distance");

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;     // centimeters
  // Prints distance in Serial Monitor

  // checks if sensor bugs out
  if (distance > 100) {
    return;
  }

  Serial.print("Distance: ");
  Serial.println(distance);

  // figure out what units ultrasonic sensor does
  // figure out what sensors say when car 2 is non-existent
  // write test scripts

  distance_diff = distance2 - distance;

  // incoming fast
  // figure out top_speed that is too fast
  if (distance_diff > 7 && distance < 30) {
    incoming(b_switch);
  }

  // tailgating
  // measure tailgating distance
  if (distance < tailgating_distance) {
    warning(b_switch);
  }
  
  // update distance every 12 loops
  if (i % 12 == 0) {
        distance2 = distance;
  }

  i += 1;
  
}

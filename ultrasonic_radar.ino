#include <Servo.h>

Servo myServo;          // create servo object
int trigPin = 9;        // Trigger pin of Ultrasonic Sensor
int echoPin = 10;       // Echo pin of Ultrasonic Sensor
long duration;
int distance;

void setup() {
  myServo.attach(6);   // Servo connected to pin 6
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  for (int angle = 0; angle <= 180; angle++) {
    myServo.write(angle);
    delay(20);
    distance = getDistance();
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print("° | Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  for (int angle = 180; angle >= 0; angle--) {
    myServo.write(angle);
    delay(20);
    distance = getDistance();
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print("° | Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  int dist = duration * 0.034 / 2;
  return dist;
}

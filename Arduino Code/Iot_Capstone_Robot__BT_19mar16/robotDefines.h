 

const int power = 500;
const int adj = 1;

const int ledPin = 13;
const int buttonPin = 9;

#define RIGHT 1
#define LEFT -1

Servo leftServo;
Servo rightServo;
Servo searchServo;

int searchServoPosition;

// Ultrasonic Sensor

#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin

#define COLL_DIST 20 // collision distance 20cm
int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance


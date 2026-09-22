/*
  Ultrasonic Proximity Detection Prototype

  Components:
  - Arduino Uno
  - HC-SR04 Ultrasonic Distance Sensor
  - LED
  - 220 ohm resistor
  - Buzzer

  Function:
  The system measures the distance of an object.
  If the object is within 15 cm:
    - LED turns ON
    - Buzzer sounds

  Otherwise:
    - LED turns OFF
    - Buzzer remains OFF
*/

// -------------------------
// Pin definitions
// -------------------------

const int TRIG_PIN = 9;
const int ECHO_PIN = 10;

const int LED_PIN = 7;
const int BUZZER_PIN = 6;

// Distance threshold in centimetres
const float ALERT_DISTANCE = 15.0;


// -------------------------
// Setup
// -------------------------

void setup() {
  // Configure ultrasonic sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Configure alert outputs
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Start serial communication
  Serial.begin(9600);
}


// -------------------------
// Measure distance
// -------------------------

float measureDistance() {

  // Make sure TRIG starts LOW
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Send a 10-microsecond ultrasonic pulse
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the duration of the ECHO pulse
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Convert time into distance.
  // Speed of sound ≈ 0.0343 cm/microsecond.
  // Divide by 2 because the sound travels to the
  // object and then back.
  float distance = duration * 0.0343 / 2;

  return distance;
}


// -------------------------
// Control alert devices
// -------------------------

void activateAlert() {
  digitalWrite(LED_PIN, HIGH);
  digitalWrite(BUZZER_PIN, HIGH);
}


void deactivateAlert() {
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
}


// -------------------------
// Main program
// -------------------------

void loop() {

  // Get the current distance
  float distance = measureDistance();

  // Display distance in Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");


  // Check whether the object is within 15 cm
  if (distance <= ALERT_DISTANCE) {

    activateAlert();

    Serial.println("WARNING: Object detected within 15 cm!");

  } else {

    deactivateAlert();
  }


  // Small delay before the next measurement
  delay(100);
}
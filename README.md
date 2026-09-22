# SOAR-P1

**Ultrasonic Proximity Alarm**

An Arduino-based proximity alarm system built and simulated on Tinkercad Circuits. It uses an ultrasonic distance sensor to continuously measure the distance to nearby objects, and triggers a buzzer and LED alert whenever an object comes within 15 cm.

**How It Works**

The HC-SR04 ultrasonic sensor emits a sound pulse and measures the time it takes to bounce back off an object. This time is converted into a distance value (in cm). If the measured distance drops below the 15 cm threshold, the Arduino activates the buzzer and lights up the LED as a proximity warning. Once the object moves away, the alarm resets automatically.

**Components Used**


Component	Quantity
Arduino Uno	1
HC-SR04 Ultrasonic Distance Sensor	1
Buzzer	1
LED	1
Resistor (220Ω, for LED)	1
Breadboard	1
Jumper Wires	As needed

**Circuit Connections**


Component Pin-->	Arduino Pin
HC-SR04 VCC--->	5V
HC-SR04 GND-->	GND
HC-SR04 Trig-->	Digital Pin 9
HC-SR04 Echo-->	Digital Pin 10
Buzzer +ve-->	Digital Pin 8
Buzzer -ve-->	GND
LED Anode (via resistor)-->	Digital Pin 7
LED Cathode-->	GND

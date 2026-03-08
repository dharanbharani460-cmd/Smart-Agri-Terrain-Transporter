#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

int motorPin1 = 9;
int motorPin2 = 10;

int16_t ax, ay, az;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  Serial.println("Smart Agri-Terrain Transporter Started");
}

void loop() {

  mpu.getAcceleration(&ax, &ay, &az);

  Serial.print("Tilt Value: ");
  Serial.println(ay);

  // Check terrain slope
  if (ay > 10000) {
    // Uphill movement
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    Serial.println("Climbing Slope");
  }
  else {
    // Normal terrain
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    Serial.println("Normal Movement");
  }

  delay(500);
}

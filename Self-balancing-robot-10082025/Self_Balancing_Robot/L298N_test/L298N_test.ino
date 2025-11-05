// Define motor control pins
const int motor1_ena = 10;
const int motor1_in1 = 7;
const int motor1_in2 = 6;

const int motor2_enb = 11;
const int motor2_in3 = 5;
const int motor2_in4 = 4;

void setup() {
  // Set all motor control pins as outputs
  pinMode(motor1_ena, OUTPUT);
  pinMode(motor1_in1, OUTPUT);
  pinMode(motor1_in2, OUTPUT);

  pinMode(motor2_enb, OUTPUT);
  pinMode(motor2_in3, OUTPUT);
  pinMode(motor2_in4, OUTPUT);

  // Initialize Serial communication for debugging
  Serial.begin(9600);
  Serial.println("Motor test started!");
}

void loop() {
  // Test Motor 1
  Serial.println("Motor 1 forward");
  digitalWrite(motor1_in1, HIGH);
  digitalWrite(motor1_in2, LOW);
  analogWrite(motor1_ena, 200); // Set motor speed (0-255)
  delay(3000);

  Serial.println("Motor 1 stop");
  analogWrite(motor1_ena, 0); // Stop the motor
  delay(1000);

  Serial.println("Motor 1 reverse");
  digitalWrite(motor1_in1, LOW);
  digitalWrite(motor1_in2, HIGH);
  analogWrite(motor1_ena, 200);
  delay(3000);

  Serial.println("Motor 1 stop");
  analogWrite(motor1_ena, 0);
  delay(1000);

  // ---
  Serial.println("Motor 2 forward");
  digitalWrite(motor2_in3, HIGH);
  digitalWrite(motor2_in4, LOW);
  analogWrite(motor2_enb, 200);
  delay(3000);

  Serial.println("Motor 2 stop");
  analogWrite(motor2_enb, 0);
  delay(1000);

  Serial.println("Motor 2 reverse");
  digitalWrite(motor2_in3, LOW);
  digitalWrite(motor2_in4, HIGH);
  analogWrite(motor2_enb, 200);
  delay(3000);

  Serial.println("Motor 2 stop");
  analogWrite(motor2_enb, 0);
  delay(1000);

  Serial.println("Test cycle complete. Restarting in 5 seconds...");
  delay(5000);
}
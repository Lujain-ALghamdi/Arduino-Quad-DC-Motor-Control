// Motor control pins for the right side motors
const int IN1 = 9;
const int IN2 = 8;

// Motor control pins for the left side motors
const int IN3 = 11;
const int IN4 = 10;


void setup() {

  // Configure motor control pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

}


void loop() {

  // 1. Move forward for 30 seconds
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(30000); // Wait for 30 seconds


  // 2. Move backward for 60 seconds
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  delay(60000); // Wait for 60 seconds


  // 3. Turn right and left alternately for 60 seconds
  // Each direction lasts for 1 second and repeats 30 times

  for (int i = 0; i < 30; i++) {


    // Turn right
    // Right motors move backward while left motors move forward
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    delay(1000); // Wait for 1 second


    // Turn left
    // Right motors move forward while left motors move backward
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    delay(1000); // Wait for 1 second

  }


  // Stop all motors after completing the movement sequence
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);


  // Stop the program to prevent repeating the sequence
  while (true);

}
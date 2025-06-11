int ir1 = 2;
int ir2 = 3;

int ENA1 = 11;  // Enable pin for motor 1 (left)
int IN1 = 10;   // Direction pin for motor 1
int IN2 = 9;

int IN3 = 8;    // Direction pin for motor 2 (right)
int IN4 = 7;
int ENB = 12;   // Enable pin for motor 2

int dir_speed = 150;
int turn_speed = 50;
int stop_speed = 0;

void setup() {
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ENA1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int left_sens = digitalRead(ir1);
  int right_sens = digitalRead(ir2);

  Serial.print("left: ");
  Serial.println(left_sens);
  Serial.print("right: ");
  Serial.println(right_sens);

  // Stop all directions first (avoid mixed directions)
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  if (left_sens == 1 && right_sens == 1) {
    // Go forward
    analogWrite(ENA1, dir_speed);
    analogWrite(ENB, dir_speed);
    digitalWrite(IN1, HIGH);  // Motor1 forward
    digitalWrite(IN4, HIGH);  // Motor2 forward
  }
  else if (left_sens == 1 && right_sens == 0) {
    // Turn right
    analogWrite(ENA1, turn_speed);
    analogWrite(ENB, turn_speed);
    digitalWrite(IN2, HIGH);  // Motor1 backward
    digitalWrite(IN4, HIGH);  // Motor2 forward
  }
  else if (left_sens == 0 && right_sens == 1) {
    // Turn left
    analogWrite(ENA1, turn_speed);
    analogWrite(ENB, turn_speed);
    digitalWrite(IN1, HIGH);  // Motor1 forward
    digitalWrite(IN3, HIGH);  // Motor2 backward
  }
  else {
    // Stop
    analogWrite(ENA1, stop_speed);
    analogWrite(ENB, stop_speed);
  }

  delay(100);  // small delay for stability
}

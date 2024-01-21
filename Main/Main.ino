#include <string.h>

int motor_R1_pin_1 = 2;
int motor_R1_pin_2 = 3;

int motor_R2_pin_1 = 8;
int motor_R2_pin_2 = 9;

int motor_L1_pin_1 = 4;
int motor_L1_pin_2 = 5;

int motor_L2_pin_1 = 6;
int motor_L2_pin_2 = 7;
int current;


String inputted;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(31250);
  pinMode(motor_R1_pin_1, OUTPUT);
  pinMode(motor_R1_pin_2, OUTPUT);
  pinMode(motor_R2_pin_1, OUTPUT);
  pinMode(motor_R2_pin_2, OUTPUT);

  pinMode(motor_L1_pin_1, OUTPUT);
  pinMode(motor_L1_pin_2, OUTPUT);
  pinMode(motor_L2_pin_1, OUTPUT);
  pinMode(motor_L2_pin_2, OUTPUT);
}

//RIGHT is 2, LEFT is 1
void turn(int which) {
  if (which == 1) {
     digitalWrite(motor_R1_pin_1, HIGH);
     digitalWrite(motor_R2_pin_1, HIGH);
     digitalWrite(motor_L1_pin_2, HIGH);
     digitalWrite(motor_L2_pin_2, HIGH);
     
     digitalWrite(motor_R1_pin_2, LOW);
     digitalWrite(motor_R2_pin_2, LOW);
     digitalWrite(motor_L1_pin_1, LOW);
     digitalWrite(motor_L2_pin_1, LOW);
  }
  if (which == 2) {
     digitalWrite(motor_R1_pin_2, HIGH);
     digitalWrite(motor_R2_pin_2, HIGH);
     digitalWrite(motor_L1_pin_1, HIGH);
     digitalWrite(motor_L2_pin_1, HIGH);

     digitalWrite(motor_R1_pin_1, LOW);
     digitalWrite(motor_R2_pin_1, LOW);
     digitalWrite(motor_L1_pin_2, LOW);
     digitalWrite(motor_L2_pin_2, LOW);
  }
}

void move(int which) {
  if (which == 1) {
     digitalWrite(motor_R1_pin_1, HIGH);
     digitalWrite(motor_R2_pin_1, HIGH);
     digitalWrite(motor_L1_pin_1, HIGH);
     digitalWrite(motor_L2_pin_1, HIGH);

     digitalWrite(motor_R1_pin_2, LOW);
     digitalWrite(motor_R2_pin_2, LOW);
     digitalWrite(motor_L1_pin_2, LOW);
     digitalWrite(motor_L2_pin_2, LOW);
  }
  if (which == 2) {
     digitalWrite(motor_R1_pin_2, HIGH);
     digitalWrite(motor_R2_pin_2, HIGH);
     digitalWrite(motor_L1_pin_2, HIGH);
     digitalWrite(motor_L2_pin_2, HIGH);

     digitalWrite(motor_R1_pin_1, LOW);
     digitalWrite(motor_R2_pin_1, LOW);
     digitalWrite(motor_L1_pin_1, LOW);
     digitalWrite(motor_L2_pin_1, LOW);
  }
}

void stop() {
  current = 0;
      digitalWrite(motor_R1_pin_1, LOW);
      digitalWrite(motor_R2_pin_1, LOW);
      digitalWrite(motor_L1_pin_1, LOW);
      digitalWrite(motor_L2_pin_1, LOW);
      digitalWrite(motor_R1_pin_2, LOW);
      digitalWrite(motor_R2_pin_2, LOW);
      digitalWrite(motor_L1_pin_2, LOW);
      digitalWrite(motor_L2_pin_2, LOW);
}
// the loop function runs over and over again forever
void loop() {

  
  if (Serial.available()) {
    inputted = Serial.readString();
    Serial.println(String(inputted));

    if (String(inputted) == "1") {
      turn(1);
      current = 1;
      Serial.println(String("GO"));
      Serial.println((inputted == 52));
    }
    if (String(inputted) == "2") {
      turn(2);
      current = 2;
    }
    if (String(inputted) == "3") {
      move(1);
      current = 3;
      Serial.write("go\n");
    }
    if (String(inputted) == "4") {
      move(2);
      current = 4;
    }
    if (String(inputted) == "5") {
      current = 0;
      digitalWrite(motor_R1_pin_1, LOW);
      digitalWrite(motor_R2_pin_1, LOW);
      digitalWrite(motor_L1_pin_1, LOW);
      digitalWrite(motor_L2_pin_1, LOW);
      digitalWrite(motor_R1_pin_2, LOW);
      digitalWrite(motor_R2_pin_2, LOW);
      digitalWrite(motor_L1_pin_2, LOW);
      digitalWrite(motor_L2_pin_2, LOW);

    }
    if (String(inputted) == "7") {
      current = 0;
      turn(2);
      delay(500);
      stop();
    }
    if (String(inputted) == "6") {
      current = 0;
      turn(1);
      delay(500);
      stop();
    }
    if (String(inputted) == "8") {
      current = 0;
      move(1);
      delay(500);
      stop();
    }
    if (String(inputted) == "9") {
      current = 0;
      move(2);
      delay(500);
      stop();
    }
  } else {
    switch (current) {
        case 1:
          turn(1);
          break;
        case 2:
          turn(2);
          break;
        case 3:
          move(1);
          break;
        case 4:
          move(2);
          break;
      }
  }
}




const int A1A = 2;//define pin 2 for A1A
const int A1B = 3;//define pin 3 for A1B

const int B1A = 4;//define pin 8 for B1A
const int B1B = 5;//define pin 9 for B1B

int motor_speed1 = 0;
int motor_speed2 = 0;

// Define Joystick Connections
#define joyX A0
#define joyY A1

int joyposX = 512;
int joyposY = 512;


void setup() {

  pinMode(B1A, OUTPUT); // define pin as output
  pinMode(B1B, OUTPUT);
  pinMode(A1A, OUTPUT);
  pinMode(A1B, OUTPUT);
  digitalWrite(B1A, LOW);
  digitalWrite(B1B, LOW);
  digitalWrite(A1A, LOW);
  digitalWrite(A1B, LOW);

  //Initializng the joystick pins as input
  //pinMode (x_key, INPUT) ;
  //pinMode (y_key, INPUT) ;

  delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:

  joyposX = analogRead(joyX);
  joyposY = analogRead(joyY);

  //Serial.print("X : ");
  //Serial.println(joyposX);
  //Serial.print("Y : ");
  //Serial.println(joyposY);
  //Serial.print("potValue : ");
  //Serial.println(data.potValue);
  delay(10);

  if (joyposX > 510)
  {

    // This is BACWARD
    motor_speed1 = map(joyposX, 1023, 510, 0, 255);
    motor_speed2 = map(joyposX, 1023, 510, 0, 255);
    digitalWrite(A1A, HIGH);
    analogWrite(A1B, motor_speed1);
    digitalWrite(B1A, HIGH);
    analogWrite(B1B, motor_speed2);


  }

  else if (joyposX < 480)
  {

    // This is FORWARD
    motor_speed1 = map(joyposX, 480, 0, 0, 255);
    motor_speed2 = map(joyposX, 480, 0, 0, 255);
    digitalWrite(A1A, LOW);
    analogWrite(A1B, motor_speed1);
    digitalWrite(B1A, LOW);
    analogWrite(B1B, motor_speed2);

  }

  else if (joyposY < 480)
  {
    // This is right
    motor_speed1 = map(joyposY, 480, 0, 0, 255);
    motor_speed2 = map(joyposY, 480, 0, 0, 255);
    digitalWrite(A1A, LOW);
    analogWrite(A1B, motor_speed1);
    digitalWrite(B1A, HIGH);
    analogWrite(B1B, 255 - motor_speed2);

  }

  else if (joyposY > 520)
  {

    // This is right
    motor_speed1 = map(joyposY, 520, 1023, 0, 255);
    motor_speed2 = map(joyposY, 520, 1023, 0, 255);
    digitalWrite(A1A, HIGH);
    analogWrite(A1B, 255 - motor_speed1);
    digitalWrite(B1A, LOW);
    analogWrite(B1B, motor_speed2);

  }

  else
  {
    digitalWrite(B1A, LOW);
    digitalWrite(B1B, LOW);
    digitalWrite(A1A, LOW);
    digitalWrite(A1B, LOW);

  }

}

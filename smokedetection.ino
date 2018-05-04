
int smokeSensitivity = 350;
int redLight = 1;
int greenLight = 2;
int mq2Port = 0;

bool debug = true;


void setup() {
  Serial.begin(9600);
  pinMode(redLight, OUTPUT);
  pinMode(greenLight, OUTPUT);
  pinMode(mq2Port, INPUT);
}

void loop() {
  int analogSensor = analogRead(mq2Port);

  Serial.print("MQ2 on Pin 0: ");
  Serial.println(analogSensor);
  if (analogSensor > smokeSensitivity)  {
    digitalWrite(redLight, HIGH);
    digitalWrite(greenLight, LOW);
    if (debug) {
      Serial.print("Gas/Fire detected");
      Serial.print(" ");
      Serial.print(analogSensor);
      Serial.print(" ");
      Serial.println(); 
    }

  }
  else  {
    digitalWrite(redLight, LOW);
    digitalWrite(greenLight, HIGH);
    if (debug) {
      Serial.print("NO Gas/Fire");
      Serial.print(" ");
      Serial.print(analogSensor);
      Serial.print(" ");
      Serial.println();
    }
  }
  delay(100);
}


Servo vesc;
SYSTEM_THREAD(ENABLED);

int vescPin = D0;
int buttonPin = A0;

void setup() {
  Serial.begin(9600);
  vesc.attach(vescPin);
  pinMode(buttonPin, INPUT_PULLUP);
}


int val = 1000;

int base = 1000;

int maxVal = 1500;

int holdCount = 0;

int holdMax = 500;

void loop() {
  if (!digitalRead(buttonPin)) {
    if (val < maxVal) {
      val += 20;
    }
    if (holdCount < holdMax) {
      holdCount++;
    } else {
      val = 2000;
      Serial.println("max value");
    }
  } else {
    holdCount = 0;
    val = 1000;
  }
  Serial.println(val);
  vesc.writeMicroseconds(val);
  delayMicroseconds(5000);
}
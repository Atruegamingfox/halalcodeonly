const int buttonPin = 4;
const int ledRed = 16;
const int ledBlue = 17;
const int ledGreen = 5;

unsigned long startTime;
unsigned long reactionTime;

void setup() {
  pinMode(ledRed, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(115200);
  delay(1000);
  Serial.println("--- ESP32 REACTION GAME ---");
  Serial.println("Press the button to START!");
}

void loop() {

  while (digitalRead(buttonPin) == HIGH);
  delay(400);

  Serial.println("Get ready...");
  digitalWrite(ledRed, HIGH);
  delay(1000);

  digitalWrite(ledBlue, HIGH);

  delay(random(1500, 4000));

  digitalWrite(ledGreen, HIGH);
  startTime = millis();

  while (digitalRead(buttonPin) == HIGH);
  reactionTime = millis() - startTime;

  digitalWrite(ledRed, LOW);
  digitalWrite(ledBlue, LOW);
  digitalWrite(ledGreen, LOW);

  Serial.print("Your Time: ");
  Serial.print(reactionTime);
  Serial.println(" ms");

  if (reactionTime < 250) Serial.println("Lightning Fast!");
  else if (reactionTime < 450) Serial.println("Good job!");
  else Serial.println("Too slow!");

  delay(3000);
  Serial.println("\nPress button to play again!");
}

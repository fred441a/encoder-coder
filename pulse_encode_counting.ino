#define W1 11
#define W2 12

int cnt = 0;
long Time = 0 ;
void setup() {
  Serial.begin(9600);
  pinMode(W1, INPUT_PULLUP);
  pinMode(W2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(W1), Count, RISING);
}
void Count() {
  if (digitalRead(W2) == HIGH)
    cnt++;
  else
    cnt--;

}
void loop() {
  if (Time == 0) {
    Time = millis();
  }
  if (millis() - Time >= 1000) {
    Time = millis();
    Serial.println(cnt);
  }



}

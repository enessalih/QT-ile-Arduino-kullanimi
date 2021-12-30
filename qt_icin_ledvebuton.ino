int butonPin = 4;
int butonundegeri = 0;
int led_Pin=7;
int val = 0;

void setup() {
  pinMode(butonPin, INPUT);
  pinMode(led_Pin, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  butonundegeri = digitalRead(butonPin);
  Serial.println(butonundegeri);
  delay(100);
  
}
void serialEvent() {
  
  if (Serial.available()) {
    val= Serial.parseInt();
    
    if (val == 2) {
      digitalWrite(led_Pin, HIGH);
      }
    if (val == 3) {
      digitalWrite(led_Pin, LOW);
      }
    }  
  }

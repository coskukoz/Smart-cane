int mz80 = 6;
int mzdeger = 0;

void setup() {
   pinMode(mz80, INPUT);
   Serial.begin(9600);
}

void loop() {
  mzdeger = digitalRead(mz80);
  if(mzdeger == 0) {
    Serial.println(1);
    
    }
  else{
    Serial.println(0);
    
    }
    delay(500);
}

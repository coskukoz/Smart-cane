// Watch video here: https://www.youtube.com/watch?v=BERHEVgaX40

/*
// TCS230 color recognition sensor 
// Sensor connection pins to Arduino are shown in comments

Color Sensor      Arduino
-----------      --------
 VCC               5V
 GND               GND
 s0                8
 s1                9
 s2                12
 s3                11
 OUT               10
 OE                GND
*/
const int s0 = 8;  
const int s1 = 9;  
const int s2 = 12;  
const int s3 = 11;  
const int out = 10;
// Variables  
int sari = 0;  
int yesil = 0;  
int mavi = 0;  
//Buzzer kısmı pin 7
const int buzzer = 7; //buzzer to arduino pin 7
//mz80 pin 6
int mz80 = 6;
int mzdeger = 0;
int buton1 = 2; //renk sensoru butonu
int button1;
    
void setup()   
{  
  Serial.begin(9600); 
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);
  pinMode(buton1, INPUT);
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH);  
  //buzzer
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 7 as an output
  //mz80
  pinMode(mz80, INPUT);
}  
    
    
void loop() 
{  
  color(); 
  Serial.print("R Intensity:");  
  Serial.print(sari, DEC);  
  Serial.print(" G Intensity: ");  
  Serial.print(yesil, DEC);  
  Serial.print(" B Intensity : ");  
  Serial.print(mavi, DEC);  
  //Serial.println();
  button1 = digitalRead(buton1);
  mzdeger = digitalRead(mz80);
  
  if(mzdeger == 0)
  {
    Serial.println("(Engel Var)");
    tone(buzzer, 1000); // Send 1KHz sound signal...
    delay(200);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...
    delay(200);        // ...for 1sec
    
  }
  else 
   Serial.println("(Engel Yok)");

{
      if (button1 == LOW)
      {
  if (sari < mavi && sari < yesil && sari < 20)
  {

   Serial.println(" - (Sari Renk)");
   digitalWrite(7, HIGH);   // turn the buzzer on (HIGH is the voltage level)
   delay(1000);              // wait for a second
   digitalWrite(7, LOW);    // turn the buzzer off by making the voltage LOW
   delay(1000);              
  }  

  else  
  {  
   
   tone(buzzer, 100); // Send 1KHz sound signal...
   delay(600);        // ...for 1 sec
   noTone(buzzer);     // Stop sound...
   delay(600);        // ...for 1sec
  }  
}
}
 }  

    
void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  //count OUT, pRed, RED  
  sari = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE  
  mavi = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  //count OUT, pGreen, GREEN  
  yesil = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}


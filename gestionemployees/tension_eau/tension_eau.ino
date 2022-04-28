#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd (0x27,20,4); 
int red=2 ; 
int green=4 ; 
int buz=6; 
int d;

void setup() { 
    pinMode(red,OUTPUT); 
  pinMode(green,OUTPUT); 
  pinMode(buz,OUTPUT); 
  lcd.init();                     
  lcd.init();
  lcd.backlight();
  Serial.begin(9600) ; 

}

void loop() {
 
  int valeur = analogRead(A0);  
  float tension = (float) 5*valeur /1023 ; 
  
  Serial.print(tension) ;
  //Serial.print(',');  
  if ( tension<2.35 ) { 
  /*  noTone(buz); 
    digitalWrite(green,HIGH); 
    digitalWrite(red,LOW); 
  lcd.init();
  lcd.setCursor(1,0);
  lcd.print("niveau bas"); */
  Serial.write('0');  
  delay(500) ;
  } 
  else if (tension >= 2.30 and tension <2.90 ) 
  {  
    noTone(buz); 
    digitalWrite(green,HIGH); 
    digitalWrite(red,LOW);
    lcd.init();
  lcd.setCursor(1,0);
  lcd.print("niveau moyen"); 
  Serial.write('1');
  
  delay(500) ;
  } 
  else if (tension >3.05)  {  
    //serial.
    Serial.write('1');
    if(Serial.available())
  {
    d=Serial.read();
    if(d){  digitalWrite(green,LOW); 
    digitalWrite(red,HIGH); 
    tone(buz,1000); 
    }
    }
  
    lcd.init();
  lcd.setCursor(1,0);
  lcd.print("  niveau haut ");  
  Serial.write('2');
  delay(500) ;
  } 
} 

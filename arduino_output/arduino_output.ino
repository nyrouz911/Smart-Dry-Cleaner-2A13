//#define motor 11 
#define PIN_LED2 13
char data;

void setup()
{
//pinMode(motor,OUTPUT);
Serial.begin(9600);
digitalWrite(PIN_LED2,LOW);
 pinMode(PIN_LED2,OUTPUT);
}

void loop() {
  if (Serial.available())
  {     
   
     data=Serial.read();  
     
     if(data=='1') 
    {
      digitalWrite(PIN_LED2,HIGH); // alumer la lampe 
      //Serial.write('1'); 
     }  
     /*else  

     //{
        
       // Serial.write('0'); 
     
     }*/   
     
  }

}

#define vent 2
char data;

void setup()
{
pinMode(vent,OUTPUT);
Serial.begin(9600);
}

void loop() {
  if (Serial.available())
  {     
   
     data=Serial.read();  
     
     if(data=='1') 
    {
      digitalWrite(vent, HIGH);  
    //delay(2000);
     
    //delay(3000);   
    }  
    else
    {
      digitalWrite(2, LOW); 
    }
     
     
  }

}

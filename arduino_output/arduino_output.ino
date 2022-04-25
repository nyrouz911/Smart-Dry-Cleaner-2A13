int capteur =0;
char data;
#define vent 2

void setup()
{

  Serial.begin(9600);
  pinMode(4,OUTPUT);//LED VERTE
  pinMode(8,OUTPUT);//LED ROUGE
  
}

void loop()
{
  
  int valcapt = analogRead(capteur);
  float voltage = valcapt*5.0/1024.0;//transformation des  tension en temperature
  float temperature = (voltage - 0.5)*100;
  //Serial.print(temperature);
  //Serial.println(" C ");
  delay(2000);

  if (temperature > 50)
  {
    digitalWrite(4,LOW);//VERTE ETEINTE
    digitalWrite(8,HIGH);// ROUGE ALLUMEE
    Serial.write('1');
    }
    else
    {
       digitalWrite(4,HIGH);//VERTE active
    digitalWrite(8,LOW);// ROUGE off
    Serial.write('0');
    }

    //output
    data=Serial.read();
    if(data=='1')
    {
    digitalWrite(vent, HIGH);  
    }
    else
    {
    digitalWrite(vent, LOW);  
    }
    }
  
  

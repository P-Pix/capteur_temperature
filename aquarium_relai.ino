int capt1=0;
int capt2=1;
int capt3=2;
int capt4=3;
int valeurcapt1;
int valeurcapt2;
int valeurcapt3;
int valeurcapt4;

void setup()
{
  Serial.begin(9600);
  pinMode(4,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
}

void loop()
{
  capt1=analogRead(A0);
  capt2=analogRead(A1);
  capt3=analogRead(A2);
  capt4=analogRead(A3);
  valeurcapt1=(-0.0891905268*capt1+75.8156132303);
  Serial.print("Capteur A0 = ");
  Serial.print(valeurcapt1);
  Serial.println("°C");
  valeurcapt2=(-0.0947098208*capt2+80.2441031952);
  Serial.print("Capteur A1 = ");
  Serial.print(valeurcapt2);
  Serial.println("°C");
  valeurcapt3=(-0.0949084193*capt3+81.0223481607);
  Serial.print("Capteur A2 = ");
  Serial.print(valeurcapt3);
  Serial.println("°C");
  valeurcapt4=(-0.0928922522*capt4+79.7268432406);
  Serial.print("Capteur A3 = ");
  Serial.print(valeurcapt4);
  Serial.println("°C");
  Serial.println(" ");
  
  if (valeurcapt1 > 26 && valeurcapt2 > 26)
  {
    digitalWrite(4,LOW); 
  }
  else
  {
    if (valeurcapt1 < 23 && valeurcapt2 <23)
    {
      digitalWrite(4,HIGH);
    }
    else
    {
      
    }
  }
  if (valeurcapt2 > 26 && valeurcapt3 > 26)
  {
    digitalWrite(2,LOW); 
  }
  else
  {
    if (valeurcapt2 < 23 && valeurcapt3 <23)
    {
      digitalWrite(2,HIGH);
    }
    else
    {
      
    }
  }
  if (valeurcapt3 > 26 && valeurcapt4 > 26)
  {
    digitalWrite(3,LOW); 
  }
  else
  {
    if (valeurcapt3 < 23 && valeurcapt4 <23)
    {
      digitalWrite(3,HIGH);
    }
    else
    {
      
    }
  }
  delay(1000);
}

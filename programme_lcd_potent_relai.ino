#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int capt1 = 0;
int capt2 = 1;
int capt3 = 2;
int capt4 = 3;
int poten = 4;
int valeurcapt1;
int valeurcapt2;
int valeurcapt3;
int valeurcapt4;
int Tchoisie;
int valeurpoten;
int Tchoisiemax;
int Tchoisiemin;
LiquidCrystal_I2C lcd(0x27, 20, 5);

void setup()
{
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  lcd.init();
}

void loop()
{
  capt1 = analogRead(A0);
  capt2 = analogRead(A1);
  capt3 = analogRead(A2);
  capt4 = analogRead(A3);
  valeurpoten = analogRead(A4);
  Tchoisie = (valeurpoten / 20);
  Tchoisiemax = (Tchoisie + 1);
  Tchoisiemin = (Tchoisie - 1);
  Serial.print("Température choisie = ");
  Serial.print(Tchoisie);
  Serial.println("°C");
  Serial.println(" ");
  valeurcapt1 = (-0.0891905268 * capt1 + 75.8156132303);
  Serial.print("Capteur A0 = ");
  Serial.print(valeurcapt1);
  Serial.println("°C");
  valeurcapt2 = (-0.0947098208 * capt2 + 80.2441031952);
  Serial.print("Capteur A1 = ");
  Serial.print(valeurcapt2);
  Serial.println("°C");
  valeurcapt3 = (-0.0949084193 * capt3 + 81.0223481607);
  Serial.print("Capteur A2 = ");
  Serial.print(valeurcapt3);
  Serial.println("°C");
  valeurcapt4 = (-0.0928922522 * capt4 + 79.7268432406);
  Serial.print("Capteur A3 = ");
  Serial.print(valeurcapt4);
  Serial.println("°C");
  Serial.println(" ");
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("T° choisie =");
  lcd.setCursor(0, 1);
  lcd.print(Tchoisie);
  
  if(valeurcapt1 > Tchoisiemax && valeurcapt2 > Tchoisiemax)
  {
    digitalWrite(4,LOW); 
  }
  else
  {
    if(valeurcapt1 < Tchoisiemin && valeurcapt2 < Tchoisiemin)
    {
      digitalWrite(4, HIGH);
    }
    else
    {
      
    }
  }
  if(valeurcapt2 > Tchoisiemax && valeurcapt3 > Tchoisiemax)
  {
    digitalWrite(2, LOW); 
  }
  else
  {
    if(valeurcapt2 < Tchoisiemin && valeurcapt3 < Tchoisiemin)
    {
      digitalWrite(2, HIGH);
    }
    else
    {
      
    }
  }
  if(valeurcapt3 > Tchoisiemax && valeurcapt4 > Tchoisiemax)
  {
    digitalWrite(3, LOW); 
  }
  else
  {
    if(valeurcapt3 < Tchoisiemin && valeurcapt4 < Tchoisiemin)
    {
      digitalWrite(3, HIGH);
    }
    else
    {
      
    }
  }
  delay(1000);
}


const int f1=A1;
const int f2=A2;
const int f3=A3;
const int f4=A4;
const int f5=A5;

const int led_1=3;
const int led_2=5;
const int led_3=6;
const int led_4=9;
const int led_5=10;


void setup()
{
  pinMode(f1,INPUT);
  pinMode(f2,INPUT);
  pinMode(f3,INPUT);
  pinMode(f4,INPUT);
  pinMode(f5,INPUT);

  pinMode(led_1,OUTPUT);
  pinMode(led_2,OUTPUT);
  pinMode(led_3,OUTPUT);
  pinMode(led_4,OUTPUT);
  pinMode(led_5,OUTPUT);

}

void loop()
{
    if(analogRead(f1)>700)
        digitalWrite(led_1,HIGH);
    else
        digitalWrite(led_1,LOW);


    if(analogRead(f2)>700)
        digitalWrite(led_2,HIGH);
    else
        digitalWrite(led_2,LOW);


    if(analogRead(f3)>700)
        digitalWrite(led_3,HIGH);
    else
        digitalWrite(led_3,LOW);


    if(analogRead(f4)>700)
        digitalWrite(led_4,HIGH);
    else
        digitalWrite(led_4,LOW);


    if(analogRead(f5)>700)
        digitalWrite(led_5,HIGH);
    else
        digitalWrite(led_5,LOW);


}

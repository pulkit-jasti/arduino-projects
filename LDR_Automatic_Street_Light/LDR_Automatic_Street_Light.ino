
const int ldr_pin=A1;
const int led=13;

void setup()
{
    pinMode(ldr_pin,INPUT);
    pinMode(led,OUTPUT);
}

void loop() 
{
    int val=analogRead(ldr_pin);

    val=constrain(val,700,900);
    int brightness=map(val,700,900,255,0);

    analogWrite(led,brightness);

}

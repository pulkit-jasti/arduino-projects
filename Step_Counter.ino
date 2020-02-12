//Resources
//https://roboticadiy.com/how-to-make-your-own-pedometer-with-arduino/
//https://www.youtube.com/watch?v=vTz6oJrhqpM




#include <SoftwareSerial.h>
SoftwareSerial MySerial(10, 11); // pin 10 connects to TX of HC-05 | pin 11 connects to RX of HC-05
int x,y;
int count =0;
float calories;
float distance;
void setup() {
MySerial.begin(9600); 
}

void loop() {
x = analogRead(A0);
y = analogRead(A1);
if ( x <= 450 && y>=390)
{ count++;
//MySerial.print(count);
delay(200);
}
if ( x >= 460 && y<=370)
{
count++;
// MySerial.print(count);
delay(200);
}
calories = count * 0.035; // This value is taken depending upon my weight and height.
distance = count * 0.0006; // My step it is on average 60cm. 
MySerial.print(x);
MySerial.print(",");
MySerial.print(y);
MySerial.print(",");
MySerial.print(count);
MySerial.print(",");
MySerial.print(calories);
MySerial.print(",");
MySerial.print(distance);
MySerial.print(";");
delay(150); 
}

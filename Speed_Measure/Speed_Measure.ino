int trig_1= 6; 
int echo_1= 7; 
long lecture_echo_1; 
long dist_1;
long time_1;
int stat_1=0;

int trig_2= 12; 
int echo_2= 11; 
long lecture_echo_2; 
long dist_2;
long time_2;
int stat_2=0;

long time=0;
long speed=0;

int dist=1 //this is the distance between the two ultrasonic sensors in meters

  
void setup() 
{ 
      pinMode(trig_1, OUTPUT); 
      digitalWrite(trig_1, LOW); 
      pinMode(echo_1, INPUT); 
      
      pinMode(trig_2, OUTPUT); 
      digitalWrite(trig_2, LOW); 
      pinMode(echo_2, INPUT);
      
      Serial.begin(9600); 
}



void loop() 
{ 
      digitalWrite(trig_1, HIGH); 
      delayMicroseconds(10); 
      digitalWrite(trig_1, LOW); 
      lecture_echo_1= pulseIn(echo_1, HIGH); 
      dist_1 = lecture_echo_1/ 58; 
    
      
      digitalWrite(trig_2, HIGH); 
      delayMicroseconds(10); 
      digitalWrite(trig_2, LOW); 
      lecture_echo_2= pulseIn(echo_2, HIGH); 
      dist_2 = lecture_echo_2/ 58; 
    
      
      if(dist_1<70)
      {
          time_1=millis();
          stat_1=1;
      }
      
      if(dist_2<70)
      {
          time_2=millis();
          stat_2=1;
      }
      
      time=time_2 - time_1;
      time=time/1000;
      
      speed=dist/time;
      
      
      if(stat_1==1&&stat_2==1)
      {
          Serial.println("Speed is: ");
          Serial.print(speed);
          Serial.print(" m/s");
      else
      {
          Serial.print("Distance 1: "); 
          Serial.println(dist_1); 
          Serial.print("Distance 2:");
          Serial.println(dist_2);
          delay(100);
      }
}

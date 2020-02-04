int trig = 6; 
int echo = 7; 
int count=0;
long lecture_echo; 
long cm;
int status=0;
int down=0;


void setup() 
{ 
  pinMode(trig, OUTPUT); 
  digitalWrite(trig, LOW); 
  pinMode(echo, INPUT); 
  Serial.begin(9600); 
}
void loop() 
{ 
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trig, LOW); 
  lecture_echo = pulseIn(echo, HIGH); 
  cm = lecture_echo / 58; 
  
  
  if(down==1)
    count++;
  
  if(cm<70&&status==1)
    down=1;
  else
    down=0;
  
  if(cm>70)
    status=1;
  else
    status=0;
 
  
  Serial.print("Distance in cm : "); 
  Serial.println(count); 
  delay(100); 
}

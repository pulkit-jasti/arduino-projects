int trig = 4; 
int echo = 3; 
int count=0;
long lecture_echo; 
long dist;
int status=0;
int people=0;


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
  dist = lecture_echo / 58; 
  
  
  if(people==1)
    count++;
  
  if(dist<50&&status==1)
  {
    people=1;
  }
  else
  {
    people=0;
  }
  
  if(dist>50)
  {
    status=1;
  }
  else
  {
    status=0;
  }
 
  
  Serial.print("Number of People: "); 
  Serial.println(count); 
  delay(100); 
}

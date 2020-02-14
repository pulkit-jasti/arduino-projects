int trig_front= 6; 
int echo_front= 7; 
long lecture_echo_front; 
long dist_front=0;
int led_front=13;

int trig_left= 5; 
int echo_left= 4; 
long lecture_echo_left; 
long dist_left=0;
int led_left=12;

int trig_back= 3; 
int echo_back= 2; 
long lecture_echo_back; 
long dist_back=0;
int led_back=11;


void setup() 
{ 
  pinMode(trig_front, OUTPUT); 
  digitalWrite(trig_front, LOW); 
  pinMode(echo_front, INPUT); 
  
  pinMode(trig_left, OUTPUT); 
  digitalWrite(trig_left, LOW); 
  pinMode(echo_left, INPUT); 

  pinMode(trig_back, OUTPUT); 
  digitalWrite(trig_back, LOW); 
  pinMode(echo_back, INPUT); 

  
  Serial.begin(9600); 
}
void loop() 
{ 
  digitalWrite(trig_front, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trig_front, LOW); 
  lecture_echo_front = pulseIn(echo_front, HIGH); 
  dist_front = lecture_echo_front / 58; 
  

  digitalWrite(trig_left, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trig_left, LOW); 
  lecture_echo_left = pulseIn(echo_left, HIGH); 
  dist_left = lecture_echo_left / 58; 

  
  digitalWrite(trig_back, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trig_back, LOW); 
  lecture_echo_back = pulseIn(echo_back, HIGH); 
  dist_back = lecture_echo_back / 58; 

  
  if(dist_front<70)
    led_front=HIGH;
  
  if(dist_left<70)
    led_left=HIGH;
  
  if(dist_back<70)
    led_back=HIGH;
    
  

  delay(50); 
}

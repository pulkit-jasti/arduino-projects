#define trigPin 13
#define echoPin 12
#define delayMilis 100

/* 0: Noisy state.
 * 1: You went below the low threshold.
 * 2: You went above the low threshold.
 * 3: You went above the high threshold.
 * 4: You went below the high threshold, pushup done.
 */

int state;
unsigned long nr_cycles;
long nr_pushups;

#define LOW_THRESH 12
#define HIGH_THRESH 25
#define CYCLE_THRESH ((1000 / delayMilis) * 4)

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  state = 0;
  nr_cycles = 0;
  nr_pushups = 0;
}

void loop()
{
  float duration;
  float distance;
  
  /* Talk to the sonar device. */
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  
  /* Report back the measured distance. */
  /*
  Serial.println("Distance:");
  Serial.println(distance);
  */
  Serial.println("State:");
  Serial.println(state);
  
  /* Jump into a pushup state machine. */
  int new_state = state;
  
  if (distance < LOW_THRESH && state == 0) {
    new_state = 1;
  } else if (distance > LOW_THRESH && distance < HIGH_THRESH && state == 1) {
    new_state = 2;
  } else if (distance > HIGH_THRESH && state == 2) {
    new_state = 3;
  } else if (distance > LOW_THRESH && distance < HIGH_THRESH && state == 3) {
    new_state = 4;
  }
  
  if (new_state == state) {
    ++nr_cycles;
  } else if (new_state == 4) {
    state = 0;
    nr_cycles = 0;
    ++nr_pushups;
    Serial.println("Registered pushup!");
    Serial.println(nr_pushups);
    Serial.println(" ");
  } else {
    state = new_state;
  }
  
  if (nr_cycles > CYCLE_THRESH) {
    state = 0;
    nr_cycles = 0;
  }
  
  delay(delayMilis);
}

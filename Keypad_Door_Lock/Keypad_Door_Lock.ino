//KEYPAD SETUP STARTS HERE
//this part of the code will require no change
#include <Keypad.h>

const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};


// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = { 9, 8, 7, 6 };

// Connect keypad COL0, COL1, COL2 and COL3 to these Arduino pins.
byte colPins[COLS] = { 5, 4, 3, 2 }; 

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

//KEYPAD SETUP ENDS HERE


char passcode[]={'1','5','9','3'}; //This is the main passcode. Every time you want to change passcode, you'll have to change this array
int digits=4; //this variable represents the number of digits of the passcode, so if you change the passcode, do check the number of digits too
int time=3; //this variable represents the number of seconds for which the door will remain unlocked if the correct passcode is entered. After this time, the door will automatically be locked

void setup()
{
  Serial.begin(9600);
}
int y=0;

void loop()
{
  int u=0,flag=0;
  char key;
  int status=0;
  
  
  Serial.println("\n\nEnter the Passcode");
  while(y==0)
  {
      key=kpd.getKey();
      if(key) 
  	  {
        if(key!=passcode[u])
        {flag=1;}
        
    	Serial.println(key);
        u++;
  	  }
      
      if(u==digits)
        break;
   }
  
  if(flag==1)
  {
    Serial.println("Wrong Answer");    
  }
  else
  {
    Serial.println("\nCorrect Passcode.......Door Unlocked\n\n");
    status=1; //use the status variable to control a relay or any other device that will require a passcode
    delay(time*1000);
    status=0;
    Serial.println("Door Locked!");
  }
  
  
//the serial print statements are only to guide and will only be displayed on the serial monitor in the computer
//end
}

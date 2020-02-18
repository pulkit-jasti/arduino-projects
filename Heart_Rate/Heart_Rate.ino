//Resources
//https://how2electronics.com/heartbeat-pulse-bpm-rate-monitor-using-arduino-pulse-sensor/



#define USE_ARDUINO_INTERRUPTS true // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h>

// Variables
const int PulseWire = 0;
const int LED13 = 13;
int Threshold = 550; // Determine which Signal to "count as a beat" and which to ignore.


PulseSensorPlayground pulseSensor; // Creates an instance of the PulseSensorPlayground object called "pulseSensor"

void setup()
{

    Serial.begin(9600); // For Serial Monitor
    
    // Configure the PulseSensor object, by assigning our variables to it.
    pulseSensor.analogInput(PulseWire);
    pulseSensor.blinkOnPulse(LED13); //auto-magically blink Arduino's LED with heartbeat.
    pulseSensor.setThreshold(Threshold);
    
    // Double-check the "pulseSensor" object was created and "began" seeing a signal.
    if (pulseSensor.begin())
    {
        Serial.println("Pulse Sensor detected!"); //This prints one time at Arduino power-up, or on Arduino reset.
    }
}

void loop()
{
    int myBPM = pulseSensor.getBeatsPerMinute(); // Calls function on pulseSensor object that returns BPM as an "int".


    if (pulseSensor.sawStartOfBeat())  // Constantly test to see if "a beat happened".
    { 
        Serial.print("BPM: ");
        Serial.println(myBPM);
    }
    
    delay(20); // considered best practice in a simple sketch.
}

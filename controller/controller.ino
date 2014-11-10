#include <avr/sleep.h>

int PWM = 3;
int LED_R = 5; 
int LED_G = 4;
int VOLT = A0; // voltage sensing divider goes here
int POT = A1; // variable resistor goes here

int bright = 0;
int voltage = 0;
 
void setup()
{
    pinMode(PWM, OUTPUT);
    pinMode(LED_R, OUTPUT);
    pinMode(LED_G, OUTPUT);
}
 
void loop()
{
    // check voltage
    voltage = analogRead(VOLT);
    
    if (voltage > 386){  // >11.5v
      digitalWrite(LED_R,false); // red off
      digitalWrite(LED_G,true); // green on
    
    } 
    else if (voltage > 357){  // >10.7v
      digitalWrite(LED_R,true); // red on
      digitalWrite(LED_G,false); // green off
    }
    else { // <10.7v - halting system, red led is on!
      analogWrite(PWM,0);
      digitalWrite(LED_R,true);
      digitalWrite(LED_G,false);
      cli(); // disabling interrupts;
      sleep_enable(); //enabling sleep
      sleep_cpu(); // sleep until reset
    }
    
    // brightness setup
    bright = analogRead(POT);
    // readout is 0-1023
    // we need approx. 20 (min) - 200 (no need to supply 14v to stripe!)
    analogWrite(PWM, (bright+95)*0.18);
}

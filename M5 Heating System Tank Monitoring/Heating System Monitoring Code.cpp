#include "mbed.h"

// Output
DigitalOut led(p5);  //warning LED 
PwmOut speaker(p21); //Audible status signals 

// Inuts of the sensors
AnalogIn level(p15);  //for tank level 
AnalogIn temp(p16);  //for tank temperature 

// low val and high val and variable i
float loval, hival, i;

int main() {
    
    led=0; // led configured
    speaker = 0.5; // Duty cycle config
    while (1) {
        while(level < 0.75){
          led = !led;
                  //emit one cycle of warble 
          for(i=0; i<1; i+=0.05){   //20 steps 
          speaker.period(0.010-(0.008*i)); // Frequence Modulations
                                            // f=100, ends f=500  
           wait_ms (50); 
        }  //end of for, which lasts approx  
               //20x50 = 1000 ms 
        }
        led = 0;
            if(temp.read()< 0.33){  //is temp too cold? 
                hival = 0.005;      //set 200 Hz as tone 
                loval = 1; //no output wanted for 2nd tone,  
                //so set to (inaudible)1 Hz        
                } 
            if(temp.read()> 0.66){ //is temp too high? 
                hival = 0.001; //set 1000 Hz as upper tone 
                loval = 0.005; //set 200 Hz as lower tone       
                }
            if((temp.read()> 0.33)&&(temp.read()< 0.66)){  
                                        //is temp right? 
                hival = 0.002; //set 500 Hz as upper tone 
                loval = 0.002; //set 500 Hz as lower tone       
                 }
         //emit tones 
        speaker.period (hival); 
        wait_ms (500); 
        speaker.period (loval); 
        wait_ms(500);
    }
}

#include "mbed.h"
//Author Saswat Mund

// Push button 1: User start button; closure = logic 1.
// Push button 2: Stop; closure = logic 1.
// Switch 1: Machine guard sensor; closed condition = logic 1.
// Switch 2: Temperature sensor; excess temperature = logic 1.
#define BTSTART p5
#define BTSTOP p6
#define SWGAURD p7
#define SWTEMP p8
// Inputs
DigitalIn start(BTSTART);
DigitalIn stop(BTSTOP);
DigitalIn guard(SWGAURD);
DigitalIn temp(SWTEMP);

// LED 1: Motor is ready to run, i.e. guard is closed, temperature is OK. This LED should flash when machine in “not ready” state. 
// LED 2: Motor is running. 
// LED 3: Fault condition – guard opened while running, shows for 0.5 s. 
// LED 4: Fault condition – excess temperature, shows for 0.5 s.
#define LED1 p10
#define LED2 p11
#define LED3 p12
#define LED4 p13
//Outputs
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

bool motorRun = false;


// Function when start button is pressed
void startFun(){
    motorRun = false;
    led2 = led3 = led4 = 0;
    if(guard && !temp){ // check if everything is okay for motor to be ready
        led1 =1;
        wait(0.2f);
        led1 = 0;
        motorRun = true;
        led2 =1;
    }
}

// when stop button is pressed
void stopFun(){

    motorRun = false;
    led1=led2=led3=led4 = 0;
}

// when is guard opened while running
void guardOpen(){
    if(motorRun){
         led3 = 1;
         led1 = led2 = led4 = 0;
         wait(0.5f);
         led3 = 0;
         motorRun = false;
    }
}

//when is temp exceed threshold value
void tempExced(){
   if(motorRun){
          led4 = 1;
          led1 = led2 = led3 = 0;
          wait(0.5f);
          led4 = 0;
          motorRun = false;
     }

}

int main() {
    printf("Starting Machine Control",motorRun);
    bool initStart = false;
    led1=led2=led3=led4=0;
    while (1) {
         if(start){
             initStart = true;
             startFun();
         }
         if(initStart){
             if(stop){
                 stopFun();
             }
             if(!guard){
                 guardOpen();
             }
             if(temp){
                 tempExced();
           
             }
             if(!motorRun){
                 if(guard && !temp && !stop){
                     startFun();
                 }
             }
            while(!guard || temp){ // check for fault
                  led1 = !led1; // Flash Led1
                  wait(0.2f);
                }
         }
         
         wait(0.001f);
    }
}

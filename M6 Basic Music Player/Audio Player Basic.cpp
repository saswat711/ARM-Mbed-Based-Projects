#include "mbed.h"

#define SPEAKER p21
#define RED_LED p22
#define YELLOW_LED p23
#define BLUE_LED p24
#define AIN1 p15
#define AIN2 p16
// Define the frequency of basic music notes
# define No     0
# define C      0.2
# define Db     0.25
# define D      0.31
# define Eb     0.37
# define E      0.43
# define F      0.50
# define Gb     0.57
# define G      0.65
# define Ab     0.73
# define A      0.81
# define Bb     0.904
# define B      1


// Define the beat length (e.g. whole note, half note) 
# define whole       1
# define half        0.5
# define quarter     0.25
# define eighth      0.125
# define sixteenth   0.0625


// Here we have used Merry christams song
// Defining the musical piece
float note[] = {C, F, F, G, F, E, D, D,    D, G, G, A, G, F, E, C,     C, A, A, Bb, A, G, F, D,      C, C, D, G, E, F,      C, F, F, F, E,       E, F, E, D, C,       G, A, G, F, C, C,       C, C, D, G, E, F,      C, F, F, G, F, E, D, D,    D, G, G, A, G, F, E, C,     C, A, A, Bb, A, G, F, D,      C, C, D, G, E, F,      C, F, F, F, E,       E, F, E, D, C,       G, A, G, F, C, C,       C, C, D, G, E, F,};
float beat[] = {half, half, half, half, half, half, half, whole,    half, half, half, half, half, half, half, whole,     half, half, half, half, half, half, half, whole,      half, half, half, half, half, whole,      half, half, half, half, whole,       half, half, half, half, whole,       half, half, half, half, half, whole,       half, half, half, half, half, whole,      half, half, half, half, half, half, half, whole,    half, half, half, half, half, half, half, whole,     half, half, half, half, half, half, half, whole,      half, half, half, half, half, whole,      half, half, half, half, whole,       half, half, half, half, whole,       half, half, half, half, half, whole,       half, half, half, half, half, whole};


// Outputs for the audio player
//Define the PWM output for the speaker 
PwmOut Speaker(SPEAKER); 

//Define the PWM output for the RGB LED 
PwmOut RedLed(RED_LED); 
PwmOut YellowLed(YELLOW_LED); 
PwmOut BlueLed(BLUE_LED); 

// Inputs for volume and the speed
AnalogIn Volume(AIN1);
AnalogIn Speed(AIN2);

// Defining Ticker
Ticker timer;

// Static variable
static int k;
static float volume;
static float speed;

// Define the timer ISR functions
void timer_ISR(){ 
	if (k<(sizeof(note)/sizeof(int))){

		if(note[k] == No) {                       	//If there is a sound pause
			
			Speaker = 0;                          	//Set the PWM duty cycle to zero
		
		} else {

			Speaker.period(0.02*note[k]);   		//Set the PWM period, which determines the note of the sound
			Speaker = volume;          				//Set the PWM duty cycle that determines the volume of the sound (controlled by one potentiometer)
		
		}

		k++;
			
		//Set the time for the next ticker interrupt, this is determined by the default music beat and the potentiometer
		timer.attach(&timer_ISR, ((beat[k]/2)+(speed/2)));
			
		//RGB LED indicator
    	RedLed = note[k];
		YellowLed = Speaker;
		BlueLed = beat[k];
    
	} else {
		k = 0;                                 	//If the musical piece is finished, start again
		Speaker = 0;
	}
} 


int main() {
    
    timer.attach(&timer_ISR, 0.1);
    k = 0;
    while (1) {
            volume = Volume.read();
            speed = Speed.read();
            wait_ms(1);
    }
}

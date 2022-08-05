# This repo contains all the projects asked to be made in the ARM Embedded System training.

# Software Used: 
Mbed Simulator & Mbed Studio

# Device Used:
for simulation: ARM MBED (LPC1768)

# ---> Module 3:

      [Motor Controller](https://github.com/saswat711/ARM-Mbed-Based-Projects/tree/main/M3%20Machine%20(Motor)%20Controller)
      
** In this project it asked as **

You are part of a team developing a simple machine control system, based on an Mbed-enabled microcontroller. The machine has start and stop buttons. When it is started, a motor is powered. The motor must not start if the safety guard is open. The motor must be immediately switched off if the guard is opened, if the stop button is pressed, or if the operating temperature exceeds a certain value. The motor may be restarted if the stop button is released, and/or when the temperature falls to an acceptable value, if of course the guard is closed.

The following inputs and outputs are needed, with proposed logic values. 

Push button 1: User start button; closure = logic 1.
Push button 2: Stop; closure = logic 1.
Switch 1: Machine guard sensor; closed condition = logic 1.
Switch 2: Temperature sensor; excess temperature = logic 1.
LEDs are used to indicate machine status: 

LED 1: Motor is ready to run, i.e. guard is closed, temperature is OK. This LED should flash when machine in “not ready” state. 
LED 2: Motor is running. 
LED 3: Fault condition – guard opened while running, shows for 0.5 s. 
LED 4: Fault condition – excess temperature, shows for 0.5 s. 
You are going to write and simulate (with the Mbed simulator) a program which meets this need.  

** The flow diagram is as followed **

   ![Flow Diagram](https://github.com/saswat711/ARM-Mbed-Based-Projects/blob/main/M3%20Machine%20(Motor)%20Controller/Flow%20Diagram.png?raw=true)

**  The simulatied circuit for the same **

   ![Simulated Diagram](https://github.com/saswat711/ARM-Mbed-Based-Projects/blob/main/M3%20Machine%20(Motor)%20Controller/Simulator%20Circuit.png?raw=true)

# ---> Module 4: 

      [Barber Shop Wait]([M4%20Barber%20Shop%20Wait](https://github.com/saswat711/ARM-Mbed-Based-Projects/tree/main/M4%20Barber%20Shop%20Wait))
      
** In this project it asked as **

A waiting area in a barbershop has very limited space. There are three barbers, and two categories of customer: 
child and adult. Barbers 1 and 2 cut only the hair of adults, while barber 3 cuts only children’s hair. 
There are 8 waiting spaces. Customers must come alone, except that children must come with one parent; 
no one is allowed entry if there is no waiting space. One haircut takes 12 minutes,
 with 1 minute gap before the next customer. Once their hair is cut, 
customers leave the shop without re-entering the waiting area; children’s parents however remain in the waiting area until their child’s haircut is complete.
 The wall on the clock ticks every minute. In the case of a fire alarm, 
all customers must leave the shop in an orderly fashion. 

Write and then simulate a program which replicates this activity. 
Interrupts should be used for adult or child requesting entry, and for the fire alarm. 
To ease testing, reduce each minute to one second, or a convenient time-slot. Seat occupancy should be indicated by LEDs

Barber 1 seems to be busier than Barber 2, always for example getting the first adult customer through the door. 
Can you share the work more fairly? 

On a school day Barber 3 will be idle! Can you let him give priority to children, 
but take on adults if there are no children? 

** The flow diagram is as followed **

   ![Flow Diagram1](https://github.com/saswat711/ARM-Mbed-Based-Projects/blob/main/M4%20Barber%20Shop%20Wait/FLow%20Chart%201.png?raw=true)
   ![Flow Diagram2](https://github.com/saswat711/ARM-Mbed-Based-Projects/blob/main/M4%20Barber%20Shop%20Wait/FLow%20Chart%202.png?raw=true)

** The simulatied circuit for the same **

   ![Simulated Diagram](https://github.com/saswat711/ARM-Mbed-Based-Projects/blob/main/M4%20Barber%20Shop%20Wait/Simulator%20Circuit.png?raw=true)


# ---> Module 5:

      [Heating System Tank Monitoring](https://github.com/saswat711/ARM-Mbed-Based-Projects/tree/main/M5%20Heating%20System%20Tank%20Monitoring)
      
** In this project it asked as **

You are developing the monitoring (but not control) system for a heating tank in an industrial process. There are two sensors in the tank, one for temperature and the other for level. Four output states must be detected, each triggering a different audible status tone: 

Tank is full, temperature too high (upper third of temperature range) : two-tone  
Tank is full, temperature is good (middle third of temperature range): steady continuous tone 
Tank is full, temperature too low (lower third of temperature range): single beeping tone 
Tank level is too low (tank less than three quarters full), any temperature: frequency-modulated “warble”  tone, flashing LED 
Sensors must be tested at least once every two seconds. 

Write a program to meet this requirement, testing and demonstrating it on the Mbed simulator. Use potentiometers for tank level and temperature, and the Pwm speaker to generate the audible status signals.
** The flow diagram is as followed **

   ![Flow Diagram](https://github.com/saswat711/ARM-Mbed-Based-Projects/blob/main/M5%20Heating%20System%20Tank%20Monitoring/Flow%20Chart.png?raw=true)

** The simulatied circuit for the same **

   ![Simulated Diagram](https://github.com/saswat711/ARM-Mbed-Based-Projects/blob/main/M5%20Heating%20System%20Tank%20Monitoring/Simulator%20Circuit.png?raw=true)


# ---> Module 6:

      [Basic Music Player](https://github.com/saswat711/ARM-Mbed-Based-Projects/tree/main/M6%20Basic%20Music%20Player)
      
** In this project it is asked to **

create a basic music player.
Configure analog Inputs for the volume and speed of playing.
Configure the PWM output for the speaker and RGB LEDs. The speaker will play the music, 
while the LEDs will reflect the melody of the song by modifying the intensity of each LED.

** The simulated circuit is **

![Simulated Circuit](https://github.com/saswat711/ARM-Mbed-Based-Projects/blob/main/M6%20Basic%20Music%20Player/Simulation%20Circuit.png?raw=true)

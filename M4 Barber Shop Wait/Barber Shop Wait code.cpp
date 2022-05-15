#include "mbed.h" 

//Interrupt
InterruptIn adultIn(p5);
InterruptIn childIn(p6);
InterruptIn fireIn(p7);

//Outputs
DigitalOut noEntry(p8);
DigitalOut barb1(p9);
DigitalOut barb2(p10);
DigitalOut barb3(p11);
DigitalOut Wall_clk(p12);

//Bus Chairs   //waiting area chairs
BusOut chair (p13,p14,p15,p16,p17,p18,p19,p20);
                              
                                
//Haircut timing info per chair 
int timeB1,timeB2,timeB3;  
                  
//seating pattern,  
//no of children and parents waiting,  
//no of adults waiting                       
int seating,seatsPat,childNo,adultNo; 


//Declare Functions
// To have adult ISR
void adult_ISR(){ 
    if ((adultNo+childNo)<8){  //check for 1 space 
        adultNo++;  //increase waiting adult no 
        seatsPat=seatsPat<<1;  //customers shift left 
        seatsPat=seatsPat|01;  //OR in new arrival 
    } else { 
        noEntry=1; 
        wait_ms (40);  
        //a symbolic flash, which upsets loop timing a little 
        noEntry=0; 
    } 
} 

// To have child ISR
void child_ISR(){ 
   if ((adultNo+childNo)<7){    
        //check for 2 spaces 
        childNo=childNo+2;   
        //increase waiting by child + parent 
        seatsPat=seatsPat<<2;   
        //increase seating pattern by 2 
        seatsPat=seatsPat|03;  //OR in new arrivals 
    } else { 
        noEntry=1; 
        wait_ms (40); 
        noEntry=0; 
    } 
} 

//To have ISR for fire alarm
void fire_ISR(){ 
    noEntry=1; 
    barb1=barb2=barb3=0;  
     //clear barbers' chairs first 
    while(seatsPat!=0){         
        //those in waiting area file out in orderly fashion 
       seatsPat=seatsPat>>1; 
       seating=seatsPat;    
        //update seating pattern display 
       wait_ms(600); 
    } 
    childNo=0; 
    adultNo=0; 
    wait(20); 
    noEntry=0; 
} 

// Main functions
int main(){ 

    adultIn.rise(&adult_ISR);  //set up interrupts 
    childIn.rise(&child_ISR); 
    fireIn.rise(&fire_ISR); 

    while(1){   // enter main while loop 
        //Check seat 1 
        //if chair occupied, decrement time counter 
        if(barb1==1){      
            timeB1--; 
            if (timeB1==0) {
                barb1=0;    //customer leaves chair and exits 
            }
        } else if(adultNo!=0){ 
            barb1=1;  //invite customer into chair 
            adultNo--;  //one adult leaves waiting area 
            //remaining customers shift right 
            seatsPat=seatsPat>>1;  
            timeB1=12; //set Timer 
        }
        
        // Check for seat 2
                //if chair occupied, decrement time counter 
        if(barb2==1){      
            timeB2--; 
            if (timeB2==0) {
                barb2=0;    //customer leaves chair and exits 
            }
        } else if(adultNo!=0){ 
            barb2=1;  //invite customer into chair 
            adultNo--;  //one adult leaves waiting area 
            //remaining customers shift right 
            seatsPat=seatsPat>>1;  
            timeB2=12; //set Timer 
        }


          //Check seat 3 
        if(barb3==1){      
            //if chair occupied, decrement time counter 
            timeB3 --; 
            if (timeB3==0){ 
                barb3=0;    //child leaves chair and exits 
                childNo--;    
                //accompanying parent leaves waiting area and exits 
                seatsPat=seatsPat>>1;  
                //remaining customers shift right 
            }  
        } else if(childNo!=0){ 
            barb3=1;  //invite child into chair 
            childNo--;  //one child leaves waiting area 
            seatsPat=seatsPat>>1;  
            //remaining customers shift right 
            timeB3=12; //set Timer 
        } 
        else if (childNo == 0){
            if(adultNo!=0){ 
               barb3=1;  //invite customer into chair 
               adultNo--;  //one adult leaves waiting area 
               //remaining customers shift right 
               seatsPat=seatsPat>>1;  
               timeB3=12; //set Timer 
          }
        }

        seating=seatsPat;  //update seating pattern display 
        wait_ms(1000);     //adjust for simulator convenience     
        //notional time delay to set loop time 
        Wall_clk=!Wall_clk;  //the wall clock ticks! 
    }  //end of while (1) 
    
}  //end of main() 

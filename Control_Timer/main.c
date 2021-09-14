#include <avr/io.h> void timer_delay(); 

int main(void){
    
     DDRC = 0xFF; /* PORTC as output*/ /* main loop */

 while(1){ 
     
     PORTC=0x01; /* Pulse PC1 ON*/

  timer_delay(); /* 20us delay */ 

  PORTC=0x00; /* Pulse PC1 OFF */ 

  timer_delay(); /* 20us delay */ }
   }
   void timer_delay(){

        TCNT0 = 0x5F; 
        /* Load TCNT0 with the start value*/

         TCCR0 = 0x01; 
         /* Timer0, normal mode, no pre-scalar */ 

         while((TIFR&0x01)==0);
          /* Wait for TOV0 to roll over, i.e. overflow */

         TCCR0 = 0;
          /* set TCCR0 to 0 to stop the timer */ 

         TIFR = 0x1;
          /* Clear TOV0 flag*/

          }


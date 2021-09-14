#include <avr/io.h>

void timer_delay(); 

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

         TCCR0A = 0x01; 
         /* Timer0, normal mode, no pre-scalar */ 

         while((TIFR0 & 0x01)==0);
          /* Wait for TOV0 to roll over, i.e. overflow */

         TCCR0A = 0;
          /* set TCCR0 to 0 to stop the timer */ 

         TIFR0 = 0x1;
          /* Clear TOV0 flag*/

          }
		  
		   /*
		   had to add an a to the Timer/control register hence it became; TCCR0A
		   had to add a 0 to the Timer/ counter interrupt flag register hence it became; TIFRA0
		   
		   */
		   
		   


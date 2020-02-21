#include <iostm8s003F3.h>
#include <intrinsics.h>
#include "delay.h"
#pragma vector = 8


__interrupt void EXTI_PORTD_2(void)
{
PB_ODR_ODR5 = !PB_ODR_ODR5; // Toggle Port B, pin 5.
}
void main()
{
CLK_ICKR=1; // High-speed internal RC on = 16 Mhz
CLK_CKDIVR = 24; //fHSI RC output/8 & fCPU=fMASTER/1

__disable_interrupt();

//PORTB5 output
PB_DDR_DDR5 =1; 
PB_CR1_C15 = 1;
PB_CR2_C25 = 1;

//PIND2 input Interrupt
PD_DDR_DDR2 =0;
PD_CR1_C12 = 1;
PD_CR2_C22 = 1;


// Set up the interrupt.
//
EXTI_CR1_PDIS = 2; // Interrupt on falling edge.
EXTI_CR2_TLIS = 0; // Falling edge only.

__enable_interrupt();

while (1)
{
__wait_for_interrupt();
}
}
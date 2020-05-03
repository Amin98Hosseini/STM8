#include <iostm8s003f3.h>
#include <intrinsics.h>
#include "delay.h"

unsigned int count=0;

// toggle pin every 1 seconde
#pragma vector = 0x19

__interrupt void timer4_interrupt(void)
{
  count++;
  if(count>60)
    {
      PD_ODR_bit.ODR3=!PD_ODR_bit.ODR3;
      count=0;
    }
  TIM4_SR_bit.UIF=0; // timer4 interrupt flage=0
}

//main entry point
int main( void )
{
  CLK_ICKR=1; // High-speed internal RC on = 16 Mhz
  CLK_CKDIVR = 24; //fHSI RC output/8 & fCPU=fMASTER/1
  PD_ODR = 0; //Turn off all pins
  PD_DDR_DDR3 = 1; //PortD, Bit 3 is output (PD3 - Data Direction Register)
  PD_CR1_C13 = 1; //PortD, Control Register 1, Bit 3 (PD3) set to Push-Pull
  PD_CR2_C23 = 1; //PortD, Control Register 2, Bit 3 (PD3) Output speed up to 10 MHz
  TIM4_IER_bit.UIE=1; // timer4 interrupt enable
  TIM4_SR=0; // timer4 interrupt flage=0
  TIM4_CNTR=0; // timer4_value=0
  TIM4_PSCR=7; // prescaler=128
  TIM4_CR1=1; // timer4 enable
  __enable_interrupt();
  while (1)
  {
    __wait_for_interrupt();
  }
}


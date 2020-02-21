#include <iostm8s003f3.h>
#include "delay.h"

#define led PB_ODR_bit.ODR5
#define key PB_IDR_bit.IDR4


unsigned char i;
//main entry point
int main( void )
{
CLK_ICKR=1; // High-speed internal RC on = 16 Mhz
CLK_CKDIVR = 24; //fHSI RC output/8 & fCPU=fMASTER/1
PB_DDR_DDR5 = 1; //PortB, Bit 5 is output (PB5 - Data Direction Register)
PB_CR1_C15 = 1; //PortB, Control Register 1, Bit 5 (PD5) set to Push-Pull
PB_CR2_C25 = 1; //PortB, Control Register 2, Bit 5  (PD5) Output speed up to 10 MHz
for(i=0;i<10;i++){
PB_ODR_bit.ODR5 = !PB_ODR_bit.ODR5;
delay_ms(500);
}
WWDG_CR=255; // Watchdog enabled

while (1)
{
WWDG_CR=255; //reset value of Watchdog
//Turn on and off the output and then delay
PB_ODR_bit.ODR5 = !PB_ODR_bit.ODR5;
delay_ms(1000);
}
}

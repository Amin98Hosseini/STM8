#include <iostm8s003k3.h>
#include <intrinsics.h>
#include "lcd.h"
#include "delay.h"

// Variable
int i=0,j=0;

// Config PIN OUT For lcd 
void InitMCU(void)
{
CLK_CKDIVR = 0x00;
PC_DDR = 0xF0;
PC_CR1 = 0xF0;
PC_ODR = 0x00;
PD_DDR_DDR4 = 1;
PD_CR1_C14 = 1;
PD_ODR_ODR4 = 0;
PD_DDR_DDR5 = 1;
PD_CR1_C15 = 1;
PD_ODR_ODR5 = 0;

PB_ODR=0;
// LED Config
PB_DDR_DDR5 = 1;
PB_CR1_C15 = 1;
PB_CR2_C25 = 1;

// Keys Config
PB_DDR_DDR4 = 0;
PB_CR1_C14 = 1;
PB_CR2_C24 = 0;
}


int main( void )
{
 InitMCU();
 lcd_init();
 lcd_clear();
 PB_ODR_bit.ODR5=1;
 lcd_gotoxy(0,0);
 lcd_puts("AMIN");
 delay_ms(1500);
 lcd_clear();
 
 while(1)
 {
   
  if(PB_IDR_IDR4==0)
  {
    
    while(PB_IDR_IDR4==0);
    delay_ms(100);
    i++;
    j++;
    if(j==2)
      i=0;
    lcd_clear();
  }
  
  if(i==1)
  {
   lcd_gotoxy(0,0);
   lcd_puts("Led ON");
   PB_ODR_bit.ODR5=0;
   i=0;
  }
  
  if(j==2)
  {
   lcd_gotoxy(0,0);
   lcd_puts("Led OFF");
   PB_ODR_bit.ODR5=1;
   j=0;
  }
   
 }
}

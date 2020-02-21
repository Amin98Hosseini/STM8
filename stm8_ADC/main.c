#include <iostm8s003k3.h>
#include <intrinsics.h>
#include "lcd.h"
#include "delay.h"
#include <stdio.h>

// Variable
int i=0,j=0;
char a[4];
signed int l,h;
float value,v;
// Config PIN OUT For lcd 
void InitMCU(void)
{
CLK_CKDIVR = 1;

PC_DDR = 0xFF;
PC_CR1 = 0xFF;
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

float read_adc(int i)
{
    if(i==6)
    {
      ADC_CSR=0x06; // ADC on AIN6
      ADC_CR2=0X38; // right Right alignment
      ADC_CR1=0x01; // Turn ADC on & triger
      //while(ADC_CSR_EOC==0);
      l=ADC_DRL;
      h=ADC_DRH;
      value=h*256;
      value=value+l;
    }
    return value;
}

int main( void )
{
 PB_DDR_DDR0 = 0;
 InitMCU();
 lcd_init();
 lcd_clear();
 PB_ODR_bit.ODR5=1;
 lcd_gotoxy(1,0);
 lcd_puts("AMIN");
 delay_ms(1500);
 lcd_clear();
 
 while(1)
 {
    v=read_adc(6);
    v=(v*3.3)/1023;
    lcd_string(1,1,"ADC6= ");
    sprintf(a,"%2.2f ",v);
    lcd_string(1,6,a);
    delay_ms(1000);
   
   /*
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
  }*/
   
 }
}

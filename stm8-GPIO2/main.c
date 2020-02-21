#include <iostm8s003f3.h>

void delay_ms(unsigned long int n)
{
unsigned long int x=0;
unsigned long fCPU=2000000; 
x=fCPU/1000;
x=x/50;
n=n*x;
while (n-- > 0);
}

//main entry point
int main( void )
{
  CLK_ICKR=1; 
  CLK_CKDIVR = 24; 
  PD_ODR = 0; 
  PD_DDR_DDR3 = 1; 
  PD_CR1_C13 = 1; 
  PD_CR2_C23 = 1; 

  PB_ODR=0;    
  PB_DDR_DDR5=0;   
  PB_CR1_C15 = 1;  
  PB_CR2_C25 =0;
  while (1)
  {
    if(PB_IDR_IDR5==0)
    {
      while(PB_IDR_IDR5==0);
      delay_ms(50);
      PD_ODR_bit.ODR3 = !PD_ODR_bit.ODR3;
    }
  }
}

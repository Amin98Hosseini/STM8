/* ----------------------------------------------------------------------------
library name :delay
this library is provide by alimohammad shafiee for stm8

date   1394/09/23
time   22:27:00

delay_ms(.....)
delay_us(.....)
*/


void delay_ms(unsigned long int n)
{
  unsigned long int x=0;
  unsigned long fCPU=2000000;  // HSI RC =16 MHz ----- HSIDIV=8 ------CPUDIV=1    fCPU=16 / 8 / 1 Mhz

  x=fCPU/1000;
  x=x/50;
  n=n*x;
      while (n-- > 0);
}

void delay_us(unsigned long int n)
{
  unsigned long int x=0;
  unsigned long fCPU=2000000;  // HSI RC =16 MHz ----- HSIDIV=8 ------CPUDIV=1    fCPU=16 / 8 / 1 Mhz

  x=fCPU/1000000;
  x=x/50;
  n=n*x;
      while (n-- > 0);
}
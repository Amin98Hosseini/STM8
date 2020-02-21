#include <iostm8s003F3.h>
#include <intrinsics.h>
#include "lcd.h"
 
void Delay(unsigned long int k)
{
  k *= 250;
  while(k--);
}
 
void lcd_enable (void)
{
  LCD_Enable = 1;
  _NOP, _NOP, _NOP;
  LCD_Enable = 0;
}
 
void lcd_command(unsigned char cmd)
{
  LCD_RS = 0;
  LCDPort= 16*((cmd >> 4) & 0x0F);
  lcd_enable();
  LCDPort = 16*(cmd & 0x0F);
  lcd_enable();
  Delay(2);
}
 
void lcd_clear(void)
{
  lcd_command(0x01);
  Delay(2);
}
 
void lcd_putch(unsigned char c)
{
  LCD_RS = 1;
  LCDPort=16*((c >> 4) & 0x0F);
  lcd_enable();
  LCDPort= 16*(c & 0x0F);
  lcd_enable();
  Delay(2);
}
 
void lcd_puts(const char *s)
{
  while(*s)
    lcd_putch(*s++);
}
 
void lcd_gotoxy(unsigned char row,unsigned char column)
{
   LCD_RS = 0;	
   if(row==1) 
     lcd_command(0x80+((column-1)%16));
   else if (row==2)  
     lcd_command(0xC0+((column-1)%16));
}
 
void lcd_init(void)
{
  LCD_Enable = 1;
  LCD_RS = 0;
 
  lcd_command(0x33);
  Delay(4);
  lcd_command(0x32);
  Delay(4);
 
  lcd_command(0x28);
  lcd_command(0x0C);
  lcd_command(0x06);
  lcd_clear();
  Delay(200);
}
 
void lcd_lshift(void)
{
  lcd_command(0x18);
}
 
void lcd_rshift(void)
{
  lcd_command(0x1C);
}
 
void lcd_display_on(void)
{
  lcd_command(0x0C);
}
 
void lcd_display_off(void)
{
  lcd_command(0x08);
}
 
void lcd_string(unsigned char i,unsigned char j,const char *s)
{
  lcd_gotoxy(i,j);
  while(*s)
    lcd_putch(*s++);
}
 
void lcd_char(unsigned char x,unsigned char y,unsigned char z)
{
  lcd_gotoxy(x,y);
  lcd_putch(z);	
}
 
void lcd_sChar(unsigned char k,unsigned char m,unsigned char n)
{
    lcd_gotoxy(k,m);
    Write_SpecChar(n);	
}	
 
void specialCharacters(void)
{
//CGRAM 1.Adrese ; 'C' harfi
   lcd_command(0x40); lcd_putch(0x0E);
   lcd_command(0x41); lcd_putch(0x11);
   lcd_command(0x42); lcd_putch(0x10);
   lcd_command(0x43); lcd_putch(0x10);
   lcd_command(0x44); lcd_putch(0x11);
   lcd_command(0x45); lcd_putch(0x0E);
   lcd_command(0x46); lcd_putch(0x04);
   lcd_command(0x47); lcd_putch(0x00);
 
//CGRAM 2.Adrese ; '?' harfi
   lcd_command(0x48); lcd_putch(0x0E);
   lcd_command(0x49); lcd_putch(0x00);
   lcd_command(0x4A); lcd_putch(0x0F);
   lcd_command(0x4B); lcd_putch(0x10);
   lcd_command(0x4C); lcd_putch(0x13);
   lcd_command(0x4D); lcd_putch(0x11);
   lcd_command(0x4E); lcd_putch(0x0F);
   lcd_command(0x4F); lcd_putch(0x00);
 
//CGRAM 3.Adrese ; '?' harfi
   lcd_command(0x50); lcd_putch(0x04);
   lcd_command(0x51); lcd_putch(0x00);
   lcd_command(0x52); lcd_putch(0x0E);
   lcd_command(0x53); lcd_putch(0x04);
   lcd_command(0x54); lcd_putch(0x04);
   lcd_command(0x55); lcd_putch(0x04);
   lcd_command(0x56); lcd_putch(0x0E);
   lcd_command(0x57); lcd_putch(0x00);
 
//CGRAM 4.Adrese ; '?' harfi
   lcd_command(0x58); lcd_putch(0x0A);
   lcd_command(0x59); lcd_putch(0x00);
   lcd_command(0x5A); lcd_putch(0x0E);
   lcd_command(0x5B); lcd_putch(0x11);
   lcd_command(0x5C); lcd_putch(0x11);
   lcd_command(0x5D); lcd_putch(0x11);
   lcd_command(0x5E); lcd_putch(0x0E);
   lcd_command(0x5F); lcd_putch(0x00);
 
//CGRAM 5.Adrese ; '?' harfi
   lcd_command(0x60); lcd_putch(0x0F);
   lcd_command(0x61); lcd_putch(0x10);
   lcd_command(0x62); lcd_putch(0x10);
   lcd_command(0x63); lcd_putch(0x0E);
   lcd_command(0x64); lcd_putch(0x01);
   lcd_command(0x65); lcd_putch(0x05);
   lcd_command(0x66); lcd_putch(0x1E);
   lcd_command(0x67); lcd_putch(0x00);
 
//CGRAM 6.Adrese ; 'U' harfi
   lcd_command(0x68); lcd_putch(0x0A);
   lcd_command(0x69); lcd_putch(0x00);
   lcd_command(0x6A); lcd_putch(0x11);
   lcd_command(0x6B); lcd_putch(0x11);
   lcd_command(0x6C); lcd_putch(0x11);
   lcd_command(0x6D); lcd_putch(0x11);
   lcd_command(0x6E); lcd_putch(0x0E);
   lcd_command(0x6F); lcd_putch(0x00);
 
//CGRAM 7.Adrese ; '?' harfi
   lcd_command(0x70); lcd_putch(0x00);
   lcd_command(0x71); lcd_putch(0x00);
   lcd_command(0x72); lcd_putch(0x0C);
   lcd_command(0x73); lcd_putch(0x04);
   lcd_command(0x74); lcd_putch(0x04);
   lcd_command(0x75); lcd_putch(0x04);
   lcd_command(0x76); lcd_putch(0x0E);
   lcd_command(0x77); lcd_putch(0x00);
 
//CGRAM 8.Adrese ; '°' harfi
   lcd_command(0x78); lcd_putch(0x0C);
   lcd_command(0x79); lcd_putch(0x12);
   lcd_command(0x7A); lcd_putch(0x12);
   lcd_command(0x7B); lcd_putch(0x0C);
   lcd_command(0x7C); lcd_putch(0x00);
   lcd_command(0x7D); lcd_putch(0x00);
   lcd_command(0x7E); lcd_putch(0x00);
   lcd_command(0x7F); lcd_putch(0x00);
}
 
void Write_SpecChar(unsigned char chr)
{
   switch(chr)
    {
       case 'C': lcd_putch(0); break;
       case '?': lcd_putch(1); break;
       case '°': lcd_putch(7); break;
    }
}
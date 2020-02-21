#ifndef __LCD_H
#define __LCD_H
 
#define   LCD_Enable   PD_ODR_ODR4
#define   LCD_RS       PD_ODR_ODR5
#define   LCDPort      PC_ODR
#define   _NOP         __no_operation()
 
extern void Delay(unsigned long int);
extern void lcd_enable(void);
extern void lcd_command(unsigned char);
extern void lcd_clear(void);
extern void lcd_putch(unsigned char);
extern void lcd_puts(const char *);
extern void lcd_gotoxy(unsigned char,unsigned char);
extern void lcd_init(void);
extern void lcd_lshift(void);
extern void lcd_rshift(void);
extern void lcd_display_on(void);
extern void lcd_display_off(void);
extern void lcd_string(unsigned char,unsigned char,const char *);
extern void lcd_char(unsigned char,unsigned char,unsigned char);
extern void lcd_sChar(unsigned char,unsigned char,unsigned char);
extern void specialCharacters(void);
extern void Write_SpecChar(unsigned char);
 
#endif /* __LCD_H */
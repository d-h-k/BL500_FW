/* ========================================================================== */
/*		Exp06_5.c : printf() Function to Text LCD Module              */
/* ========================================================================== */
/*			  Designed and programmed by Duck-Yong Yoon in 2010.  */

#include <avr/io.h>
#include <stdio.h>
#include "OK-128LCD.h"

static int LCD_putchar(char c, FILE *stream);
static FILE device = FDEV_SETUP_STREAM(LCD_putchar, NULL, _FDEV_SETUP_WRITE);

static int LCD_putchar(char c, FILE *stream)	/* print a character to text LCD */
{
  if((c < 0x20) | (c > 0x7E))                   // check from 0x20 to 0x7E
    return 0;

  LCD_data(c);
  return 0;
}

int main(void)
{
  unsigned char i = 1;
  double x = 0.001;

  MCU_initialize();                             // initialize MCU and kit
  Delay_ms(50);                                 // wait for system stabilization
  LCD_initialize();                             // initialize text LCD module
  Beep();

  LCD_string(0x80," printf  to LCD ");          // display title
  LCD_string(0xC0,"Press KEY1-KEY4!");

  stdout = &device;				// set text LCD to stdout

  while(1)
    { switch(Key_input())                       // key input
        { case KEY1 : PORTD = 0x10;             // KEY1 ?
                      LCD_command(0x80);
                      printf("  KEY1 is OK !  ");
                      LCD_command(0xC0);
                      printf(" i=%03d  x=%5.3f ",i,x);
                      i++;
                      x += 0.001;
                      break;
          case KEY2 : PORTD = 0x20;             // KEY2 ?
                      LCD_command(0x80);
                      printf("  KEY2 is OK !  ");
                      LCD_command(0xC0);
                      printf(" i=%03d  x=%5.3f ",i,x);
		      i++;
                      x += 0.001;
                      break;
          case KEY3 : PORTD = 0x40;             // KEY3 ?
                      LCD_command(0x80);
                      printf("  KEY3 is OK !  ");
                      LCD_command(0xC0);
                      printf(" i=%03d  x=%5.3f ",i,x);
		      i++;
                      x += 0.001;
                      break;
          case KEY4 : PORTD = 0x80;             // KEY4 ?
                      LCD_command(0x80);
                      printf("  KEY4 is OK !  ");
                      LCD_command(0xC0);
                      printf(" i=%03d  x=%5.3f ",i,x);
		      i++;
                      x += 0.001;
                      break;
          default:    break;
        }
    }
}

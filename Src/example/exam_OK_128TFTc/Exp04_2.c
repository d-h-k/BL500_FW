/* ========================================================================== */
/*	  Exp04_2.c : User-Defined Character Display on Text LCD Module       */
/* ========================================================================== */
/*			  Designed and programmed by Duck-Yong Yoon in 2010.  */

#include <avr/io.h>
#include <avr/pgmspace.h>
#include "OK-128LCD.h"

prog_uchar font[] = {
  0x10, 0x18, 0x1C, 0x1E, 0x1C, 0x18, 0x10, 0x00,   // character 0 (left arrow)
  0x0F, 0x09, 0x09, 0x09, 0x09, 0x09, 0x0F, 0x00,   // character 1 (��)
  0x08, 0x08, 0x08, 0x0E, 0x08, 0x08, 0x08, 0x00,   // character 2
  0x01, 0x02, 0x04, 0x08, 0x00, 0x00, 0x0F, 0x00,   // character 3 (��)
  0x10, 0x08, 0x04, 0x02, 0x00, 0x00, 0x1E, 0x00,   // character 4
  0x0F, 0x08, 0x08, 0x0F, 0x08, 0x08, 0x0F, 0x00,   // character 5 (��)
  0x04, 0x04, 0x04, 0x1C, 0x04, 0x04, 0x04, 0x00,   // character 6
  0x01, 0x03, 0x07, 0x0F, 0x07, 0x03, 0x01, 0x00 }; // character 7 (right arrow)

void Set_font(void)                             /* set user character font */
{
  unsigned char i;

  LCD_command(0x40);                            // set CGRAM address
  for(i = 0; i < 64; i++)			// download font data
     LCD_data(pgm_read_byte(&font[i]));
}

int main(void)
{
  MCU_initialize();                             // initialize MCU and kit
  Delay_ms(50);                                 // wait for system stabilization
  LCD_initialize();                             // initialize text LCD module

  Set_font();                                   // set user character font

  while(1)
    { Beep();
      LCD_command(0x80);                        // display logo
      LCD_data(0x00);
      LCD_string(0x81," OK-128TFT V1 ");
      LCD_data(0x07);

      LCD_string(0xC0,"ATmega128 ");            // display message 1
      LCD_data(0x01);
      LCD_data(0x02);
      LCD_data(0x03);
      LCD_data(0x04);
      LCD_data(0x05);
      LCD_data(0x06);
      Delay_ms(2000);

      LCD_string(0xC0,"   2010/12/05   ");      // display message 2
      Delay_ms(2000);

      LCD_string(0xC0," DUCK-YONG YOON ");      // display message 3
      Delay_ms(2000);
    }
}


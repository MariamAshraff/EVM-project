/*
 * EVM.c
 *
 * Created: 11/7/2023 3:51:50 PM
 *  Author: VTE
 */ 

#include <avr/io.h>
#include "button.h"
#include "LCD.h"
#include "DIO.h"
#define F_CPU 8000000UL
#include <util/delay.h>

unsigned char counter1=0;
unsigned char counter2=0;
unsigned char counter3=0;
unsigned char counter4=0;
int main(void)
{
	LCD_vInit();
	DIO_vconnectpullup('D',3,1);
	DIO_vconnectpullup('D',6,1);
	DIO_vconnectpullup('D',4,1);
	DIO_vconnectpullup('D',5,1);
	DIO_vconnectpullup('D',7,1);
	button_vInit('D',3);
	button_vInit('D',4);
	button_vInit('D',5);
	button_vInit('D',6);
	button_vInit('D',7);
	
	LCD_vSend_string("A=0");
	LCD_movecursor(1,12);
	LCD_vSend_string("B=0");
	LCD_movecursor(2,1);
	LCD_vSend_string("C=0");
	LCD_movecursor(2,12);
	LCD_vSend_string("D=0");
    while(1)
    {
		if (button_u8read('D',3)==0)
		{
			counter1++;
			LCD_movecursor(1,3);
			if (counter1<10)
			LCD_vSend_char(counter1+48);
			else if (counter1<100)
			{
				LCD_vSend_char(counter1/10+48);
				LCD_vSend_char(counter1%10+48);
			}
			else if (counter1<1000)
			{
				LCD_vSend_char(counter1/100+48);
				LCD_vSend_char((counter1/10)%10+48);
				LCD_vSend_char(counter1%10+48);
			}
		}
		else if(button_u8read('D',4)==0)
		{
			counter2++;
			LCD_movecursor(1,14);
			if (counter2<10)
			LCD_vSend_char(counter2+48);
			else if (counter2<100)
			{
				LCD_vSend_char(counter2/10+48);
				LCD_vSend_char(counter2%10+48);
			}
			else if (counter2<1000)
			{
				LCD_vSend_char(counter2/100+48);
				LCD_vSend_char((counter2/10)%10+48);
				LCD_vSend_char(counter2%10+48);
			}
		}
		else if(button_u8read('D',5)==0)
		{
			counter3++;
			LCD_movecursor(2,3);
			if (counter3<10)
			LCD_vSend_char(counter3+48);
			else if (counter3<100)
			{
				LCD_vSend_char(counter3/10+48);
				LCD_vSend_char(counter3%10+48);
			}
			else if (counter3<1000)
			{
				LCD_vSend_char(counter3/100+48);
				LCD_vSend_char((counter3/10)%10+48);
				LCD_vSend_char(counter3%10+48);
			}
		}
		else if(button_u8read('D',6)==0)
		{
			counter4++;
			LCD_movecursor(2,14);
			if (counter4<10)
			LCD_vSend_char(counter4+48);
			else if (counter4<100)
			{
				LCD_vSend_char(counter4/10+48);
				LCD_vSend_char(counter4%10+48);
			}
			else if (counter4<1000)
			{
				LCD_vSend_char(counter4/100+48);
				LCD_vSend_char((counter4/10)%10+48);
				LCD_vSend_char(counter4%10+48);
			}
		}
		else if(button_u8read('D',7)==0)
		{
			counter1=counter2=counter3=counter4=0;
			LCD_movecursor(1,1);
			LCD_vSend_string("A=0  ");
			LCD_movecursor(1,12);
			LCD_vSend_string("B=0  ");
			LCD_movecursor(2,1);
			LCD_vSend_string("C=0  ");
			LCD_movecursor(2,12);
			LCD_vSend_string("D=0  ");
			LCD_movecursor(1,1);
		}
		_delay_ms(200);
    }
}


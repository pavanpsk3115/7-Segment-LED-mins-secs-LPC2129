#include <LPC21XX.H>
#include "delay_func.h"

#define seg_d 0XFF<<0
#define seg1 1<<8
#define seg2 1<<9
#define seg3 1<<10
#define seg4 1<<11

void display(int,int);
unsigned char seg[]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};
int main()
{
	int m=0,s=0;
	IODIR0=seg_d|seg1|seg2|seg3|seg4;
	while(1)
	{
		display(m,s++);
		if(s==60)
		{
			s=0;
			m++;
			if(m==60)
				m=0;
		}
		
	}
}
void display(int m,int s)
{
	int i;
	for(i=0;i<50;i++)
	{
		IOCLR0=seg_d|seg1;
		IOSET0=seg[m/10];
		delay_ms(5);
		IOSET0=seg1;
		
		IOCLR0=seg_d|seg2;
		IOSET0=seg[m%10]^0x80;
		delay_ms(5);
		IOSET0=seg2;
		
		IOCLR0=seg_d|seg3;
		IOSET0=seg[s/10];
		delay_ms(5);
		IOSET0=seg3;
		
		IOCLR0=seg_d|seg4;
		IOSET0=seg[s%10];
		delay_ms(5);
		IOSET0=seg4;
	}
}
	

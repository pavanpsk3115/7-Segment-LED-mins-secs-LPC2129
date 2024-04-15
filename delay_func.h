#include<LPC21XX.H>
typedef unsigned int u32;
void delay(u32);
void delay_ms(u32);
void delay_us(u32);
void delay(u32 n)
{
	T0PR=15000000-1;
	T0TCR=0X01;
	while(T0TC<n);
	T0TCR=0X03;
	T0TCR=0X00;
}
void delay_ms(u32 n)
{
	T0PR=15000-1;
	T0TCR=0X01;
	while(T0TC<n);
	T0TCR=0X03;
	T0TCR=0X00;
}
void delay_us(u32 n)
{
	T0PR=15-1;
	T0TCR=0X01;
	while(T0TC<n);
	T0TCR=0X03;
	T0TCR=0X00;
}

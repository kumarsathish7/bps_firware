#include<lpc21xx.h>
int prev=0;
void delay_ms(int ms)
 {
   T0PR=150000-1;              //Reset Timer0//Loading match register value                   //Loading Prescalar register value
   T0PC=T0TC=0;                    //Generates interrupt and reset on match
   T0TCR=0x1;             //Starting Timer
   while(T0TC<ms);  //Waiting for interrupt
   T0TCR=0x0; 
 }
 void delay_s(int ms)
 {
   T0PR=1500-1;              //Reset Timer0//Loading match register value                   //Loading Prescalar register value
   T0PC=T0TC=0;                    //Generates interrupt and reset on match
   T0TCR=0x1;             //Starting Timer
   while(T0TC<ms);  //Waiting for interrupt
   T0TCR=0x0; 
 }
void st_tim(void)
{
	 T0PR=1500-1;              //Reset Timer0//Loading match register value                   //Loading Prescalar register value
   T0PC=T0TC=0;                    //Generates interrupt and reset on match
   T0TCR=0x1;  
}
int tim_stam(void)
{
	prev+=T0TC;
	return 	prev;
	
}

 
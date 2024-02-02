#include<lpc21xx.h>
#include <string.h>
#include <stdio.h>
void tx(unsigned char d)
{
	while(!U0LSR&(1<<5));
	U0THR=d;
}
void s_tx(char *ptr){
	while(*ptr!=0){
		U0THR=*ptr;
		while((U0LSR&(1<<5))==0);
		ptr++;
	}
}

void uart_config(void)
{
	PINSEL0=0X05 ;   //	TO SELECT UART FUNC
	U0LCR=0X83;      //to select 8ni frame
	U0DLL=390;      //To set baud rate 2400
	U0LCR=0X03;
	
}
int rx(void)
{
	while(!U0LSR&(1<<0));
	return U0RBR;
}
void int_tx(int num){
	char buf[10];
	sprintf(buf,"%d",num);
	s_tx(buf);
}
void flo_tx(float num){		
	int i=0;
	i=num;
   int_tx(i);
	i=(num-i)*10;
	tx('.');
	int_tx(i);
}

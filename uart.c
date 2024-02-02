#include<lpc21xx.h>
#include "uart.h"
#include "i2c.h"
#include "i2c_eeprom.h"
#include <string.h>
#define I2C_EEPROM_SA 0x50 //7Bit Slave Addr
void bps(void);
u8 p[1024] __attribute__((at(0x40000040)))="";
int prev,temp;
float rate,avg;
main()
{
	 u8 h[1024];
	 int i=0,k,ptr=0;
	 uart_config();         //baud rate set as 2700
   init_i2c();
	
   st_tim();                   //to get time stamp of rx
	delay_s(25);
	
	while(2){
     tx(rx());
	   	h[i]=rx();             //recieve uart RX
	  	if(	h[i-1]='\0'){
			break;}
			i++;
			bps();
		}
		
  avg=i/rate;
   int_tx(avg);  //average value of bps with total bytes recived;

for(k=0;k<i;k++){
	if(h[k]==' '){      //write into EEprom word by word
	i2c_eeprom_page_write(I2C_EEPROM_SA,0x03+ptr,h+ptr,k-ptr);
	ptr=k+2;}
  else{
	continue;}
}

i2c_eeprom_seq_read(I2C_EEPROM_SA,0x03,p,ptr); //read from saved EEPROM memory
s_tx(p);                                       //print in terminal


}
void bps(void)
{
	temp = tim_stam();
	rate = 1/((float)temp*0.001-(float)prev*0.001); //for 1 byte time taken millisec
	prev = temp;
	flo_tx(rate);
}
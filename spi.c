#include<lpc21xx.h>
#include"header.h"

extern unsigned char id[10];
void spi_init(void)
{
	PINSEL0|=0x00001500;//P0.4-->CLK0

						//P0.5-->MISO0

						//P0.6-->MOSI0	

	IODIR0|=(1<<7);		//P0.7-->Out dir(CS0) 	

	IOSET0=(1<<7);		//*CS0=1

	S0SPCCR=12;			//spi0 speed==1Mbps

	S0SPCR=0x20;		//CPOL=CPHA=0
}

#define SPIF ((S0SPSR>>7)&1)


unsigned char spi_transfer(unsigned char data){

	S0SPDR=data;	//data to slave

	while(SPIF==0);

	return S0SPDR;	//data from slave

}

void rc522_write(unsigned char reg,unsigned char val)
{
	IOCLR0=1<<7;
	spi_transfer((reg<<1)&0x7E);
	spi_transfer(val);
	IOSET0=1<<7;
}

unsigned char rc522_read(unsigned char reg)
{
	unsigned char val;
	IOCLR0=1<<7;
	spi_transfer(((reg<<1)&0x7e)|0x80);
	val=spi_transfer(0x00);
	IOSET0=1<<7;
	return val;
}


/*************************************************************
* SPI interface code for PIC16F devices
* ADAPTED TO WORK WITH THE ATMEGA8
*
* Provides an interface to the SPI hardware unit. A single 
* buffer is used for both TX and RX. The basic idea is that
* the buffer is loaded with bytes that need to be
* transmitted, then the 'exchange' funtion is called. 
* The bytes are transmitted sequentially and are replaced
* by the bytes that are received from the other device.
* The exchange is handles through the interrupt service
* routine.
*
* (c) 2005, Lieven Hollevoet, boostc compiler.
*************************************************************/

#ifndef _SPI_H_
#define _SPI_H_

#include <avr/io.h>

//outputs:

	#define SPI_SS_DDR DDRB
	#define SPI_SS_BV PB2

	#define SPI_SCK_PORT PORTB
	#define SPI_SCK_DDR DDRB
	#define SPI_SCK_BV PB5

	#define SPI_MOSI_PORT PORTB
	#define SPI_MOSI_DDR DDRB
	#define SPI_MOSI_BV PB3

	#define SPI_CE_PORT PORTD
	#define SPI_CE_DDR DDRD
	#define SPI_CE_BV PD5
	
	#define SPI_CS_PORT PORTD
	#define SPI_CS_DDR DDRD
	#define SPI_CS_BV PD4

//inputs:
	#define SPI_MISO_PORT PINB
	#define SPI_MISO_DDR DDRB
	#define SPI_MISO_BV PB4
	
	#define SPI_IRQ_PORT PINB
	#define SPI_IRQ_DDR DDRD
	#define SPI_IRQ_BV PD3

//macros:
#define SPI_CS_low() SPI_CS_PORT &= ~(1<<SPI_CS_BV);
#define SPI_CS_high() SPI_CS_PORT |= (1<<SPI_CS_BV);




///////////////////////////////////////////////////////////
// Function declarations: the functions are listed written  
// in the code (spi.c).
///////////////////////////////////////////////////////////
void spi_init();
void spi_init_buffer();
void spi_load_byte(unsigned char input);
void spi_exchange(char flag);
unsigned char spi_Read_Write(unsigned char byte);
unsigned char spi_get_byte(char count);
void spi_read_reg (char reg_addr); 

#endif // _SPI_H_

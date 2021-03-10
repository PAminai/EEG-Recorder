// Programmer: Pouya Aminaie
// B.Sc. Project Title: On Design of EEG Remote Monitoring Device for Brain Care
// Shiraz University
// Last Update: March, 2021 
// Description: This is the code for EEG Recordeing via external ADC (MCP3201) 
//              and serial communication via Bluetooth (HC05)

#include <mega8.h>
#include <delay.h>
#include <stdio.h>


// Declare your global variables here

#define DATA_REGISTER_EMPTY (1<<UDRE)
#define RX_COMPLETE (1<<RXC)
#define FRAMING_ERROR (1<<FE)
#define PARITY_ERROR (1<<UPE)
#define DATA_OVERRUN (1<<DOR)


// Write a character to the USART Transmitter
#ifndef _DEBUG_TERMINAL_IO_
#define _ALTERNATE_PUTCHAR_
#pragma used+
void putchar(char c)
{
while ((UCSRA & DATA_REGISTER_EMPTY)==0);
UDR=c;
}
#pragma used-
#endif

// Standard Input/Output functions
#include <stdio.h>


void main(void)
{


// USART initialization
// Communication Parameters: 8 Data, 1 Stop, Even Parity
// USART Receiver: Off
// USART Transmitter: On
// USART Mode: Asynchronous
// USART Baud Rate: 9600 (Double Speed Mode)
UCSRA=(0<<RXC) | (0<<TXC) | (0<<UDRE) | (0<<FE) | (0<<DOR) | (0<<UPE) | (1<<U2X) | (0<<MPCM);
UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (0<<RXEN) | (1<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);
UCSRC=(1<<URSEL) | (0<<UMSEL) | (1<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0) | (0<<UCPOL);
UBRRH=0x00;
UBRRL=0x67;


// SPI initialization
// SPI Type: Master
// SPI Clock Rate: 2*2000.000 kHz
// SPI Clock Phase: Cycle Start
// SPI Clock Polarity: Low
// SPI Data Order: MSB First
SPCR=(1<<SPIE) | (1<<SPE) | (0<<DORD) | (1<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);
SPSR=(1<<SPI2X);

// Clear the SPI interrupt flag
#asm
    in   r30,spsr
    in   r30,spdr
#endasm

// TWI initialization
// TWI disabled
TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | (0<<TWIE);

// Global enable interrupts
#asm("sei")



while (1)
      {      
      
      printf("%f",SPDR);    // SPI Data Reg transmitted to PC via USART (HC05)

      }
}
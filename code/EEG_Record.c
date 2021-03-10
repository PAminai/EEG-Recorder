/* This is the code for EEG Recording via internnal ADC of micro and USB to TTL for serial communication
 * Programmer: Pouya
 */

#include <io.h>
#include <delay.h>
#include <stdio.h>



int a;
//float b;
char buffer[4];

unsigned int read_adc(unsigned char adc_input){
ADMUX=(0<<REFS0)|(0<<REFS1); // External Vref: output of LM385-2.5
ADCSRA=(1<<ADPS2)|(0<<ADPS1)|(1<<ADPS0); // ADC Prescaler = 32, Sampling Freq=250 KHz
ADCSRA=(1<<ADEN);
ADMUX|=adc_input; // Enable ACD0, PC0
ADCSRA|=(1<<ADSC); // Start converting !
while(!(ADCSRA & (1<<ADIF))); // Waiting 
ADCSRA|=(1<<ADIF); // Clearign ADC
return ADCW;
}





void main(void)
{

// USART Initialization
// Parameters: No Parity, 1 Stop bit, 8 bit data
// Receiver: OFF
// Transmitter: ON
// Mode: Syncronous
// B.R.: 9600, UBRR=51
UCSRA= (0<<RXC)|(0<<TXC)|(0<<UDRE)|(0<<FE)|(0<<DOR)|(0<<PE)|(0<<U2X)|(0<<MPCM);
UCSRB= (0<<UCSZ2)|(1<<TXEN)|(0<<RXEN)|(0<<RXCIE)|(0<<TXCIE)|(0<<UDRIE)|(0<<RXB8)|(0<<TXB8);
UCSRC= (1<<UCSZ1)|(1<<UCSZ0)|(0<<UPM1)|(1<<UPM0)|(0<<USBS)|(0<<UMSEL)|(1<<URSEL)|(0<<UCPOL);
UBRRH= 0x00; 
UBRRL= 0x33;


#asm("sei")

while(1){
a=read_adc(0);
sprintf(buffer,"",a);
puts(buffer);
}

}

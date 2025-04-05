#include <avr/io.h>
#include <util/delay.h>

#define FOSC 16000000UL
#define BAUD 115200
#define MYUBBR ((FOSC/16/BAUD)-1)

// serial_init - Initialise the USART port for 8 bit operations
void serial_init(unsigned short ubrr) {
    UBRR0H = (ubrr>>8);
    UBRR0L = ubrr;
    UCSR0B |= (1<<TXEN0); // turn on transmitter
    UCSR0B |= (1<<RXEN0); // turn on receiver
    UCSR0C = (1<<USBS0)|(3<<UCSZ00); // set for async, operation, no parity
    return;
}

// serial_out - output a byte to the USART0 port
void serial_out(char ch) {
    while ((UCSR0A & (1<<UDRE0)));
    UDR0 = ch;
    return;
}


// serial_in - reads a byte from the USART0 port and returns it
char serial_in() {
    while (!(UCSR0A & (1<<RXC0)));
    return UDR0;
}

int string_length(char* str){
    unsigned int len = 0;
    for(; str[len]; len++);
    return len;
}



int main(void) {
    UBRR0H = (MYUBBR >> 8);
    UBRR0L = MYUBBR;

    UCSR0B = (1 << TXEN0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);

    while(1){
        UDR0 = '8';
        _delay_ms(1000);
    }
    return 1;
}
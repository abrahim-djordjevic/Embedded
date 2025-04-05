#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    // set PORTB5 as an output by setting DDB5 on DDRB to 1
    // set register to register and 1 left shifted by register index
    DDRB = DDRB | (1 << DDB5); 
    while(1) 
    {   
        //set PORTB5 to active to turn on LED
        PORTB = PORTB | (1 << PORTB5);
        //wait
        _delay_ms(1000);
        //turn LED off
        PORTB = PORTB & ~(1 << PORTB5);
        _delay_ms(1000);

    }
}
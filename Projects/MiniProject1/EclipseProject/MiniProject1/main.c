/*
 * main.c
 *
 *  Created on: Aug 27, 2020
 *      Author: engmo
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// the state of clock
unsigned char seconds = 0, minutes = 10, hours = 0;


void timer1_init(void) {
	// Enable Timer1

	// Put 15625 in OCR1A so that using 1MHz Clk and 64 prescaler -> Compare match should happen every 1 sec
	OCR1A = 15625;
	TCNT1 = 0;

	// enable Timer1 compare match interrupt
	TIMSK |= (1 << OCIE1A);

	// Set FOC1A/B to 1
	// Choose CTC mode with OCR1A as top
	// Choose 64 prescaler
	TCCR1A = (1 << FOC1A) | (1 << FOC1B);
	TCCR1B = (1 << WGM12) | (1 << CS10) | (1 << CS11);
}

void int0_init(void) {
	// set PD2 (int0) as input pin
	DDRD &= ~(1 << PD2);
	// enable PD2 pull up
	PORTD |= (1 << PD2);

	// set interrupt sense for int0 at falling edges
	MCUCR |= (1 << ISC01);

	// enable int0 interrupts
	GICR |= (1 << INT0);
}

void int1_init(void) {
	// set PD3 (int1) as input pin
	DDRD &= ~(1 << PD3);

	// set interrupt sense for int1 at raising edges
	MCUCR |= (1 << ISC10) | (1 << ISC11);

	// enable int1 interrupts
	GICR |= (1 << INT1);
}

void int2_init(void) {
	// set PB1 (int2) as input pin
	DDRB &= ~(1 << PB1);
	// enable PB1 pull up
	PORTB |= (1 << PB1);

	// set interrupt sense for int2 at falling edges
	MCUCSR &= ~(1 << ISC2);

	// enable int2 interrupts
	GICR |= (1 << INT2);
}

// increment the clock every second if not in pause mode
ISR(TIMER1_COMPA_vect) {
	seconds++;
	if (seconds == 60) {
		seconds = 0;
		minutes++;
		if (minutes == 60) {
			minutes = 0;
			hours++;
			if (hours == 24) {
				hours = 0;
			}
		}
	}
}

// reset the clock
ISR(INT0_vect) {
	// reset the clock state
	seconds = 0;
	minutes = 0;
	hours = 0;

	// and reset the TCNT1 to ensure accurate reset
	TCNT1 = 0;
}

// pause the clock
ISR(INT1_vect) {
	// Disable the Timer1 by stoping the timer clock
	TCCR1B &= ~((1 << CS10) | (1 << CS11) | (1 << CS12));
}

// resume the clock
ISR(INT2_vect) {
	// reenable the timer clock
	// Choose 64 prescaler
	TCCR1B |= (1 << CS10) | (1 << CS11);
}

// a function to display a digit on a 7 seg with address seg
void display_digit(unsigned char digit, unsigned char seg) {
	// put the displayed number on PC0-PC3 without changing other bits
	PORTC = (PORTC & 0xf0) | (digit & 0x0f);

	// put the seg address on PC4-PC6 without changing other bits
	PORTC = (PORTC & 0x8f) | ((seg & 0x07) << 4);

	// wait
	//_delay_ms(1000);
	//PORTC &= ~(1 << PC7);
	//_delay_ms(200);
	//PORTC |= (1 << PC7);
	_delay_us(20);
}

int main (void) {

	// Set PORTC pins PC0-PC6 as outputs
	DDRC |= 0xff;

	// enable interrupts globally
	SREG |= (1 << 7);

	timer1_init();
	int0_init();
	int1_init();
	int2_init();

	while(1) {
		// display seconds
		display_digit(seconds % 10, 0b000);
		display_digit(seconds / 10, 0b001);

		// display minutes
		display_digit(minutes % 10, 0b010);
		display_digit(minutes / 10, 0b011);

		// display hours
		display_digit(hours % 10, 0b100);
		display_digit(hours / 10, 0b101);
	}
}


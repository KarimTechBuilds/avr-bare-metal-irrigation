#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  int dry_threshold = 625; // Set a threshold for dry soil

  ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Enable ADC and set prescaler to 128
  ADMUX = (1 << REFS0); // Use AVcc as reference voltage
    
  DDRB |= (1 << PB0); // Set PB0 as output

  while(1){
    ADCSRA |= (1 << ADSC);

    while(ADCSRA & (1 << ADSC)){

    }; // Wait for any ongoing conversion to finish
    
    int moisture_level= ADC; // Read the ADC value (moisture level)
    if (moisture_level < dry_threshold){
      PORTB |= (1 << PB0); // Turn on the water pump
    } else {
      PORTB &= ~(1 << PB0); // Turn off the water pump

    }



  }
  
  return 0;
}
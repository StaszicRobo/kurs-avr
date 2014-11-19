#include <avr/io.h> //dolaczenie podstawowej biblioteki
#include <avr/interrupt.h> //dolaczenie biblioteki z przerwaniami
#include <util/delay.h> //dolaczenie biblioteki z opóznieniami

int main()
{
     DDRD = 0xFF; //konfiguracja portu jako wyjscia diody podłączone do PD4-PD7
     DDRD &= ~(1<<PD3); //konfiguracja 3 pinu portu D jako wejscie podłączamy przycisk generujący przerwanie 
     PORTD |= (1<<PD3); //ustawienie rezystora podciagajacego
     MCUCR |= (1<<ISC11); //konfiguracja przerwania INT1
     GICR |= (1<<INT1); //wlaczenie przerwania INT1
     sei(); //globalne wlaczenie przerwan
     while(1) //pusta petla
    {
        PORTD= 0b00001000;
        _delay_ms(100);
        PORTD= 0b10001000;
        _delay_ms(1000);
        PORTD= 0b11001000;
        _delay_ms(1000);
        PORTD= 0b11101000;
        _delay_ms(1000);
        PORTD= 0b11111000;
        _delay_ms(1000);
    }
}

SIGNAL(SIG_INTERRUPT1) //poczatek funkcji obslugi przerwania
{
    PORTD = 0x00; 
    _delay_ms(1000); //odczekanie 1s(1000 milisekund)
}

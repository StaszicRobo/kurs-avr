#include <avr/io.h>
#include <avr/interrupt.h> //dolaczenie biblioteki z przerwaniami

void timer_set() //funkcja konfigurujaca timer i porty
{
  TIMSK |= (1<<TOIE0);//wlaczenie przerwania od przepelnienia licznika
  TCCR0 |= (1<<CS00) | (1<<CS01); //ustawienie preskalera na 64
  DDRB = 0xFF;// wszystkie piny portu D jako wyjscia 
}

int main()
{
    timer_set();// wywo³anie funkcji
    sei();  //globalne wlaczenie przerwan
    while(1); //pusta petla 
}

SIGNAL(SIG_OVERFLOW0) //poczatek funkcji obslugi przerwania
{
    PORTD^=0xFF;
}

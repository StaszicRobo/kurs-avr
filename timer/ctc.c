#include <avr/io.h> //dolaczenie podstawowej biblioteki
#include <avr/interrupt.h> //dolaczenie biblioteki z przerwaniami
#include <util/delay.h> //dolaczenie biblioteki z opóznieniami

void timer_set() //funkcja konfigurujaca timer i porty
{
  TIMSK |= (1<<OCIE2);//wlaczenie przerwania compare match
  DDRD = 0xFF;// wszystkie piny portu D jako wyjscia 
  TCCR2 |= (1<<WGM20)  | (1<<CS22) | (1<<COM21);  //wybór trybu CTC ustawienie preskalera na 64
  OCR2 = 100; // wpisanie wartosci do ocr
}

int main()
{
  timer_set();// wywo³anie funkcji
  sei();  //globalne wlaczenie przerwan
  while(1); //pusta petla 
}

ISR(TIMER2_COMP_vect) //poczatek funkcji obslugi przerwania
{
    PORTD^= 0b10101010;
}

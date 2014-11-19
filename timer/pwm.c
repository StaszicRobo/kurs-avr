#include <avr/io.h> //dolaczenie podstawowej biblioteki
#include <util/delay.h>
 
int main() {
  TCCR1A = (1<<COM1A1)|(1<<COM1B1)|(1<<WGM10)|(1<<WGM11);
  //konfiguracja trybu fast PWM 10 bit 
  TCCR1B = (1<<CS10)|(1<<WGM12);
  DDRB = 0xFF; 
  //konfiguracja trybu i prescaler 1 ( nie dzielimy sygnalu zegarowego)
  OCR1A = 0;
  OCR1B = 0;
  //wartosc okreslajaca wspólczynnik wypelnienia
  while(1) {
    OCR1A+=1;
    OCR1B+=1;
    _delay_ms(1);
    if (OCR1A>600) OCR1A=0;
    if (OCR1B>600) OCR1B=0;
  } //diody powinny zmieniac jasonosc s rozna predkoscia
}

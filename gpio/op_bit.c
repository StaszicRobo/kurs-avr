#define F_CPU 1000000L
#include <avr/io.h>
#include <util/delay.h>
 
int main(void)
{
  /* Wszystkie linie portu D będą wyjściami */
  DDRD  = 0xff;
  /* Linia PC0 będzie wejściem z podciągnięciem do VCC */
  DDRC  = 0x00;
  PORTC |= (1<<PC0); 
  PORTC |= (1<<PC1); 
  int sterowanie=0; //zmienna odpowiadająca za aktualnie wykonywaną operację 
  /* Początek nieskończonej pętli */
  while(1)
  {
  /* Jeśli pierwszy przycisk wciśnięty */
    if(!(PINC & (1<<PC0)))
    {
     /* Zwiększenie zmiennej sterującej o 1 */
      sterowanie +=1;
      /* opóżnienie aż drgania na stykach ustaną */
       _delay_ms(80);
    }
  if(sterowanie==0){   // wprowadzenie liczby w systemie binarnym 
    /* Jeśli drugi przycisk wciśnięty */
    if(!(PINC & (1<<PC1)))
    {
     /* Zwiększenie stanu licznika o 1 */
      PORTD +=1;
      /* opóżnienie aż drgania na stykach ustaną */
       _delay_ms(80);
    }
  }
  if(sterowanie==1){  //operator "|" - bitowa alternatywa (OR)
    if(!(PINC & (1<<PC1)))
    {
      PORTD |= 0xf0;  /* ustawia bity nr. 4..7 */
      _delay_ms(80);
    }
  }
  if(sterowanie==2){ //operator "&" - bitowa koniunkcja (AND)
    if(!(PINC & (1<<PC1)))
    {
      PORTD &= 0xaa;  /* zeruje bity nr. 0,2,4,6 */
      _delay_ms(80);
    }
  }
  if(sterowanie==3){ //operator "^" - bitowa alternatywa wykluczająca (XOR)
    if(!(PINC & (1<<PC1)))
    {
      PORTD ^= 0x0f;  /* "odwraca" bity nr. 0..3 */
      _delay_ms(80);
    }
  }
  if(sterowanie==4){ //operator "<<" - przesunięcie w lewo
    if(!(PINC & (1<<PC1)))
    {
      PORTD <<=3;
      _delay_ms(80);
    }
  }
  if(sterowanie==5){ // operator ">>" - przesunięcie w prawo
    if(!(PINC & (1<<PC1)))
    {
      PORTD >>=3;
      _delay_ms(80);
    }
  }
  if(sterowanie==6){ //operator "~" - dopełnienie jedynkowe
    if(!(PINC & (1<<PC1)))
    {
      PORTD =~0xaa;
      _delay_ms(80);
    }
  }
 
  }
}

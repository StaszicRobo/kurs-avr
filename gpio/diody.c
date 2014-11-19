/* 8 diod LED przłączonych do portu D */
/* ATmega8 1MHz */
 
#define F_CPU 1000000L
#include <avr/io.h>
#include <util/delay.h>
 
int main(void)
{   
   /* Wszystkie linie portu D będą wyjściami */
   DDRD = 0xFF;  /* 0xFF binarnie 1111 1111 */
 
   /* Początek nieskończonej pętli */
   while(1)
   {
      PORTD = 0xaa;    /* 0xaa binarnie 1010 1010 */
      /* opóźnienie 0.33 sek. */
      _delay_ms(330); 
       PORTD = 0x55;    /* 0x55 binarnie 0101 0101 */
      /* opóźnienie 0.33 sek. */
      _delay_ms(330);
   }
}

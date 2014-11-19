#define F_CPU 1000000UL
#include<avr/io.h>
#include <util/delay.h>
 
void sspi_init()       
{
    DDRB = ( 1 << PB4 );        //Ustawienie MISO jako wyjście 
    SPCR = ( 1 << SPIE ) | ( 1 << SPE );    //Włączamy przerywania i interfejs SPI
}
 
int main()
{
    sspi_init();
    sei();                //Włączamy przerywania
    for (;;);
    return 0;
}
 
ISR(SPI_STC_vect)            //Kod wykonywany po zgłoszeniu przerywania SPI_STC
{
    char byte = SPDR;        //Pobieramy wartość wysłaną przez Master
}

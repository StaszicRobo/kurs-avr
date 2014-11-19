#define F_CPU 1000000L
#include <avr/io.h>
#include <util/delay.h>

void mspi_init()
{
    DDRB = ( 1 << PB5 ) | ( 1 << PB3 ) | ( 1 << PB2 );  //MOSI, SCK, SS' jako wyjścia chcąc podłączyć więcej urządzeń należy ustawić więcej wyjść pod SS
    SPCR = ( 1 << SPE ) | ( 1 << MSTR ) | ( 1 << SPR1 ) | ( 1 << SPR0 );   //Włączamy SPI, układ Master, najmniejsza częstotliwość SCK fosc / 128 
}                                                                   

void send_spi(char byte)
{
    SPDR = byte;                    //Wysyłamy zawartość zmiennej bajt   
    while( ! bit_is_set( SPSR, SPIF ) );        //Oczekujemy na zakończenie transmisji ( do ustawienia SPIF ) przez sprzęt
}                           
 
int main()
{
    char bajt = 0;
    mspi_init();
    while(1)                //Pętla nieskończona
    {
        send_spi(bajt);
    }
    return 0;
}

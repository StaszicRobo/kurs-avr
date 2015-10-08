#include <avr/io.h> //dołączneie biblioteki obsługi mikrokontrolera


int main() //początek funkcji głównej
{
    DDRD = 0xFF; // ustawienie wszystkich nózek portu D jako wyjscia
    PORTD = 0b0000001; // stan wysoki na nóżce PD0
} // koniec funkcji

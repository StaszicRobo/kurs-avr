/* To jest komentarz
   blokowy. Zajmuje on
   kilka linii */
 
// to jest komentarz liniowy




// FUNKCJA GŁÓWNA //

int main(){
 
// każdy program powinien posiadać funkcję główną instrukcje w niej zawarte 
// są wykonywane podczas działania programu
         
}




// TYPY ZMIENNYCH //

bool                    // 1 bajt przechowuje wartości typu TRUE/FALSE
char                    // 1 bajt liczba 8-bitowa(ASCII)  
unsigned char           // 1 bajt liczba 8-bitowa bez znaku
signed char             // 1 bajt liczba 8-bitowa ze znakiem      
int                     // 2 lub 4 bajty liczba całkowita     
unsigned int            // 2 lub 4 bajty liczba całkowita bez znaku 
short int               // 2 bajty krótka liczba całkowita 
unsigned short int      // 2 bajty krótka liczba całkowita bez znaku 
long int                // 4 lub 8 bajtów długa liczba całkowita      
unsigned long int       // 4 lub 8 bajtów długa liczba całkowita bez znaku 
long long int           // 8 bajtów  bardzo długa liczba całkowita
unsigned long long int  // 8 bajtów  bardzo długa liczba całkowita bez znaku
float                   // 4 bajty liczba zmiennoprzecinkowa 
double                  // 8 bajtów  długa liczba zmiennoprzecinkowa 
long double             // 10, 12 lub 16 bajtów bardzo długa liczba zmiennoprzecinkowa   
void                    // coś i nic
 
typ nazwa; // deklaracja zmiennej 
int liczba; // deklaracja zmiennej o nazwie liczba typu całkowitego
 
 


// STRUKTURY //
 
struct nazwa {
    typ1 nazwa1;
    typ2 nazwa2;
};  //struktura definicja własnego typu zmiennych złożonych we wnętrzu struktury 
    //deklarujemy potrzebne nam zmienne 
 
nazwa kamil; // deklaracja złożonej zmiennej kamil typu nazwa
kamil.nazwa1 = 0; // odwołanie do zmiennej nazwa1. 




// TABLICE //
typ nazwa[liczba];           // tablica jest zmienną złożoną z określonej 
                             // liczby zmiennych tego samego typu.

typ nazwa[liczba1][liczba2]; // Tablice mogą posiadać wiele wymiarów
nazwa[i] = 0;                // odwołanie do i-tego elementu tablicy
nazwa[i][j] = 0;             // odwołanie do elementu tablicy dwuwymiarowej o współrzędnych i,j




// INSTRUKCJA WARUNKOWA //

if (warunek1)          // jeśli spełniony jest warunek zawarty w nawiasie po if  
{                      // (przyjmuje wartość różną od 0) zostaną wykonane instrukcje w nawiasie klamrowym. 
    instrukcja1
} else if(warunek2) {  // drugi warunek, sprawdzany jeżeli pierwszy nie zostanie speniony
    instrukcja2
} else {               // jeżeli żadne z powyższych warunków nie zostaną spełnione 
    instrukcja3        // wykonają się instrukcje zawarte w nawiasie po else (opcjonalnie) 
}




// PĘTLE //

while (warunek){
    instrukcje;
}                 // pętla while wykonuje instrukcje tak długo jak warunek jest spełniony
 
do {
    instrukcje;
} while (warunek); // pętla do while wykonuje instrukcje raz, a potem 
                   // powtarza je jeżeli warunek jest nadal spełniony
 
for (wyrażenie1; wyrażenie2; wyrażenie3){
instrukcja
} //przed piwerszym sprawdzeniem pętli zostanie wykonwne wyrażenie1, następnie 
  //zostanie sprawdzony warunek wtrażenie2, i jeżeli jest on prawdziwy po wykonaniu 
  //obrotu pętli zostanie wykonane wyrżneie3.
   
int x; //przykład 
for (x = 10; x > 0; x--){
instrukcje; 
}//pętla za każdym obrotem zniejsza liczbę x o jeden co po wykonaniu 10 obrotów 
 //doprowadzi do zakończenia jej wykonywania, możemy więc wykonywać ściśle określoną 
 //liczbę obrotów. 

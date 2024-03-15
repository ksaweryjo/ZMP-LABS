// Ksawery Józefowski 277513 zadanie 2a

#include <iostream>
#include <cstdio>

int array[1000] = {}; // Wyzerowanie pamięci tablicy
int var1;

void num_check(){
    int n = 0;
    if (var1 == 1){
        printf("Tak");
        return;
    }
    for (int i = 0; i < var1-1; i++){
        if (array[i] == array[var1-1]){
            n++;
        }
    }
    if (n >= 1){
        printf("Tak\n");
    }
    else {
        printf("Nie\n");
    }
}

int main(){
    /* Nie zauważam sęsu wczytywania ręcznie 1000 liczb więc można określić
    jej rozmiar dla ułatwienia sprawdzania
    chyba, że chodziło o sprawdzanie inputa z pliku, ale wydaje mi się, że powinno
    to być zaznaczone w treści zadania */

    printf("Podaj rozmiar tablicy: ");
    scanf("%d", &var1);
    if (var1 == 0){
        printf("Array is empty");
        return 0;
    }
    for (int i = 0; i < var1; i++){
        printf("Podaj liczbe: ");
        scanf("%d", &array[i]);
    }
    num_check();
    return 0;
}
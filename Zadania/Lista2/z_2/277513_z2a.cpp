// Ksawery Józefowski 277513 zadanie 2a

#include <iostream>
#include <cstdio>

int arr1[1000] = {0}; // Wyzerowanie pamięci tablicy
int var1;

void num_check(){
    int n = 0;
    if (var1 == 1){
        printf("Tak");
        return;
    }
    for (int i = 0; i < var1-1; i++){
        if (arr1[i] == arr1[var1-1]){
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
        std::cerr << "arr1 is empty";
        return 0;
    }
    for (int i = 0; i < var1; i++){
        printf("Podaj liczbe: ");
        scanf("%d", &arr1[i]);
    }
    num_check();
    return 0;
}
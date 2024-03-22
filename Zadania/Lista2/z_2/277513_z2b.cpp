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
        // Dzięki posortowanej tablicy możemy użyć continue,
        // które będzie skipować iteracje jak i możemy dodać drugiego break,
        // aby nie musieć sprawdzać całej tablicy
        if (arr1[i] < arr1[var1-1]){
            if (i == var1-2){
                printf("Nie");
            }
            continue;
        }
        if (arr1[i] > arr1[var1-1]){
            printf("Nie");
            break;
        }
        if (arr1[i] == arr1[var1-1]){
            printf("Tak");
            break;
        }
    }
}

int main(){
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
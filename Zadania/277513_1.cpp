// Ksawery Józefowski 277513 zadanie 1

#include <iostream>
#include <cstdio>

int var1, var2 = 1; // zaczynamy od 1 bo musimy uwzglednić wejściową liczbę

int main (){
    printf("Podaj liczbe: ");
    scanf("%d", &var1);
    printf("\n%d", var1);
    while(var1 != 1) {
        if (var1 % 2 == 0) {
            var1 = var1 / 2;
            var2++;
        } else {
            var1 = var1 * 3 + 1;
            var2++;
        }
        printf(" %d", var1);
    }
    printf(", %d", var2);
    return 0;
}
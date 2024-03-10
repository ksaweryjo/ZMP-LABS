// Ksawery Józefowski 277513 zadanie 3

#include <iostream>
#include <cstdio>

int var1;

// Ilość zer na końcu silni jest uzależniona od ilości 5, które mieszcząsięw liczbie
int zero_count(int n){
    int count = 0;
    for(int i = 5; n/i >= 1; i += 5){
        count++;
    }
    return count;
}

int main(){
    printf("Podaj liczbe: ");
    scanf("%d", &var1);
    printf("\n%d", zero_count(var1));
    return 0;
}
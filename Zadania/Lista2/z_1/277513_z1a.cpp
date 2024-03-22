// Ksawery Józefowski nr 277513 zadanie 1a

#include <iostream>
#include <cstdio>

int var1;

// Liczmy od zera więc wydaje mi się, że 0 powinno być pod indeksem 0
int iter_Fibonacci(int n){
    int a = 0, b = 1, c;
    if (n == 0){
        return 0;
    }
    for(int i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main(){
    printf("Podaj liczbe: ");
    scanf("%d", &var1);
    printf("%d", iter_Fibonacci(var1));
    return 0;
}
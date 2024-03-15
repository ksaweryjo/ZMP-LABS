// Ksawery Józefowski nr 277513 zadanie 1b

#include <iostream>
#include <cstdio>

int var1;

int recursive_Fibonacci(int n){
    if(n == 0){
        return 0;
    }
    else if(n == 1) {
        return 1;
    }
    return recursive_Fibonacci(n-1) + recursive_Fibonacci(n-2);
}

int main(){
    printf("Podaj Liczbe: ");
    scanf("%d", &var1);
    printf("%d", recursive_Fibonacci(var1));
    return 0;
}
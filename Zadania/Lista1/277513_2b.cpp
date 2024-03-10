// Ksawery Józefowski 277513 zadanie 2b

#include <iostream>
#include <cstdio>

int var1;

int gcd(int a, int b) // Największy wspólny dzielnik
{
    int result = std::min(a, b);
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }
    return result;
}

int euler(int n){
    int result = 0;
    for (int i = 1; i < n; i++){
        if (gcd(n, i) == 1){
            result++;
        }
    }
    return std::abs(result); // We wzorze jest abs ale nie wiem czy to jest potrzebne
}

int F_function(int n){
    int result = 0;
    for (int i = 1; i < n; i++){
        if (n % i == 0){
            result += euler(i);
        }
    }
    return result;
}

int main (){
    printf("Podaj liczbe: ");
    scanf("%d", &var1);
    printf("\n%d", F_function(var1));
    return 0;
}
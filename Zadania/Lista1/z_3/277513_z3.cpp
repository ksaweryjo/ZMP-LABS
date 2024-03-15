// Ksawery Józefowski 277513 zadanie 3

#include <iostream>
#include <cstdio>

int var1;

int zero_count(int n) {// Ilość zer na końcu zależna jest od podzielności przez 5 i jej potęg
    int count = 0;
    while (n >= 5) {
        n /= 5;
        count += n;
    }
    return count;
}

int main() {
    scanf("%d", &var1);
    printf("%d", zero_count(var1));
    return 0;
}

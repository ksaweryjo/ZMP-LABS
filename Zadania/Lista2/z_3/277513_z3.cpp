// Ksawery Józefowski nr 277513 zadanie 3

#include <iostream>
#include <cstdio>

bool IsAnagram(char* var1, char* var2) {
    int arr1[255] = {0}; // Zakładam, że użyjemy ASCII,
    // próbowałem z UTF-8, ale i tak ignoruje Polskie znaki
    while (*var1) {
        printf("%d\n", *var1);
        arr1[*var1]++;
        var1++;
    }
    while (*var2) {
        arr1[*var2]--;
        var2++;
    }
    for (int i = 0; i < 255; i++) {
        if (arr1[i] != 0)
            return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    if(argc > 3){
        std::cerr << "Too many arguments";
    }

    if (IsAnagram(argv[1], argv[2])) {
        printf("Tak");
    } else {
        printf("Nie");
    }
    return 0;
}

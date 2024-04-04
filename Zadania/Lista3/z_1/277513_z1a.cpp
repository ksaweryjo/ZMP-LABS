// Ksawery Józefowski nr 277513 zadanie 1a

#include <iostream>
#include <cstdio>

// "Przegrywa gracz, który jest zmuszony wziąć ostatnią zapałkę."
void Game(int matches){
    int p1, p2;
    int temp = 0;
    while (matches > 1) {
        // Player 1
        do {
            if(temp != 0){
                printf("Nielegalny Ruch, Powtorz\n");
            }
            printf("Ruch Gracza nr 1: ");
            scanf("%d", &p1);
            temp++;
        } while (!(p1 >= 1 && p1 <= 3 && p1 <= matches));
        temp = 0;

        matches -= p1;
        if (matches == 1) {
            printf("Gracz nr 2 Przegral");
            break;
        }
        // Jest opcja, żę zostanie 2-3 zapałek i ktoś je wszystkie weźmie
        else if (matches < 1){
            printf("Gracz nr 1 Przegral");
            break;
        }

        // Player 2
        do {
            if(temp != 0){
                printf("Nielegalny Ruch, Powtorz\n");
            }
            printf("Ruch Gracza nr 2: ");
            scanf("%d", &p2);
            temp++;
        } while (!(p2 >= 1 && p2 <= 3 && p2 <= matches));
        temp = 0;

        matches -= p2;
        if (matches == 1) {
            printf("Gracz nr 1 Przegral");
            break;
        }
        else if (matches < 1){
            printf("Gracz nr 2 Przegral");
            break;
        }
        printf("Aktualny stan zapalek: %d\n", matches);
    }
}

int main() {
    int matches;
    printf("Podaj liczbe zapalek: ");
    scanf("%d", &matches);
    Game(matches);
    return 0;
}

// Ksawery Józefowski nr 277513 zadanie 1b

#include <iostream>
#include <cstdio>

// "Przegrywa gracz, który jest zmuszony wziąć ostatnią zapałkę."
// Strategią komputera będzie ustawianie liczby zapałek tak, aby
// Reszta z dzielenia tej liczby przez 4 wynosiła 1.
// Wtedy gracz nie ma szans. To samo tyczy się z komputerem (nie ma na to kontrataku).
void Game(int matches){
    int p1, p2;
    int temp = 0;
    while (matches > 1) {
        // Player
        do {
            if(temp != 0){
                printf("Nielegalny Ruch, Powtorz\n");
            }
            printf("Ruch Gracza: ");
            scanf("%d", &p1);
            temp++;
        } while (!(p1 >= 1 && p1 <= 3 && p1 <= matches));
        temp = 0;

        matches -= p1;
        if (matches == 1) {
            printf("Komputer Przegral");
            break;
        }
        else if (matches < 1){
            printf("Gracz Przegral");
            break;
        }

        // Computer
        switch(matches % 4) {
            case 0:
                p2 = 3;
                break;
            case 1: // W tym przypadku równie dobrze gracz może być zwycięscą
                p2 = 2;
                break;
            case 2:
                p2 = 1;
                break;
            case 3:
                p2 = 2;
                break;
            default:
                printf("Fatal Error");
                break;
        }
        printf("Ruch Komputera: %d\n", p2);

        matches -= p2;
        if (matches == 1) {
            printf("Gracz Przegral");
            break;
        }
        else if (matches < 1){
            printf("Komputer Przegral");
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

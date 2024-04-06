// Ksawery Józefowski nr 277513 zadanie 2

#include <iostream>
#include <cstdio>

void Merger(int LS, int LSS, int RSS, int* source, int* destination) {
    int i = LS, k = LS;
    int j = LSS;

    while (i < LSS && j < RSS) {
        if (source[i] <= source[j]) {
            destination[k] = source[i];
            i++;
        } else {
            destination[k] = source[j];
            j++;
        }
        k++;
    }

    while (i < LSS) {
        destination[k++] = source[i++];
    }

    while (j < RSS) {
        destination[k++] = source[j++];
    }
}

void Sorter(int* data, int size) {
    int* temp = new int[size];

    for (int j = 1; j < size; j *= 2) {
        for (int i = 0; i < size; i += 2 * j) {
            Merger(i, std::min(i + j, size), std::min(i + j * 2, size), data, temp);
        }
        for (int i = 0; i < size; i++) {
            data[i] = temp[i];
        }
    }

    delete[] temp;
}

int main() {
    int size;
    printf("Podaj rozmiar: ");
    scanf("%d", &size);
    int* arr1 = new int[size];

    for (int i = 0; i < size; i++) {
        printf("Podaj wartosc(%d): ", i);
        scanf("%d", &arr1[i]);
    }

    Sorter(arr1, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr1[i]);
    }

    delete[] arr1;

    return 0;
}
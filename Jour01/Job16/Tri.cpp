#include <iostream>
#include <cstring>

using namespace std;

void swap(const char** a, const char** b) {
    const char* temp = *a;
    *a = *b;
    *b = temp;
}

void MySortString(const char* arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (strcmp(arr[j], arr[minIndex]) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

void printArray(const char* arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << endl;
    }
}

int main(void) {
    const char* arr[] = {"Verre", "Cafe", "Sucre", "Souris", "Ordinateur", "Bouteille"};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Tableau avant le tri :" << endl;
    printArray(arr, size);

    MySortString(arr, size);

    cout << "\nTableau apres le tri :" << endl;
    printArray(arr, size);

    return 0;
}
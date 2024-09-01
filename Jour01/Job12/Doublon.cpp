#include <iostream>

using namespace std;

int doubleArray(int* arr, int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        *(arr + i) *= 2;
        sum += *(arr + i);
    }
    return sum;
}

void printArray(int* arr, int size) {
    cout << "Tableau apres avoir double les elements: ";
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int main(void) {

    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int sum = doubleArray(arr, size);

    printArray(arr, size);

    cout << "Somme des elements doubles: " << sum << endl;

    return 0;
}
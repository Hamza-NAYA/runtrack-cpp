#include <iostream>

using namespace std;

void showTable(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int* addElement(int* arr, int& size, int newElement) {
    int* newArr = new int[size + 1];

    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }

    newArr[size] = newElement;

    delete[] arr;

    size++;

    return newArr;
}

int main(void) {
    int* myArray = new int[0];
    int size = 0;

    for (int i = 1; i <= 5; i++){
        myArray = addElement(myArray, size, i);

        cout << "Contenu du tableau : ";
        showTable(myArray, size);
    }

    delete[] myArray;

    return 0;
}
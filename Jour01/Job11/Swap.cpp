#include <iostream>

using namespace std;

void swapValues(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main(void) {
    int x = 10;
    int y = 20;

    cout << "Avant l'echange: x = " << x << ", y = " << y << endl;

    swapValues(x, y);

    cout << "Apres l'echange: x = " << x << ", y = " << y << endl;

    return 0;
}
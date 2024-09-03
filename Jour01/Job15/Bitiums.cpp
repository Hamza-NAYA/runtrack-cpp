#include <iostream>

using namespace std;

bool isBitCountEven(int n) {
    int count = 0;

    while (n != 0) {

        count ^= (n & 1);
        n >>= 1;
    }

    return (count == 0);
}

int main(void) {
    int n = 42;
    if (isBitCountEven(n)) {
        cout << "Le nombre de bits a 1 est pair\n";
    } else {
        cout << "Le nombre de bits a 1 est impair\n";
    }

    return 0;
}
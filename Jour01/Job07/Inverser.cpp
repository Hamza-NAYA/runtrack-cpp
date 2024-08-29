#include <iostream>

using namespace std;

int main(void) {
    int num,  num_inverse = 0, reste;

    cout << "Entrez un nombre : ";
    cin >> num;

    while (num != 0) {
        reste = num % 10;
        num_inverse = num_inverse * 10 + reste;
        num /= 10;
    }

    cout << "Le nombre inverse est : " << num_inverse << endl;

    return 0;
}
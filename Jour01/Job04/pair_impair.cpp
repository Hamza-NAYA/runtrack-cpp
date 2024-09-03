#include <iostream>

using namespace std;

int main(void) {

    int num;

    cout << "Entrez votre entier : ";
    cin >> num;

    if(num % 2 == 0) {
        cout << "L'entier est pair" << endl;
    } else {
        cout << "L'entier est impair" << endl;
    }

    return 0;
}
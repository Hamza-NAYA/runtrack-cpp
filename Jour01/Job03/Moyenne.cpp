#include <iostream>

using namespace std;

int main(void) {

    int num, sum = 0;

    for (int i = 0; i < 5; ++i ) {
        cout << "Entrez vos entiers : ";
        cin >> num;
        sum += num;
    }
    cout << "Le moyenne de vos entiers est : " << sum / 5 << endl;

    return 0;
}
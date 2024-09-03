#include <iostream>

using namespace std;

int main() {
    int n, m, temp;

    cout << "Entrez la valeur de n : ";
    cin >> n;
    cout << "Entrez la valeur de m : ";
    cin >> m;

    cout << "\nAvant l'echange : " << endl;
    cout << "n = " << n << endl;
    cout << "m = " << m << endl;

    temp = n;
    n = m;
    m = temp;

    cout << "\nApres l'echange : " << endl;
    cout << "n = " << n << endl;
    cout << "m = " << m << endl;

    return 0;
}
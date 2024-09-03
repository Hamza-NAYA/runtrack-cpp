#include <iostream>

using namespace std;

int main(void) {

    float num1, num2, produit;

    cout << "Entrez le premier nombre : ";
    cin >> num1;

    cout << "Entrez le second nombre : ";
    cin >> num2;

    produit = num1 * num2;

    cout << "Le produit de vos nombres est : " << produit << endl;

    return 0;
}
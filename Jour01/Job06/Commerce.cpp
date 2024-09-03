#include <iostream>

using namespace std;

int main(void) {

    double prixHT, tva, prixTTC;
    int quantite;

    cout << "Entrez le prix HT d'un kilo de carottes (en euros): ";
    cin >> prixHT;

    cout << "Entrez la quantite de carottes en kilos: ";
    cin >> quantite;

    cout << "Entrez le taux de TVA (en %): ";
    cin >> tva;

    prixTTC = prixHT * (1 + tva / 100) * quantite;

    cout << "Le prix TTC des carottes est de: " << prixTTC << " euros" << endl;

    return 0;
}
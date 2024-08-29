#include <iostream>

using namespace std;


int trouver_minimum(int* tableau, int taille) {
    int min = *tableau;

    for (int i = 1; i < taille; ++i) {
        if (*(tableau + i) < min) {
            min = *(tableau + i);
        }
    }

    return min;
}

int main(void) {
    int tableau[] = {14, 48, 32, 11, 94, 15, 73, 12};
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    int minimum = trouver_minimum(tableau, taille);

    cout << "Le plus petit element du tableau est : " << minimum << endl;

    return 0;
}
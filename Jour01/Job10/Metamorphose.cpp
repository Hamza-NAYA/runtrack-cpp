#include <iostream>

using namespace std;

int trouver_minimum(int** tableau, int taille) {
    int min = **tableau;

    for (int i = 1; i < taille; i++) {
        if (**(tableau + i) < min) {
            min = **(tableau + i);
        }
    }

    return min;
}

int main(void) {
    int a = 14, b = 48, c = 32, d = 11, e = 94, f = 15, g = 73, h = 12;

    int* tableau[] = {&a, &b, &c, &d, &e, &f, &g, &h};
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    int minimum = trouver_minimum(tableau, taille);

    cout << "Le plus petit element du tableau est : " << minimum << endl;

    return 0;
}
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Specialite {
    IA,
    Web,
    Logiciel,
    SystemeImmersif,
    Cybersecurite,
    NBR_SPECIALITES
};

const char* nomSpecialite(Specialite s) {
    switch (s) {
        case IA: return "Intelligence Artificielle";
        case Web: return "Developpement Web";
        case Logiciel: return "Developpement Logiciel";
        case SystemeImmersif: return "Systeme Immersif";
        case Cybersecurite: return "Cybersecurite";
        default: return "Inconnu";
    }
}

void afficherSpecialite(Specialite s, int nbEtudiants) {
    cout << nomSpecialite(s) << " - Nombre d'etudiants : " << nbEtudiants << endl;
}

int main(void) {
    srand(time(0));

    int etudiants[NBR_SPECIALITES];

    for (int i = 0; i < NBR_SPECIALITES; ++i) {
        etudiants[i] = 12 + rand() % 55;
    }

    for (int i = 0; i < NBR_SPECIALITES; ++i) {
        afficherSpecialite(static_cast<Specialite>(i), etudiants[i]);
    }

    return 0;
}
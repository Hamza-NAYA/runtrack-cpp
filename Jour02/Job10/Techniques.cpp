#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <memory>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Aquatique {
protected:
    double vitesseNage;

public:
    Aquatique(double vitesse = 0.0) : vitesseNage(vitesse) {}

    virtual void nage() {
        cout << "L'animal nage a une vitesse de " << vitesseNage << " m/s" << endl;
    }
};

class Terrestre {
protected:
    double vitesseMarche;

public:
    Terrestre(double vitesse = 0.0) : vitesseMarche(vitesse) {}

    virtual void marche() {
        cout << "L'animal marche a une vitesse de " << vitesseMarche << " m/s" << endl;
    }
};

class Pingouin : public Aquatique, public Terrestre {
private:
    string nom;
    double vitesseGlisse;
    multiset<double> tempsGlisseCompetition;

public:
    static vector<shared_ptr<Pingouin>> colonie;
    static list<string> lieuxRencontre;

    Pingouin(string nom, double vitesseNage, double vitesseMarche, double vitesseGlisse)
        : Aquatique(vitesseNage), Terrestre(vitesseMarche), nom(nom), vitesseGlisse(vitesseGlisse) {
        colonie.push_back(shared_ptr<Pingouin>(this));
    }

    ~Pingouin() {
        auto it = find_if(colonie.begin(), colonie.end(),
            [this](const shared_ptr<Pingouin>& p) { return p.get() == this; });
        if (it != colonie.end()) {
            colonie.erase(it);
        }
    }

    void enregistrerTempsGlisse(double temps) {
        tempsGlisseCompetition.insert(temps);
        cout << "Temps de glisse de " << temps << " secondes enregistre pour " << nom << endl;
    }

    void afficherTempsGlisse() const {
        cout << "Temps de glisse de " << nom << " :" << endl;
        for (double temps : tempsGlisseCompetition) {
            cout << "- " << temps << " secondes" << endl;
        }
    }
};

vector<shared_ptr<Pingouin>> Pingouin::colonie;
list<string> Pingouin::lieuxRencontre;

int main() {
    auto p1 = make_shared<Pingouin>("Tux", 2.5, 0.8, 3.2);

    p1->enregistrerTempsGlisse(12.5);
    p1->enregistrerTempsGlisse(10.8);
    p1->enregistrerTempsGlisse(14.2);

    p1->afficherTempsGlisse();

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
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
        cout << "L'animal nage à une vitesse de " << vitesseNage << " m/s" << endl;
    }

    double getVitesseNage() const {
        return vitesseNage;
    }

    void setVitesseNage(double vitesse) {
        vitesseNage = vitesse;
    }
};

class Terrestre {
protected:
    double vitesseMarche;

public:
    Terrestre(double vitesse = 0.0) : vitesseMarche(vitesse) {}

    virtual void marche() {
        cout << "L'animal marche à une vitesse de " << vitesseMarche << " m/s" << endl;
    }

    double getVitesseMarche() const {
        return vitesseMarche;
    }

    void setVitesseMarche(double vitesse) {
        vitesseMarche = vitesse;
    }
};

class Pingouin : public Aquatique, public Terrestre {
private:
    string nom;
    double vitesseGlisse;
    map<string, int> competences;
    set<weak_ptr<Pingouin>, owner_less<weak_ptr<Pingouin>>> amis;
    unordered_map<string, string> journal;
    unordered_set<string> emplacementsNourriture;

public:
    static vector<shared_ptr<Pingouin>> colonie;
    static list<string> lieuxRencontre;

    Pingouin(string nom, double vitesseNage, double vitesseMarche, double vitesseGlisse)
        : Aquatique(vitesseNage), Terrestre(vitesseMarche), nom(nom), vitesseGlisse(vitesseGlisse) {
        colonie.push_back(shared_ptr<Pingouin>(this));
        cout << nom << " a rejoint la colonie" << endl;
    }

    ~Pingouin() {
        auto it = find_if(colonie.begin(), colonie.end(),
            [this](const shared_ptr<Pingouin>& p) { return p.get() == this; });
        if (it != colonie.end()) {
            colonie.erase(it);
            cout << nom << " a quitte la colonie" << endl;
        }
    }

    void ajouterEmplacementNourriture(const string& emplacement) {
        if (emplacementsNourriture.insert(emplacement).second) {
            cout << nom << " a decouvert un nouvel emplacement de nourriture : " << emplacement << endl;
        } else {
            cout << emplacement << " est deja connu de " << nom << endl;
        }
    }

    void retirerEmplacementNourriture(const string& emplacement) {
        if (emplacementsNourriture.erase(emplacement)) {
            cout << "L'emplacement " << emplacement << " a ete retire des lieux de nourriture de " << nom << endl;
        } else {
            cout << "L'emplacement " << emplacement << " n'etait pas connu de " << nom << endl;
        }
    }

    void afficherEmplacementsNourriture() const {
        cout << "Emplacements de nourriture connus par " << nom << " :" << endl;
        for (const auto& lieu : emplacementsNourriture) {
            cout << "- " << lieu << endl;
        }
    }
};

vector<shared_ptr<Pingouin>> Pingouin::colonie;
list<string> Pingouin::lieuxRencontre;

int main() {
    auto p1 = make_shared<Pingouin>("Tux", 2.5, 0.8, 3.2);

    p1->ajouterEmplacementNourriture("Baie des Manchots");
    p1->ajouterEmplacementNourriture("Ile aux poissons");
    p1->ajouterEmplacementNourriture("Baie des Manchots");

    p1->afficherEmplacementsNourriture();

    p1->retirerEmplacementNourriture("Ile aux poissons");
    p1->afficherEmplacementsNourriture();

    return 0;
}

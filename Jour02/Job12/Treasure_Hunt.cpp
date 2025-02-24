#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <memory>
#include <algorithm>
#include <unordered_map>
#include <random>

using namespace std;

class Aquatique {
protected:
    double vitesseNage;

public:
    Aquatique(double vitesse = 0.0) : vitesseNage(vitesse) {}

    virtual void nage() {
        cout << "L'animal nage a une vitesse de " << vitesseNage << " m/s" << endl;
    }

    double getVitesseNage() const { return vitesseNage; }
    void setVitesseNage(double vitesse) { vitesseNage = vitesse; }
};

class Terrestre {
protected:
    double vitesseMarche;

public:
    Terrestre(double vitesse = 0.0) : vitesseMarche(vitesse) {}

    virtual void marche() {
        cout << "L'animal marche a une vitesse de " << vitesseMarche << " m/s" << endl;
    }

    double getVitesseMarche() const { return vitesseMarche; }
    void setVitesseMarche(double vitesse) { vitesseMarche = vitesse; }
};

class Pingouin : public Aquatique, public Terrestre {
private:
    string nom;
    double vitesseGlisse;

public:
    static vector<weak_ptr<Pingouin>> colonie;
    static list<string> lieuxRencontre;
    static unordered_map<string, string> lieuxMeetupPeche;

    Pingouin(string nom, double vitesseNage, double vitesseMarche, double vitesseGlisse)
        : Aquatique(vitesseNage), Terrestre(vitesseMarche), nom(nom), vitesseGlisse(vitesseGlisse) {
        auto ptr = shared_ptr<Pingouin>(this, [](Pingouin*) {});
        colonie.push_back(ptr);
        cout << nom << " a rejoint la colonie" << endl;
    }

    ~Pingouin() {
        auto it = remove_if(colonie.begin(), colonie.end(),
            [this](const weak_ptr<Pingouin>& p) {
                auto sp = p.lock();
                return !sp || sp.get() == this;
            });

        colonie.erase(it, colonie.end());
        cout << nom << " a quitte la colonie" << endl;
    }

    double calculerTempsParcours() const {
        double tempsGlisse = 15.0 / vitesseGlisse;
        double tempsPlat1 = 20.0 / vitesseMarche;
        double tempsNage = 50.0 / vitesseNage;
        double tempsPlat2 = 15.0 / vitesseMarche;
        return tempsGlisse + tempsPlat1 + tempsNage + tempsPlat2;
    }

    static void afficherTempsParcoursColonie() {
        cout << "Temps de parcours pour chaque pingouin :" << endl;
        for (const auto& weakPingouin : colonie) {
            if (auto pingouin = weakPingouin.lock()) {
                cout << "- " << pingouin->nom << " : " << pingouin->calculerTempsParcours() << " secondes" << endl;
            }
        }
    }

    static void ajouterLieuRencontre(const string& lieu) {
        lieuxRencontre.push_back(lieu);
        cout << lieu << " a ete ajoute a la liste des lieux de rencontre" << endl;
    }

    static void retirerLieuRencontre(const string& lieu) {
        auto it = find(lieuxRencontre.begin(), lieuxRencontre.end(), lieu);
        if (it != lieuxRencontre.end()) {
            lieuxRencontre.erase(it);
            cout << lieu << " a ete retire de la liste des lieux de rencontre" << endl;
        } else {
            cout << lieu << " n'existe pas dans la liste des lieux de rencontre" << endl;
        }
    }

    static void afficherLieuxRencontre() {
        cout << "Lieux de rencontre des pingouins :" << endl;
        for (const auto& lieu : lieuxRencontre) {
            cout << "- " << lieu << endl;
        }
    }

    void seRendreAuMeetup(const string& lieu) {
        cout << nom << " se rend au meetup a " << lieu << "..." << endl;

        if (lieuxMeetupPeche.find(lieu) != lieuxMeetupPeche.end()) {
            string lieuPeche = lieuxMeetupPeche[lieu];
            cout << "Ce meetup est proche du lieu de peche : " << lieuPeche << endl;

            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> dist(0, 1);

            if (dist(gen)) {
                cout << nom << " a attrape un poisson a " << lieuPeche << "! " << endl;
            } else {
                cout << nom << " n'a pas eu de chance cette fois-ci... " << endl;
            }
        } else {
            cout << "Ce meetup n'est pas associe a un lieu de peche. " << endl;
        }
    }
};

vector<weak_ptr<Pingouin>> Pingouin::colonie;
list<string> Pingouin::lieuxRencontre;
unordered_map<string, string> Pingouin::lieuxMeetupPeche = {
    {"lac", "Baie des Manchots"},
    {"glacier", "Ile aux Poissons"},
    {"banquise", "Lagune des Poissons"}
};

int main() {
    auto p1 = make_shared<Pingouin>("Tux", 2.5, 0.8, 3.2);
    auto p2 = make_shared<Pingouin>("Pingu", 2.8, 0.9, 3.5);
    auto p3 = make_shared<Pingouin>("Skipper", 3.0, 1.0, 4.0);

    Pingouin::ajouterLieuRencontre("lac");
    Pingouin::ajouterLieuRencontre("glacier");
    Pingouin::ajouterLieuRencontre("banquise");

    Pingouin::afficherLieuxRencontre();

    Pingouin::retirerLieuRencontre("glacier");
    Pingouin::afficherLieuxRencontre();

    cout << "\n--- Deplacements aux Meetups ---\n" << endl;
    p1->seRendreAuMeetup("lac");
    p2->seRendreAuMeetup("banquise");
    p3->seRendreAuMeetup("foret de glace");

    return 0;
}

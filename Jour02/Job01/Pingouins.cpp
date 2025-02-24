#include <iostream>
#include <string>

using namespace std;

class Aquatique {
protected:
    double vitesseNage;

public:
    Aquatique(double vitesse = 0.0) : vitesseNage(vitesse) {}

    virtual void nage() {
        cout << "L'animal nage a une vitesse de " << vitesseNage << " m/s" << endl;
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
        cout << "L'animal marche a une vitesse de " << vitesseMarche << " m/s" << endl;
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

public:
    Pingouin(string nom, double vitesseNage, double vitesseMarche)
        : Aquatique(vitesseNage), Terrestre(vitesseMarche), nom(nom) {}

    void sePresenter() {
        cout << "Bonjour, je suis un pingouin nomme " << nom << endl;
    }

    void nage() override {
        cout << nom << " nage a une vitesse de " << vitesseNage << " m/s" << endl;
    }

    void marche() override {
        cout << nom << " marche a une vitesse de " << vitesseMarche << " m/s" << endl;
    }
};

int main(void) {
    Pingouin p1("Tux", 2.5, 0.8);

    p1.sePresenter();

    p1.nage();

    p1.marche();

    return 0;
}
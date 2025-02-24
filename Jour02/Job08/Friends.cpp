#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <memory>
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

public:
    static vector<shared_ptr<Pingouin>> colonie;
    static list<string> lieuxRencontre;

    Pingouin(string nom, double vitesseNage, double vitesseMarche, double vitesseGlisse)
        : Aquatique(vitesseNage), Terrestre(vitesseMarche), nom(nom), vitesseGlisse(vitesseGlisse) {
        colonie.push_back(shared_ptr<Pingouin>(this));
        sort(colonie.begin(), colonie.end(), [](const shared_ptr<Pingouin>& p1, const shared_ptr<Pingouin>& p2) {
            return p1->calculerTempsParcours() < p2->calculerTempsParcours();
        });
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

    double calculerTempsParcours() const {
        double tempsGlisse = 15.0 / vitesseGlisse;
        double tempsPlat1 = 20.0 / vitesseMarche;
        double tempsNage = 50.0 / vitesseNage;
        double tempsPlat2 = 15.0 / vitesseMarche;
        return tempsGlisse + tempsPlat1 + tempsNage + tempsPlat2;
    }

    static void afficherTempsParcoursColonie() {
        cout << "Temps de parcours pour chaque pingouin :" << endl;
        for (const auto& pingouin : colonie) {
            cout << "- " << pingouin->nom << " : " << pingouin->calculerTempsParcours() << " secondes" << endl;
        }
    }

    static void ajouterLieuRencontre(const string& lieu) {
        lieuxRencontre.push_back(lieu);
        cout << lieu << " a ete ajoute à la liste des lieux de rencontre" << endl;
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

    void ajouterCompetence(const string& nomCompetence, int niveau) {
        competences[nomCompetence] = niveau;
        cout << "Competence " << nomCompetence << " ajoutee avec un niveau de " << niveau << endl;
    }

    void modifierCompetence(const string& nomCompetence, int niveau) {
        auto it = competences.find(nomCompetence);
        if (it != competences.end()) {
            competences[nomCompetence] = niveau;
            cout << "Competence " << nomCompetence << " modifiee au niveau " << niveau << endl;
        } else {
            cout << "Competence " << nomCompetence << " non trouvee" << endl;
        }
    }

    void supprimerCompetence(const string& nomCompetence) {
        auto it = competences.find(nomCompetence);
        if (it != competences.end()) {
            competences.erase(it);
            cout << "Competence " << nomCompetence << " supprimee" << endl;
        } else {
            cout << "Competence " << nomCompetence << " non trouvee" << endl;
        }
    }

    void listerCompetences() const {
    cout << "Competences de " << nom << " :" << endl;
    for (const auto& entry : competences) {
        cout << "- " << entry.first << " : niveau " << entry.second << endl;
        }
    }

    void ajouterAmi(shared_ptr<Pingouin> ami) {
        if (ami.get() != this) {
            amis.insert(ami);
            cout << nom << " a ajoute " << ami->nom << " comme ami" << endl;
        } else {
            cout << nom << " ne peut pas être son propre ami" << endl;
        }
    }

    void retirerAmi(shared_ptr<Pingouin> ami) {
        auto it = amis.find(ami);
        if (it != amis.end()) {
            amis.erase(it);
            cout << nom << " a retire " << ami->nom << " de ses amis" << endl;
        } else {
            cout << ami->nom << " n'est pas un ami de " << nom << endl;
        }
    }

    void listerAmis() const {
        cout << "Amis de " << nom << " :" << endl;
        for (const auto& weakAmi : amis) {
            if (auto ami = weakAmi.lock()) {
                cout << "- " << ami->nom << endl;
            }
        }
    }
};

vector<shared_ptr<Pingouin>> Pingouin::colonie;
list<string> Pingouin::lieuxRencontre;

int main() {
    auto p1 = make_shared<Pingouin>("Tux", 2.5, 0.8, 3.2);
    auto p2 = make_shared<Pingouin>("Pingu", 2.8, 0.9, 3.5);
    auto p3 = make_shared<Pingouin>("Skipper", 3.0, 1.0, 4.0);

    p1->ajouterAmi(p2);
    p1->ajouterAmi(p3);
    p2->ajouterAmi(p1);

    p1->listerAmis();
    p2->listerAmis();

    p1->retirerAmi(p3);
    p1->listerAmis();

    return 0;
}
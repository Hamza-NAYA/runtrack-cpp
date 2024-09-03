#include <iostream>

using namespace std;

int main(void){
    int i, n, c, sum = 0;

    cout << "Entrez un nombre : ";
    cin >> n;

    for(i = 5; i <= n; i++){
        c = i * i * i;
        sum += c;
        cout << "Le cube de " << i << " est : " << c << endl;
    }
    cout << "La somme des cubes de 5^3 a " << n << "^3 est " << sum << endl;
    return 0;
}
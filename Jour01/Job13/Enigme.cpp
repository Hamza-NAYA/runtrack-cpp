#include <iostream>
#include <bitset>

using namespace std;

constexpr unsigned long long fibonacci(int n) {
    return (n <= 1) ? n : (fibonacci(n - 1) + fibonacci(n - 2));
}

bool hasEvenOnes(uint32_t n) {
    return (bitset<32>(n).count() % 2 == 0);
}

int main(void) {

    cout << "Les 10 premiers termes de la suite de Fibonacci :" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "Fibonacci(" << i << ") = " << fibonacci(i) << endl;
    }

    uint32_t num = 21;

    if (hasEvenOnes(num)) {
        cout << "Le nombre " << num << " a un nombre pair de bits a 1." << endl;
    } else {
        cout << "Le nombre " << num << " a un nombre impair de bits a 1." << endl;
    }

    return 0;
}
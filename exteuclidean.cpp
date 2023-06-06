#include <iostream>

using namespace std;

int extendedEuclidean(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedEuclidean(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}
int modInverse(int a, int m) {
    int x, y;
    int gcd = extendedEuclidean(a, m, x, y);

    if (gcd != 1) {
        cout << "The modular multiplicative inverse does not exist." << endl;
        return -1;
    }

    int inverse = (x % m + m) % m;
    return inverse;
}


int main() {
    int number, modulus;

    cout << "Enter the number: ";
    cin >> number;
    cout << "Enter the modulus: ";
    cin >> modulus;

    int inverse = modInverse(number, modulus);
    if (inverse != -1) {
        cout << "The modular multiplicative inverse of " << number << " modulo " << modulus << " is: " << inverse << endl;
    }

    return 0;
}

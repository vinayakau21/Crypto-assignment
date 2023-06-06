#include <iostream>
#include <cmath>

long long modPow(long long base, long long exponent, long long modulus) {
    if (modulus == 1) {
        return 0;
    }

    long long result = 1;
    base = base % modulus;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }

        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }

    return result;
}

long long generateSymmetricKey(long long g, long long p, long long x, long long y) {
    long long public_key_A = modPow(g, x, p);
    long long public_key_B = modPow(g, y, p);

    long long shared_secret_A = modPow(public_key_B, x, p);
    long long shared_secret_B = modPow(public_key_A, y, p);

    if (shared_secret_A == shared_secret_B) {
        return shared_secret_A;
    } else {
        std::cerr << "Error: Symmetric key generation failed." << std::endl;
        return -1;
    }
}

int main() {
    long long g, p, x, y;

    std::cout << "Enter the value of g: ";
    std::cin >> g;

    std::cout << "Enter the value of p: ";
    std::cin >> p;

    std::cout << "Enter the private key for Alice (x): ";
    std::cin >> x;

    std::cout << "Enter the private key for Bob (y): ";
    std::cin >> y;

    long long symmetric_key = generateSymmetricKey(g, p, x, y);

    if (symmetric_key != -1) {
        std::cout << "Symmetric key generated is: " << symmetric_key << std::endl;
    }

    return 0;
}

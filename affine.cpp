#include <iostream>
#include <string>
using namespace std;

bool isCoprime(int num) {
    for (int i = 2; i < num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int findModInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1; 
}

string encrypt(string plaintext, int keyA, int keyB) {
    string ciphertext = "";
    for (int i = 0; i < plaintext.length(); i++) {
        if (isalpha(plaintext[i])) {
            char ch = islower(plaintext[i]) ? 'a' : 'A';
            int x = plaintext[i] - ch;
            int y = (keyA * x + keyB) % 26;
            ciphertext += static_cast<char>(y + ch);
        } else {
            ciphertext += plaintext[i];
        }
    }
    return ciphertext;
}

string decrypt(string ciphertext, int keyA, int keyB) {
    string plaintext = "";
    int modInverse = findModInverse(keyA, 26);
    for (int i = 0; i < ciphertext.length(); i++) {
        if (isalpha(ciphertext[i])) {
            char ch = islower(ciphertext[i]) ? 'a' : 'A';
            int x = ciphertext[i] - ch;
            int y = (modInverse * (x - keyB + 26)) % 26;
            plaintext += static_cast<char>(y + ch);
        } else {
            plaintext += ciphertext[i];
        }
    }
    return plaintext;
}

int main() {
    int keyA, keyB;
    string plaintext;

    cout << "Enter key A: ";
    cin >> keyA;
    cout << "Enter key B: ";
    cin >> keyB;
    cout << "Enter plaintext: ";
    cin.ignore();
    getline(cin, plaintext);

    if (!isCoprime(keyA)) {
        cout << "Key A is not coprime with 26. Please choose a different key." << endl;
        return 0;
    }

    string ciphertext = encrypt(plaintext, keyA, keyB);
    cout << "Ciphertext: " << ciphertext << endl;

    string decryptedText = decrypt(ciphertext, keyA, keyB);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
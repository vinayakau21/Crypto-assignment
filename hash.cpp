#include <iostream>
#include <string>
#include <functional>

using namespace std;

string computeHash(const string& message) {
    hash<string> hasher;
    size_t hashValue = hasher(message);
    return to_string(hashValue);
}

int main() {
    string originalMessage;
    string receivedMessage;

    cout << "Enter the original message: ";
    getline(cin, originalMessage);

    string originalHash = computeHash(originalMessage);

    cout << "Original Message: " << originalMessage << endl;
    cout << "Original Hash: " << originalHash << endl;

    cout<<"Simulating a receiver..."<<endl;
    cout << "Enter the received message: ";
    getline(cin, receivedMessage);
    string receivedHash = computeHash(receivedMessage);

    cout << "Received Message: " << receivedMessage << endl;
    cout << "Received Hash: " << receivedHash << endl;

    if (originalHash == receivedHash) {
        cout << "Message integrity verified. The hash matches." << endl;
    } else {
        cout << "Message integrity check failed. The hash does not match." << endl;
    }

    return 0;
}

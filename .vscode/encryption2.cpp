#include <bits/stdc++.h>
using namespace std;

class Cipher {
public:
    virtual string encrypt(const string& message, int shift) = 0;
    virtual string decrypt(const string& message, int shift) = 0;

    virtual ~Cipher() {}
};

class CaesarCipher : public Cipher {
public:
    CaesarCipher() {}

    string encrypt(const string& message, int shift) override {
        string encryptedMessage = "";
        for (char ch : message) {
            if (isalpha(ch)) {
                char base = islower(ch) ? 'a' : 'A';
                char encryptedChar = (ch - base + shift + 26) % 26 + base;
                encryptedMessage += encryptedChar;
            } else {
                encryptedMessage += ch;
            }
        }
        return encryptedMessage;
    }

    string decrypt(const string& message, int shift) override {
        string decryptedMessage = "";
        for (char ch : message) {
            if (isalpha(ch)) {
                char base = islower(ch) ? 'a' : 'A';
                char decryptedChar = (ch - base - shift + 26) % 26 + base;
                decryptedMessage += decryptedChar;
            } else {
                decryptedMessage += ch;
            }
        }
        return decryptedMessage;
    }

    ~CaesarCipher() {}
};

int main() {
    int shiftAmount;
    string message;
    char direction;

    cout << "Enter the shift amount: ";
    cin >> shiftAmount;
    cin.ignore();

    cout << "Enter 'F' for forward shift or 'B' for backward shift: ";
    cin >> direction;
    cin.ignore();

    cout << "Enter the message: ";
    getline(cin, message);

    Cipher* cipher = new CaesarCipher();

    if (toupper(direction) == 'B') {
        shiftAmount = -shiftAmount;
    }

    string encryptedMessage = cipher->encrypt(message, shiftAmount);
    cout << "Encrypted message: " << encryptedMessage << endl;

    string decryptedMessage = cipher->decrypt(encryptedMessage, shiftAmount);
    cout << "Decrypted message: " << decryptedMessage << endl;

    delete cipher;

    return 0;
}

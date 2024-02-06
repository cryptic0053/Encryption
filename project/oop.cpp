#include <bits/stdc++.h>
using namespace std;
class Cipher {
public:
    virtual string encrypt(const string& message) = 0;
    virtual string decrypt(const string& message) = 0;
};
class CaesarCipher : public Cipher {
private:
    int shift;
public:
    CaesarCipher(int shiftAmount) : shift(shiftAmount) {}
    string encrypt(const string& message) override {
        string encryptedMessage = "";
        for (char ch : message) {
            if (isalpha(ch)) {
                char encryptedChar = (toupper(ch) - 'A' + shift) % 26 + 'A';
                encryptedMessage += encryptedChar;
            } else {
                encryptedMessage += ch;
            }
        }
        return encryptedMessage;
    }
      string decrypt(const string& message) override {
        string decryptedMessage = "";
        for (char ch : message) {
            if (isalpha(ch)) {
                char decryptedChar = (toupper(ch) - 'A' - shift + 26) % 26 + 'A';
                decryptedMessage += decryptedChar;
            } else {
                decryptedMessage += ch;
            }
        }
        return decryptedMessage;
    }
};

int main() {
    int shiftAmount;
    string message;

    cout << "Enter the shift amount: ";
    cin >> shiftAmount;
    cin.ignore();

    cout << "Enter the message: ";
    getline(cin, message);

    Cipher* cipher = new CaesarCipher(shiftAmount);

    string encryptedMessage = cipher->encrypt(message);
    cout << "Encrypted message: " << encryptedMessage << std::endl;

  
    string decryptedMessage = cipher->decrypt(encryptedMessage);
    cout << "Decrypted message: " << decryptedMessage << std::endl;

    delete cipher;

    return 0;
}

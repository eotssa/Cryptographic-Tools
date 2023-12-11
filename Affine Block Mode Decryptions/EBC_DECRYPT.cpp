#include <iostream>
#include <vector>
using namespace std;

// ECB mode decryption using Affine Cipher
vector<char> ecb_dec(vector<string> encryptedBlocks) {
    vector<char> xs; 
    int key = 8; // key is in decimal form, 0x08 in hexadecimal

    // Iterate over each element in encryptedBlocks
    for (int i = 0; i < encryptedBlocks.size(); i++) {
        // Convert the hex string to an int
        int hexToInt = stoi(encryptedBlocks[i], nullptr, 16); 
        // Perform decryption using affine decryption formula
        int affineDecrypt = (163 * (hexToInt - key)) % 256;
        // Convert int to char
        char intToChar = static_cast<char>(affineDecrypt); 
        // Append the char to xs
        xs.push_back(intToChar);
        cout << "encryptedBlock: " << encryptedBlocks[i] << endl;
        cout << "hexToInt: " << hexToInt << endl;
        cout << "affineDecrypt: " << affineDecrypt << endl;
        cout << "intToChar: " << intToChar << endl;
    }
    return xs;
}

int main() {
    // cipher_ecb is the vector that contains the hexadecimal representation of the ciphertext
    vector<string> cipher_ecb  = {"0XEE", "0X33", "0X49", "0X5F", "0x54"};
    // call the ecb_dec function and pass the cipher_ecb vector to it
    vector<char> ps_ecb = ecb_dec(cipher_ecb);
    // print the decrypted plaintext
    cout << "\nECB decryption: ";
    for (char c : ps_ecb) {
        cout << c;
    }
    cout << endl;
    return 0;
}

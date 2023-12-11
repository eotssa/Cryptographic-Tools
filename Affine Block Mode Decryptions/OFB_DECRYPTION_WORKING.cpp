#include <iostream>
#include <vector>
using namespace std;



// CBC mode decryption using Affine Cipher
vector<char> ofb_dec(vector<string> encryptedBlocks) {
    vector<char> xs; // vector to store the decrypted plaintext
    int iv = 170; // hardcoded /0XAA
    int key = 8;
    //int iv = stoi("0XAA", nullptr, 16); // Initialization Vector, used to xor with the first block of ciphertext
    //int key = stoi("0X08", nullptr, 16); // Key, used in the decryption algorithm
    
    // IV and key are added to block cipher ENCRYPTION (block = iv) here
    unsigned char s = (key + 11 * iv) % 256; // initial value CFB mode (take encrypted block = iv, and key inputs)
    int p = (stoi(encryptedBlocks[0], nullptr, 16) ^ s); //block cipher is XOR'd with encryption output 's'
    char intToChar = static_cast<char>(p);
    xs.push_back(intToChar);

    //cout << "What is s: " << s << endl;
    //cout << "What is p: " << p << endl;
    //cout << "What is inToChar: " << intToChar << endl; 

    for (int i = 1; i < encryptedBlocks.size(); i++) {
        s = (key + 11 * s % 256);
        int p = (stoi(encryptedBlocks[i], nullptr, 16) ^ s);
        char intToChar = static_cast<char>(p);
        xs.push_back(intToChar); // add the decrypted first block to the plaintext vector
        //s = (key + 11 * s) % 256;
        //s = (163*(stoi(encryptedBlocks[i-1], nullptr, 16) + key)) % 256;
    }
    
    return xs;
}

int main() {
    vector<string> cipher_ofb  = {"0X3A", "0XDb", "0X65", "0X2F", "0x52"}; //vector of hexadecimal representation of ciphertext
    vector<char> ofb_decX = ofb_dec(cipher_ofb); // calls the ofb_dec function to decrypt the ciphertext
    cout << "\nCBC decryption: ";
    for (auto c : ofb_decX) {
        cout << c; //print the decrypted plaintext
    }
    cout << endl;
    return 0;
}

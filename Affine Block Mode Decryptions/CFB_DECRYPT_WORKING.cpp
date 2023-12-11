#include <iostream>
#include <vector>
using namespace std;



// CBC mode decryption using Affine Cipher
vector<char> cfb_dec(vector<string> encryptedBlocks) {
    vector<char> xs; // vector to store the decrypted plaintext
    int iv = 170; // hardcoded /0XAA
    int key = 8;
    //int iv = stoi("0XAA", nullptr, 16); // Initialization Vector, used to xor with the first block of ciphertext
    //int key = stoi("0X08", nullptr, 16); // Key, used in the decryption algorithm
    
    // return (163*(block-key+256))%256;
    //1. Added 'iv' to the key and decryption. 
    unsigned char s = (key + 11 * iv) % 256; // initial value CFB mode (take encrypted block = iv, and key inputs)
    int p = (stoi(encryptedBlocks[0], nullptr, 16) ^ s);
    char intToChar = static_cast<char>(p);
    xs.push_back(intToChar);

    //cout << "What is s: " << s << endl;
    //cout << "What is p: " << p << endl;
    //cout << "What is inToChar: " << intToChar << endl; 

    for (int i = 1; i < encryptedBlocks.size(); i++) {
        unsigned char s = (key + 11 * stoi(encryptedBlocks[i - 1], nullptr, 16) % 256);
        int p = (stoi(encryptedBlocks[i], nullptr, 16) ^ s);
        char intToChar = static_cast<char>(p);
        xs.push_back(intToChar); // add the decrypted first block to the plaintext vector
        s = (char)((163 * (stoi(encryptedBlocks[i-1], nullptr, 16) - key + 256)) % 256);
    }
    
    return xs;
}

int main() {
    vector<string> cipher_cfb  = {"0X3B", "0XF0", "0X3B", "0XF4", "0xE0"}; //vector of hexadecimal representation of ciphertext
    vector<char> cfb_decX = cfb_dec(cipher_cfb); // calls the cfb_dec function to decrypt the ciphertext
    cout << "\nCBC decryption: ";
    for (auto c : cfb_decX) {
        cout << c; //print the decrypted plaintext
    }
    cout << endl;
    return 0;
}

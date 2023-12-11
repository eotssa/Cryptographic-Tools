#include <iostream>
#include <string>
#include <vector>

using namespace std;

// CBC mode decryption using Affine Cipher
vector<char> cbc_dec(vector<string> encryptedBlocks) {
    vector<char> xs; // vector to store the decrypted plaintext
    int iv = stoi("0XAA", nullptr, 16); // Initialization Vector, used to xor with the first block of ciphertext
    int key = stoi("0X08", nullptr, 16); // Key, used in the decryption algorithm
    
    //1. Uses affine decryption first with key.
    //2. XOR affine decryption output with 'iv' -- this will return out plaintext, which we append into 'xs'
    char x0 = (char)(((163 * (stoi(encryptedBlocks[0], nullptr, 16) - key)) % 256) ^ iv); //decrypt the first block of ciphertext
    xs.push_back(x0); // add the decrypted first block to the plaintext vector
   
    //1. Use affine decryption with encryptedBlocks[i] + key
    //2. XOR affine decryption output NOT with 'iv' this time, but rather, the previous ciphertext. 
    for (int i = 1; i < encryptedBlocks.size(); i++) {
        char xi = (char)(((163 * (stoi(encryptedBlocks[i], nullptr, 16) - key)) % 256) ^ stoi(encryptedBlocks[i-1], nullptr, 16)); //decrypt the current block by xor-ing with the previous block
        xs.push_back(xi); // add the decrypted block to the plaintext vector
    }
    return xs;
}

int main() {
    vector<string> cipher_cbc  = {"0X66", "0X55", "0X5A", "0XBD", "0x5B"}; //vector of hexadecimal representation of ciphertext
    vector<char> ps_cbc = cbc_dec(cipher_cbc); // calls the cbc_dec function to decrypt the ciphertext
    cout << "\nCBC decryption: ";
    for (auto c : ps_cbc) {
        cout << c; //print the decrypted plaintext
    }
    cout << endl;
    return 0;
}

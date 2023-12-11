#include <iostream>
#include <string>
#include <fstream> 
#include <streambuf>
using namespace std;

//Affine cypher decryption without knowing the initial 'a' or 'b' values in f(c) = ax + b


string Affine_Decrypt(string txt, int aInverse, int b) {

    string temp = "";

    for (int i = 0; i < txt.size(); i++) {
        char ch = txt.at(i);

        ch = ch - 'A'; 
        ch = ((aInverse * (ch - b)) % 26);

        // makeshift modulo operation because trouble with negative modulo operations
        while (ch < 0) { ch += 26; }

        ch = ch + 'A';
        
        temp += ch;  
   
    }

    return temp; 

}

int main()
{
    // create file variables
    ifstream file;
    file.open("3d2680ae_ae.txt");

    if (!file.is_open()) {
        cout << "Error opening input file \n" ;
        return 1;
    }

    //file iterator that points to the beginning, and char iterator that points to end()
    string encryptedText((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    
    file.close(); 

    //Calls Affine_Decrypt, parameters can be determined either via brute force or plaintext attack
    //NOTE: parameter 'a' is the modulo 26 inverse of the original encryption key for 'a'
    string plainText = Affine_Decrypt(encryptedText, 11, 7);

    cout << plainText << '\n'; 

    return 0;

}

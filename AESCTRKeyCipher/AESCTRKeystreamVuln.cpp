#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bitset>

using namespace std;

vector<char> readFileToVec(const string& fileName) {
    ifstream file(fileName, ios::binary);
    vector<char> file_text((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();    
    return file_text;
}

vector<char> stringToVec(const string& str) {
    return vector<char>(str.begin(), str.end());
}

bool isBinaryFile(const string& str) {
    return str.size() > 4 && str.substr(str.size() - 4) == ".bin";
}

vector<char> XORVecs(vector<char> vec1, vector<char> vec2) {
    int size = min(vec1.size(), vec2.size());
    vector<char> resultXOR(size, 0);
    for (int i = 0; i < size; i++) {
        resultXOR.at(i) = (vec1.at(i) ^ vec2.at(i));
    }
    return resultXOR;
}

vector<bitset<8>> charToBinary (vector<char> vecCharXOR) {
    vector<bitset<8>> binary_Vector;
    for (int i = 0; i < vecCharXOR.size(); i++) {
        binary_Vector.push_back(bitset<8>(vecCharXOR[i]));
    }
    return binary_Vector;
}

vector<int> findSpace_Positions(vector<bitset<8>> bitsetData) {
    vector<int> positions(bitsetData.size(), 0); 
    for (int i = 0; i < bitsetData.size(); ++i) {
        bitset<8> bit = bitsetData[i];
        if (bit.test(6)) {
            positions.at(i) = 1;
    }
        else {
            positions.at(i) = 0; 
        }
    }
    return positions; 
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <file1/bin_string1> <file2/bin_string2>\n";
        return 1;
    }

    vector<char> input1, input2;
    for (int i = 1; i <= 2; i++) {
        string arg(argv[i]);
        if (isBinaryFile(arg)) {
            (i == 1 ? input1 : input2) = readFileToVec(arg);
        } else {
            (i == 1 ? input1 : input2) = stringToVec(arg);
        }
    }

    // XOR input1 with input2
    vector<char> xorResult = XORVecs(input1, input2);

    // Converts XOR'd result into bits
    vector<bitset<8>> xorResultBitset = charToBinary(xorResult);

    // Finds positions of 'space'
    vector<int> positions = findSpace_Positions(xorResultBitset);

    vector<char> decryptedPlainText(input1.size(), 0);
    for (int i = 0; i < input1.size(); i++) {
        if (positions.at(i) == 1) {
            decryptedPlainText.at(i) = (input1.at(i) ^ ' ') ^ input2.at(i);
        } else {
            decryptedPlainText.at(i) = ' ';
        }
    }

    // Print out decrypted text
    for (char c : decryptedPlainText) {
        cout << c;
    }

    return 0;
}



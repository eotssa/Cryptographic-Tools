# AES-CTR Keystream Decryption Tool

## Overview

This tool is specifically designed to decrypt AES-CTR encryptions when two different ciphertexts are encrypted using the same keystream. It features a self-developed unique algorithm. 

## How to Use

```bash
g++ -o decrypt_aes_ctr decrypt_aes_ctr.cpp
```

This command compiles the source code into an executable named `decrypt_aes_ctr`.

### Running the Tool

To run the tool, use the following command format:

```bash
./decrypt_aes_ctr <file1/bin_string1> <file2/bin_string2>
```

- `<file1/bin_string1>`: This can be either a binary file (with a `.bin` extension) or a string.
- `<file2/bin_string2>`: This is the second input, which can also be either a binary file or a string.

### Decryption Process

2. **XOR Operation**: It performs an XOR operation between the two inputs. This is based on the principle that XORing two ciphertexts encrypted with the same keystream can reveal patterns.

3. **Exploiting the 6th Bit Heuristic**: The tool uses the heuristic that in ASCII encoding, the 6th bit of a space character (' ') is always set. This knowledge is used to identify potential spaces in the XORed result, which helps in revealing parts of the plaintext.

### Output

The more files you have with the same keystream, the more of the plaintext you'll be able to generate. Even with one other cipher text, you'll be able to reasonably deduce file contents with are encrypted with AES. 



# Vigenère Cipher Decryption Tool

 C++ tool designed for decrypting texts encrypted using the Vigenère cipher. It's particularly useful when the key length is unknown, as it includes functionality to brute-force potential key lengths and manually inspect the results for the correct decryption.

## Features
- **Automatic Key Length Detection:** The tool can try different key lengths up to a specified limit, facilitating the decryption process when the key length is unknown.
- **Frequency Analysis:** Implements frequency analysis in the function `getVE_key` to derive potential keys based on the encrypted text.
- **Decryption:** Once a key is determined, the `VE_Decrypt` function is used to decrypt the text.

## How to Use

2. **Preparing Your Encrypted Text:**
   - Place your encrypted text in a file named `e12e9445_ve.txt` in the same directory as the program. 
   - Compile and run.

# Affine Block Mode Decryptions

C++ implementation of the Affine Cipher with different block cipher modes, including CBC, CFB, ECB, and OFB.

## How to use
- Change the `cipher_xxx` variable in the main function with their respective hexadecimal values.
- Compile and run

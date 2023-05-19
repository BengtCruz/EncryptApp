/**
 * @file main.c
 * @author Bengt Svedling Cruz (bengtsvedling@hotmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <AesManager.h>

int main()
{
    unsigned char key[16] = "0123456789abcdef";
    unsigned char plaintext[16] = "Hello, OpenSSL!";

    printf("Plaintext: ");
    for (int i = 0; i < 16; i++) {
        printf("%c", plaintext[i]);
    }
    printf("\n");
    
    unsigned char *cypher = AesManager_Encrypt(plaintext, key);
    
    for (int i = 0; i < 16; i++) {
        printf("%02x", cypher[i]);
    }
    printf("\n");

    unsigned char *decypher = AesManager_Decrypt(cypher, key);

    printf("Decyphertext: ");
    for (int i = 0; i < 16; i++) {
        printf("%c", decypher[i]);
    }

    printf("\n");

    return 0;
}
/**
 * @file AesManager.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/aes.h>

#define AES_BLOCK_SIZE 16

unsigned char *AesManager_Encrypt(const unsigned char *plaintext, const unsigned char *key)
{
    // Allocate memory for the ciphertext
    unsigned char *ciphertext = malloc(strlen(plaintext) + 1);
    if (ciphertext == NULL) 
        // Handle memory allocation failure
        return NULL;
    

    // or (if you want to allocate it on the heap)
    // unsigned char *ciphertext = malloc(strlen(plaintext) + 1);

    // Initialize the AES key
    AES_KEY aes_key;

    // Set the encryption key
    AES_set_encrypt_key(key, 128, &aes_key);

    // Encrypt the input string
    AES_encrypt(plaintext, ciphertext, &aes_key);

    return ciphertext;
}

unsigned char *AesManager_Decrypt(const unsigned char *ciphertext, const unsigned char *key)
{
    // Allocate memory for the decrypted string
    unsigned char *plaintext = malloc(strlen(ciphertext));
    if(plaintext == NULL)
        return NULL;

    // Initialize the AES key
    AES_KEY aes_key;

    // Set the decryption key
    AES_set_decrypt_key(key, 128, &aes_key);

    // Decrypt the ciphertext
    AES_decrypt(ciphertext, plaintext, &aes_key);

    return plaintext;
}
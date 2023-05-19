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
#include <aes.h>

#define AES_BLOCK_SIZE 16

char *AesManager_Encrypt(const unsigned char *plaintext, const unsigned char *key)
{
    // Initialize the AES library
    struct AES_ctx ctx;
    AES_init_ctx(&ctx, key);

    // Encrypt the input string
    AES_ECB_encrypt(&ctx, plaintext);

    // Copy the encrypted string to the output string
    char *output = malloc(strlen(plaintext) + 1);
    strcpy(output, input);

    return output;
}

char *AesManager_Decrypt(const unsigned char *ciphertext, const unsigned char *key)
{
    // Initialize the AES library
    struct AES_ctx ctx;
    AES_init_ctx(&ctx, key);

    // Decrypt the input string
    AES_ECB_decrypt(&ctx, ciphertext);

    // Copy the decrypted string to the output string
    char *output = malloc(strlen(ciphertext) + 1);
    strcpy(output, input);

    return output;
}
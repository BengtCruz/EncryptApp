/**
 * @file AesManager.h
 * @author Bengt Svedling Cruz (bengtsvedling@hotmail.com)
 * @brief AES manager module that interfaces with OpenSSL library
 * for simple encrypting and decrypting operations using AES encryption.
 * @version 0.1
 * @date 2023-05-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef AESMANAGER_H
#define AESMANAGER_H

/**
 * @brief 
 * 
 * @param plaintext to encrypt.
 * @param key, 16 AES block key.
 * @return unsigned char*, encrypted plaintext.
 */
unsigned char *AesManager_Encrypt(const unsigned char *plaintext, const unsigned char *key);

/**
 * @brief 
 * 
 * @param ciphertext to ecrypt.
 * @param key, 16 AES block key.
 * @return unsigned char*, decrypted ciphertext.
 */
unsigned char *AesManager_Decrypt(const unsigned char *ciphertext, const unsigned char *key);


#endif
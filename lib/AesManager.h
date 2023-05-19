/**
 * @file AesManager.h
 * @author your name (you@domain.com)
 * @brief 
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
 * @param plaintext 
 * @param key 
 * @return char* 
 */
char *AesManager_Encrypt(const unsigned char *plaintext, const unsigned char *key);

/**
 * @brief 
 * 
 * @param ciphertext 
 * @param key 
 * @return char* 
 */
char *AesManager_Decrypt(const unsigned char *ciphertext, const unsigned char *key);


#endif
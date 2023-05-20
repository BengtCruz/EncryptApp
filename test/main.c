#include <stdio.h>
#include <string.h>
#include "AesManager.h"
#include "unity.h"

void setUp()
{
    // Set up any initialization required for the tests
}

void tearDown()
{
    // Clean up any resources allocated during the tests
}

void testEncryptDecrypt()
{
    const unsigned char *plaintext = "Hello, World!";
    const unsigned char *key = "0123456789abcdef";

    // Encrypt plaintext
    unsigned char *ciphertext = AesManager_Encrypt(plaintext, key);
    TEST_ASSERT_NOT_NULL(ciphertext);

    // Decrypt cipher
    unsigned char *decrypted = AesManager_Decrypt(ciphertext, key);
    TEST_ASSERT_NOT_NULL(decrypted);

    // Compare plaintext with decrypted text.
    TEST_ASSERT_EQUAL_STRING(plaintext, decrypted);

    // Free and clean memory
    free(ciphertext);
    free(decrypted);
}

int main()
{
    UNITY_BEGIN();
    
    RUN_TEST(testEncryptionDecryption);
    
    UNITY_END();
    
    return 0;
}
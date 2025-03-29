#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIXED_KEY "osproject1234567" 

// XOR Encrypt/Decrypt function
void xorEncryptDecrypt(char *message, const char *key, char *output) {
    int msgLen = strlen(message);
    int keyLen = strlen(key);

    for (int i = 0; i < msgLen; i++) {
        output[i] = message[i] ^ key[i % keyLen];  // XOR with key
    }
    output[msgLen] = '\0'; 
}

int main() {
    char *message;
    char *encrypted;
    char *decrypted;
    char userKey[17]; 
    int maxLen;

    // message length input
    printf("Enter the length of your message: ");
    scanf("%d", &maxLen);
    getchar(); 

    // Allocate memory dynamically
    message = (char *)malloc(maxLen + 1);
    encrypted = (char *)malloc(maxLen + 1);
    decrypted = (char *)malloc(maxLen + 1);

    if (!message || !encrypted || !decrypted) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input message
    printf("Enter a message: ");
    fgets(message, maxLen + 1, stdin);
    message[strcspn(message, "\n")] = '\0'; 

    // Encrypt the message
    xorEncryptDecrypt(message, FIXED_KEY, encrypted);
    printf("\n🔹 Message Encrypted Successfully!\n");

    // Ask for decryption key
    printf("\nEnter a 16-character key to decrypt: ");
    fgets(userKey, 17, stdin);
    userKey[strcspn(userKey, "\n")] = '\0'; // Remove newline

    // Validate key
    if (strcmp(userKey, FIXED_KEY) == 0) {
        xorEncryptDecrypt(encrypted, FIXED_KEY, decrypted);
        printf("\n Correct key! \n Decrypted message: %s\n", decrypted);
    } else {
        printf("\n Incorrect key! Decryption failed.\n");
    }

    // Free allocated memory
    free(message);
    free(encrypted);
    free(decrypted);

    return 0;
}

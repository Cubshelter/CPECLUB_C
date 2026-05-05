#include <stdio.h>

int main() {
    char message[100];
    int key, choice;
    char *ptr;

    printf("--- Simple Cipher Tool ---\n");
    printf("1. Encrypt\n2. Decrypt\nSelect: ");
    scanf("%d", &choice);

    printf("Enter message (one word): ");
    scanf("%s", message);

    printf("Enter key (1-10): ");
    scanf("%d", &key);

    // Initialize the pointer to the start of the string
    ptr = message;

    if (choice == 1) {
        // ENCRYPTION LOOP
        while (*ptr != '\0') {
            *ptr = *ptr + key; // Shift forward
            ptr++;
        }
        printf("Encrypted: %s\n", message);
    } 
    else if (choice == 2) {
        // DECRYPTION LOOP
        while (*ptr != '\0') {
            *ptr = *ptr - key; // Shift backward
            ptr++;
        }
        printf("Decrypted: %s\n", message);
    }

    return 0;
}

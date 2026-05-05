#include <stdio.h>
#include <string.h>

// Step 1: The Blueprint
struct Contact {
    char name[50];
    char phone[15];
};

// Step 4: The Pointer Challenge (Function using Arrow ->)
void displayContact(struct Contact *ptr) {
    printf("Name: %-15s | Phone: %-15s\n", ptr->name, ptr->phone);
}

int main() {
    struct Contact phonebook[5];
    int count = 0;
    int choice;

    // Step 2: The Shell Loop
    while(1) {
        printf("\n--- Phonebook Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Exit\n");
        printf("Select option: ");
        
        // The space before %d clears the "Enter" key from memory
        if (scanf(" %d", &choice) != 1) break; 

        if (choice == 3) {
            printf("Exiting Phonebook. Goodbye!\n");
            break;
        }

        switch(choice) {
            case 1:
                if (count < 5) {
                    printf("Enter Name (No spaces): ");
                    scanf("%s", phonebook[count].name);
                    
                    printf("Enter Phone: ");
                    scanf("%s", phonebook[count].phone);
                    
                    count++;
                    printf(">>> Contact saved!\n");
                } else {
                    printf("!!! Error: Phonebook Full\n");
                }
                break;

            case 2:
                if (count == 0) {
                    printf("Phonebook is empty.\n");
                } else {
                    printf("\n--- Current Contacts ---\n");
                    for(int i = 0; i < count; i++) {
                        // Passing the ADDRESS (&) to the pointer function
                        displayContact(&phonebook[i]);
                    }
                }
                break;

            default:
                printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}

#include <stdio.h>

// The container for a single network packet
struct Packet {
    int serialNo;
    int priority;
};

int main() {
    // setting up the structure
    printf("Firewall Structure Initialized...\n");
   
    
    // Create a 'filing cabinet' for 10 packets
    struct Packet packets[10];
    
     // Adding the packets
    packets[0].serialNo = 1;
    packets[0].priority = 5;

    // Highest Priority
    packets[1].serialNo = 10;
    packets[1].priority = 1;

    printf("Packets loaded into memory.\n");
    printf("First Packet Serial: %d, Priority: %d\n", packets[0].serialNo, packets[0].priority);

   
    int i;
    
    printf("--- Mini Firewall Input ---\n");
    
    for(i = 0; i < 10; i++) {
        printf("Enter SerialNo and Priority (e.g., 1 5) for Packet %d: ", i + 1);
        
        scanf("%d %d", &packets[i].serialNo, &packets[i].priority);
    }

    printf("\nAll 10 packets received. Ready for filtering.\n");


    // Sorting by Priority
    struct Packet temp; // Our temporary holding chair
    int j;

    for (i = 0; i < 10 - 1; i++) {
        for (j = 0; j < 10 - i - 1; j++) {
            
            // Compare Priorities (Lower number = Higher Priority)
            if (packets[j].priority > packets[j + 1].priority) {
                // Swap them!
                temp = packets[j];
                packets[j] = packets[j + 1];
                packets[j + 1] = temp;
            }
        }
    }
    
        // To sort it
    for (i = 0; i < 10 - 1; i++) {
        for (j = 0; j < 10 - i - 1; j++) {
           
            int swapNeeded = 0;

            // Swap if the next packet has a higher priority (smaller number)
            if (packets[j].priority > packets[j + 1].priority) {
                swapNeeded = 1;
            } 
            // If priorities are EQUAL, check the Serial Number (Tie-breaker)
            else if (packets[j].priority == packets[j + 1].priority) {
                if (packets[j].serialNo > packets[j + 1].serialNo) {
                    swapNeeded = 1;
                }
            }

            // If either rule was met, perform the swap using our "holding chair" (temp)
            if (swapNeeded) {
                temp = packets[j];
                packets[j] = packets[j + 1];
                packets[j + 1] = temp;
            }
        }
    }
            
            int swapNeeded = 0;

            // Rule 1: Priority check (Lower number = Higher Importance)
            if (packets[j].priority > packets[j + 1].priority) {
                swapNeeded = 1;
            } 
            // Rule 2: Tie-breaker (If priorities are equal, check Serial Number)
            else if (packets[j].priority == packets[j + 1].priority) {
                if (packets[j].serialNo > packets[j + 1].serialNo) {
                    swapNeeded = 1;
                }
            }

            // Perform the swap if needed
            if (swapNeeded) {
                temp = packets[j];
                packets[j] = packets[j + 1];
                packets[j + 1] = temp;
            }
            // --- OUTPUT SECTION ---
    printf("\n--- Firewall Output (Sorted Packets) ---\n");
    printf("RANK\tSERIAL\tPRIORITY\n");
    for(i = 0; i < 10; i++) {
        // \t creates a "Tab" space to keep columns neat
        printf("%d.\t%d\t%d\n", i + 1, packets[i].serialNo, packets[i].priority);
    }

    


    return 0;

};


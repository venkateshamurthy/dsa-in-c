#include <stdio.h>
#include <stdbool.h>
#define SIZE 6


int arr[SIZE] = {0};   // Hash table array
int flag[SIZE]= {0};  // Flag array to mark filled slots

int main() {

    int num, loc, i, j;
    // Input records
    for (i = 0; i < SIZE; i++) {
        printf("Enter record %d: ", i + 1);scanf("%d", &num);

        // Calculate hash location
        loc = num % SIZE;

        // Check for collision
        if (flag[loc] == false) {
            arr[loc] = num;
            flag[loc] = true;
            printf("Stored at address %d\n", loc);
        } else {
            printf("Collision detected at address %d, trying next slot.\n", loc);

            // Resolve collision using linear probing
            j = loc;
            while (flag[++j % SIZE] == true) ;

            arr[j % SIZE] = num;
            flag[j % SIZE] = true;
            printf("Stored at address %d\n", j % SIZE);
        }
   }


    // Display hash table content
    printf("\nThe Hash Table Content is:\n");
    for (i = 0; i < SIZE; i++) {
        if (flag[i] == true) {
            printf("Address %d: %d\n", i, arr[i]);
        } else {
            printf("Address %d: ##\n", i);
        }
    }
}

#include <stdio.h>
#include <stdbool.h>
#define SIZE 6


int arr[SIZE] = {0};   // Hash table array
int flag[SIZE]= {0};  // Flag array to mark filled slots

int main() {

    int num, loc, i, j;
    // Input records
    for (i = 0; i < SIZE; i++) {
        //Enter data
        printf("Enter record %d: ", i + 1);
        scanf("%d", &num);

        // Calculate hash location
        loc = num % SIZE;

        // Check for collision
        if ( ! flag[loc]) {
            arr[loc] = num;
            flag[loc] = true;
            printf("Stored at address %d\n", loc);
        } else {
            j    = loc + 1;            // start from next location
            printf("Collision detected at address %d, trying next slot.\n", j);

            // Resolve collision using linear probing
            while (flag[j % SIZE])  // keep moving till you find a false
                j++;

            arr[j % SIZE] = num;    // store num at  j%SIZE
            flag[j % SIZE] = true;  // store true at j%SIZE
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
/*
Address 0: 90
Address 1: 1
Address 2: 2
Address 3: 9
Address 4: 10
Address 5: 17
*/
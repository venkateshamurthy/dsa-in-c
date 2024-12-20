#include <stdio.h>
#include <stdbool.h>
#define SIZE 10

int arr[SIZE] = {0};   // Hash table array
int flag[SIZE]= {0};  // Flag array to mark filled slots
void store_number (int num);

int main() {
    printf("Hashmap program of SIZE:%d\n", SIZE);
    printf("--------------------------\n");
    int num, loc, i;
    // Input records
    for (i = 0; i < SIZE; i++) {
        //Enter data
        printf("Enter record %d (of %d): ", i + 1, SIZE);
        scanf("%d", &num);
        store_number(num);
        /*
        // Calculate hash location
        loc = num % SIZE;

        // Check for collision
        if ( ! flag[loc]) {            // No collision
            arr[loc] = num;            // so store num in arr[loc]
            flag[loc] = true;          // mark flag[loc] = true to indicate occupied
            printf("Stored at address %d\n", loc);
        } else {                       // Collision detected
            printf("Collision detected at address %d, trying next slot from.\n", loc);

            // Resolve collision using linear probing
            while (flag[++loc % SIZE])  // keep moving till you find a flag[loc%SIZE]=false
                 ; //Do nothing

            arr[loc % SIZE] = num;    // store num at  j%SIZE
            flag[loc % SIZE] = true;  // store true at j%SIZE
            printf("Stored at address %d\n", loc % SIZE);
        }
        */
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

// Store the number to has table
void store_number (int num) {
    // Calculate hash location
    int loc = num % SIZE;

    // Check for collision
    if ( ! flag[loc]) {            // No collision
        arr[loc] = num;            // so store num in arr[loc]
        flag[loc] = true;          // mark flag[loc] = true to indicate occupied
        printf("Stored at address %d\n", loc);
    } else {                       // Collision detected
        printf("Collision detected at address %d, trying next slot from.\n", loc);

        // Resolve collision using linear probing
        while (flag[++loc % SIZE])  // keep moving till you find a flag[loc%SIZE]=false
        /** DO NOTHING */  ;

        arr[loc % SIZE] = num;    // store num at  j%SIZE
        flag[loc % SIZE] = true;  // store true at j%SIZE
        printf("Stored at address %d\n", loc % SIZE);
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

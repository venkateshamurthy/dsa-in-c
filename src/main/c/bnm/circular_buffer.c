#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 5
/*
   -1 0 1 2 3 4
     | | | | | |
          r f
*/
int a[MAX], f = 0, r = -1, count = 0;

void insert (int item) {
    //r = (r + 1) % MAX;
    //a[r] = item;
    a[++r % MAX] = item;
    count++;
}

void display () {
    int i = f, cnt = count;
    while(cnt-- > 0) printf("%d ", a[i++ % MAX]);
    printf("\n");
}

int delete() {
    //int item = a[f];
    //f = (f + 1) % MAX;
    int item = a[f++ % MAX];
    count--;
    return item;
}

int main() {
    int ch, item;
    while (1) {
        printf("Enter choices: 1. Insert 2. Delete  3. Display 4. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1 /* Insert*/:
                    if (count == MAX)
                        printf("Overflow. So cannot add further\n");
                    else {
                        printf("Enter the item to insert: ");
                        scanf("%d", &item);
                        insert(item);
                   }
                    break;
            case 2/* Delete*/:
                    if (count == 0)
                        printf("Underflow. No elements to delete\n");
                    else {
                        item = delete();
                        printf("Deleted item: %d\n", item);
                    }
                    break;
            case 3 /* Display*/:
                    if (count == 0)
                        printf("Underflow. No elements to display\n");
                    else
                        display();
                    break;
            case 4: exit(0);
            default:printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
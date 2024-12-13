#include <stdio.h>

int heap[100];
int size;

void swap(int a, int b) {
   int temp = heap[a];
   heap[a] = heap[b];
   heap[b] = temp;
}

void heapify_down(int index){
   int largest = index;
   int left = 2 * index + 1;
   int right = 2 * index + 2;

   if (left < size && heap[left] > heap[largest])
         largest = left;

   if (right < size && heap[right] > heap[largest])
         largest = right;

  if (largest != index) {
       swap(index, largest);
       heapify_down(largest);
   }
}

void build_max_heap(){
   for (int i = (size/2) - 1 ; i >= 0; i--)
         heapify_down( i);
}

void print_array() {
   printf("Max Heap: ");
   for (int i = 0; i < size; i++)
         printf("%d ", heap[i]);
   printf("\n");
}


int main() {
   //Receive Input
   printf("Enter the number of elements: "); scanf("%d", &size);
   printf("Enter the elements: ");
   for (int i = 0; i < size; i++) scanf("%d", &heap[i]);

   //Execute Max Heap
   build_max_heap();

   //Print output
   print_array();
}
 /*
OUTPUT:
Enter the number of elements: 8
Enter the elements: 45 36 54 27 63 72 61 18
Max Heap: 72 63 61 27 36 54 45 18

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include "name.h"
#include "node.h"
#include "iterator.h"
#define node_name(args...) node_make((data_creator)&name_make,3,args)



int main() {
    node * vn = node_name("Vydya","Narayana",19);
    node * yn = node_link(vn, node_name("Yajna","Narayana",24));
    node * vm = node_link(yn, node_name("Venkat","Murthy", 54));
    node * ik = node_link(vm, node_name("Indumathi","Kale",49));

    node_display_recursive(vn, (data_to_string)&name_to_string);

    printf("Size of linked list:%d\n", node_size(vn));

    node_display_iterative(vn, (data_to_string)&name_to_string);

    node_free(vn,    (free_up)&name_free);
} 

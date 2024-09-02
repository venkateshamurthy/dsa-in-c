#ifndef _NODE_HEADER_H_
#define _NODE_HEADER_H_
#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>
#include "utils.h"

typedef struct _node {
    void * data; 
    struct _node * next;
} node;

//Creation functions
node * node_data (data_creator dc, int n,  ...);
node * node_va_data (data_creator dc, int n,  va_list* ap);
node * node_last(node * root);

// Display functions
void   node_display(node * n, const char* context, data_to_string stringer);
void   node_display_recursive(node * n, data_to_string stringer);
void   node_display_iterative(node * n, data_to_string stringer);

//List functions
int    node_size(node * n) ;
void   node_free(node * n,  free_up free_er);
node * detect_loop_in_linkedlist(node * head, bool break_free_loop);

//Common data typed linked list creation functions
#define node_ints(count, args...)  node_data((data_creator)&va_arg_int_ptr, count, args)
#define node_strings( count, args...)  node_data((data_creator)&va_arg_string, count, args)
#endif /*_NODE_HEADER_H_*/


#ifndef _NODE_HEADER_H_
#define _NODE_HEADER_H_
#include <stdarg.h>
#include <stddef.h>

typedef struct _node {
    void * data; 
    struct _node * next;
} node;

typedef void   (*free_up)(void * ptr);
typedef char * (*data_to_string)(void * data);
typedef void * (*data_creator)(va_list ap);

node * node_make (data_creator dc, int n,  ...);
node * node_link( node * p, node *c);
void   node_display(node * n, const char* context, data_to_string stringer);
void   node_display_recursive(node * n, data_to_string stringer);
void   node_display_iterative(node * n, data_to_string stringer);
int    node_size(node * n) ;
void   node_free(node * n,  free_up free_er);
#endif /*_NODE_HEADER_H_*/


#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__
#include "person.h"
#include <stdarg.h>
#include <stdbool.h>

typedef struct _ll {
    void       * data;
    struct _ll * next;
} ll;

/* Head of singly linked list*/
extern ll * head;

/* Typedefs. */
typedef void        (*free_data)(void * ptr);
typedef char *      (*to_string)(void * data);
typedef ll   *      (*node_fabricator)(va_list ap, int count);
typedef ll   *      (*node_maker)(void * data);
typedef bool        (*equalizer)(void * expected, void * actual);

/* CRUD operations */
ll * ll_from_va     (node_fabricator fa, int count, ...);
ll * ll_append      (ll * appending_node);
ll * ll_prepend     (ll * prepending_node);
ll * ll_remove      (ll * removing_node, free_data free_er);
ll * ll_insert      (ll * current, ll * to_be_inserted);
void ll_free        (ll * node, free_data free_er);

/* Display  operations*/
void ll_display     (ll * node, char * context, to_string tos);
void ll_display_all (char * context, to_string tos);
void ll_display_iterate(ll * node, char * ctxt, to_string tos);


/* Problem Solving */
ll * ll_detect_loop (const ll * node, bool break_free_loop);
int  sizeof_ll      (const ll * node);
ll * ll_last        (const ll * node);
ll * ll_middle      (const ll * node);
ll * ll_last_n      (const ll * node, int nth_node_from_last);
#endif






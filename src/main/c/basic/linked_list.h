#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__
#include "person.h"
#include <stdarg.h>
#include <stdbool.h>

typedef struct _ll {
    void       * data;
    struct _ll * next;
} ll;

typedef void        (*free_data)(void * ptr);
typedef char *      (*to_string)(void * data);
typedef ll   *      (*node_fabricator)(va_list ap, int count);

void ll_free        (ll * head, free_data free_er);
void ll_display     (ll * head, char * context, to_string tos);
void ll_display_iterate(ll * head, char * context, to_string tos);
ll * ll_from_va     (node_fabricator fa, int count, ...);

ll * ll_insert      (ll * current, ll * to_be_inserted);
ll * ll_last        (const ll * head);
ll * ll_middle      (const ll * head);
ll * ll_last_n      (const ll * head, int nth_node_from_last);
int  sizeof_ll      (const ll * head);
ll * ll_detect_loop (const ll * head, bool break_free_loop);
#endif






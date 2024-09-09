#include "linked_list.h"

int * int_dup        (int data) ;
int * int_ptr_dup    (int* data) ;
void  free_int       (int * p);
ll *  ll_int         (int data) ;
ll *  ll_ints        (int count, int data[]) ;
void  ll_ints_display(ll* head) ;
void  ll_ints_free   (ll * p);
char * int_to_string (void * data);
ll   * ll_ints_va    (va_list ap, int count);
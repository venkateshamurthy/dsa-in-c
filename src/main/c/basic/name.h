#include <stdarg.h>

/* Structure to hold name & age. */
typedef struct _name {
    char * first;
    char * last;
    int age;
} name;

name * name_dup         (const name   p);

/* Stringifier */
char * name_ptr_display (name * n);

/* Free Memory */
void   name_free(name * n);

/* Create Name. */
name * name_create(const char * f, const char * l, int ag);

/* 
   A va (variable argument) list comprising instances of name truct
   after reading va_list.
*/
name * name_va_create( va_list ap);

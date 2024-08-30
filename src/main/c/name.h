#include <stdarg.h>

/* Structure to hold name & age. */
typedef struct _name {
    char * first;
    char * last;
    int age;
} name;

/* Stringifier */
char * name_to_string (name * n);

/* Free Memory */
void   name_free(name * n);

/* Create */
name * name_create(const char * f, const char * l, int ag);

/* 
   A va (variable argument) list comprising different args.
   This makes use of name_create after reading va_list.
*/
name * name_make( va_list ap);

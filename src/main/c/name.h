#include <stdarg.h>



typedef struct _name {
    char * first;
    char * last;
    int age;
} name;
char * name_to_string (name * n);
void name_free(name * n);
name * name_create(const char * f, const char * l, int ag);
name * name_make( va_list ap);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

typedef struct _name {
    char * first;
    char * last;
    int age;
} name;

char * name_to_string (name * n) {
   char * ret = malloc(strlen(n -> first) + 1 +
                       strlen(n -> last) +  1 +
                       1 +
                       sizeof(int));
   if (ret != NULL) {
     sprintf(ret, "%s %s %d", n -> first, n -> last, n -> age);
     return ret;
   }
   return NULL;
}

void name_free(name * n) {
    printf("Deleting..Name:%s\n", name_to_string(n));
    free(n->first);
    free(n->last);
    free(n);
}

name * name_create(const char * f, const char * l, int ag){
    name * n = (name *) malloc(sizeof(name));
    n -> first = string_allocate(f);
    n -> last =  string_allocate(l);
    n -> age = ag;
    return n;
}

name * name_make( va_list* ap) {
    return name_create (
       va_arg(*ap, char*),
       va_arg(*ap, char*),
       va_arg(*ap, int)
    );
}
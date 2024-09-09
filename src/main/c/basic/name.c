#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>
#include "name.h"


name* name_va_create(va_list ap) {
    name * n = name_create(
        va_arg(ap, char *),
        va_arg(ap, char *),
        va_arg(ap, int));
    return n;
}

char * name_ptr_display (name * n) {
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
    printf("Deleting..Name:%s\n", name_ptr_display(n));
    free(n -> first);
    free(n -> last);
    free(n);
}

name * name_create(const char * f, const char * l, int ag){
    name * n = (name *) malloc(sizeof(name));
    n -> first = strdup(f);
    n -> last =  strdup(l);
    n -> age = ag;
    return n;
}

name * name_dup(const name p) {
    return name_create(p.first, p.last, p.age);
}
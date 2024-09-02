#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"
#include "address.h"

/* A address to string conversion function. Required for printing/displaying*/
char * address_to_string (address * n) {
   char * ret = malloc(strlen(n -> home)  +  1 +
                       strlen(n -> phone) +  1 +
                       strlen(n -> email) +  1 );
   if (ret != NULL) {
     sprintf(ret, "%s\n%s\n%s", n -> home, n -> phone, n -> email);
   }
   return ret;
}

/* A memory de-allocator function that frees insider fields before clean=ing up the self.*/
void address_free(address * n) {
    printf("Deleting..Address:%s\n", address_to_string(n));
    free(n->home);
    free(n->phone);
    free(n->email);
    free(n);
}

/* An address creator with all the fields as parameters passed.*/
address * address_create(const char * home, const char * phone, const char * email){
    address * n = (address *) malloc(sizeof(address));
    n -> home = string_allocate(home);
    n -> phone = string_allocate(phone);
    n -> email = string_allocate(email);
    return n;
}

/* An address maker when var args are passed.*/
address * address_make( va_list* ap) {
    return address_create (
       va_arg(*ap, char*),
       va_arg(*ap, char*),
       va_arg(*ap, char*)
    );
}


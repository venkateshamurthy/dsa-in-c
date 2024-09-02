#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

typedef struct _address {
    char * home;
    char * phone;
    char * email;
} address;

char * address_to_string (address * n) ;

void address_free(address * n);

address * address_create(const char * home, const char * phone, const char * email);

address * address_make( va_list* ap);
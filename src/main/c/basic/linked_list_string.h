#include "linked_list.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

ll * ll_string          (const char * data);
ll * ll_strings         (int count, const char * data[]);
void ll_strings_display (ll* head);
void free_string        (char * p);
void ll_strings_free    (ll* p);
char * string_to_string (void * data);
ll   * ll_strings_va    (va_list ap, int count);
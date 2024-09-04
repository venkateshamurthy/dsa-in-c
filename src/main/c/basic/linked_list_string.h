#include "linked_list.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

ll * ll_string (const char * data);
ll * ll_strings(int count, const char * data[]);
void ll_strings_display (ll* head);
void free_string(char * p);
void ll_strings_free( ll* p);
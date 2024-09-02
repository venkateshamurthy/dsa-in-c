#include <stdarg.h>
int    va_arg_int(va_list ap);
int  * va_arg_int_ptr(va_list ap);
char * va_arg_string(va_list ap);

char * itos (void *number);
char * string_to_string (void * data);
int * int_allocate(int data);
void free_int (int*p);
char * string_allocate(const char * data);
void free_string(char *p);

typedef void   (*free_up)(void * ptr);
typedef char * (*data_to_string)(void * data);
typedef void * (*data_creator)(va_list* ap);
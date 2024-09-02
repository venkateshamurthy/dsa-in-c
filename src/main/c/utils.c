#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

char buffer[20];

char * itos (void *number) {
    buffer[0] = '\0';
    sprintf(buffer, "%d", *((int*)number));
    return buffer;
}

char * string_to_string (void * data) {
    return (char*) data;
}

int * int_allocate(int data) {
    int * p = (int*) malloc(sizeof(int));
    memcpy(p, (int*)&data, sizeof(int));
    return p;
}
void free_int(int * p) { free(p);}

char * string_allocate(const char * data) {
    char * copy = (char*) malloc((1 + strlen(data)) * sizeof(char));
    strcpy(copy, data);
    return copy;
}
void free_string(char * p) {free(p);}

int   *  va_arg_int_ptr(va_list* ap)   { int data = va_arg(*ap, int);return int_allocate(data);}
char  *  va_arg_string(va_list* ap)    { const char* data = va_arg(*ap, char*); return string_allocate(data);}

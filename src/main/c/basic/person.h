#ifndef __PERSON_H__
#define __PERSON_H__
#include <stdarg.h>
#define person_make(args...) person_va_create(5, args)

typedef enum _gender {MALE, FEMALE} gender;

typedef struct _person {
    char *  name;
    int     age;
    gender  gender;
    char *  phone;
    char *  address;
} person;

person   person_va_create   (int   count, ...);
person * person_dup         (const person   p);
person * person_ptr_dup     (const person * p);
void     free_person        (person * p);
char*    person_display     (person p);
char*    person_ptr_display (person* p);
#endif
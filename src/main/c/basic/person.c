#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
person person_va_create(int count, ...) {
    va_list ap;
    va_start (ap, count);

    person p;
    p.name   = strdup(va_arg(ap, char *));
    p.age    = va_arg(ap, int);
    p.gender = va_arg(ap, gender);
    p.phone  = strdup(va_arg(ap, char *));
    p.address= strdup(va_arg(ap, char *));
    va_end(ap);

    return p;
}

person * person_dup (const person p) {
    return person_ptr_dup((const person *)&p);
}

person * person_ptr_dup (const person * p) {
    person* copy    = (person *) malloc(sizeof(person));
    copy -> name    = strdup(p -> name);
    copy -> age     = p -> age;
    copy -> gender  = p -> gender;
    copy -> phone   = strdup(p -> phone);
    copy -> address = strdup(p -> address);
    return copy;
}
char buf[2556];
char * person_display(person p) {
    buf[0]='\0';
    sprintf (buf, "%s,%d,%s,%d,%s\n",
    p.name,p.age,p.address,p.gender,p.phone);
    return buf;
}
char * person_ptr_display(person * p) {
    buf[0]='\0';
    sprintf (buf, "%s,%d,%s,%d,%s\n",
    p->name,p->age,p->address,p->gender,p->phone);
    return buf;
}

void free_person(person * p) {
    printf("\n clearing person: %s\n", person_ptr_display(p));
    free(p -> name);
    free(p -> address);
    free(p -> phone);
    free(p);
}
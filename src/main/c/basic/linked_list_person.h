#ifndef __LINKED_LIST_PERSON_H__
#define __LINKED_LIST_PERSON_H__
#include "linked_list.h"
#include "person.h"
#include <stdarg.h>

ll   * ll_person         (const person person);
ll   * ll_persons        (int count, const person data[]);
void   ll_persons_free   (ll* p);
void   ll_persons_display(ll* p);
ll   * ll_persons_va     (va_list ap, int count);
#endif
#ifndef __LINKED_LIST_NAME_H__
#define __LINKED_LIST_NAME_H__
#include "linked_list.h"
#include "name.h"
#include <stdarg.h>

ll   * ll_name         (const name person);
ll   * ll_names        (int count, const name data[]);
void   ll_names_free   (ll* p);
void   ll_names_display(ll* p);
ll   * ll_names_va     (va_list ap, int count);
#endif
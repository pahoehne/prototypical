//
// Created by Paul Hoehne on 10/4/22.
//

#include <stdlib.h>
#include <setjmp.h>
#include <stdint.h>
#include <stdarg.h>
#include <cmocka.h>

/**
 * This is the approach to handling malloc.  It seems to work fine without causing other crashes.
 */

#ifndef PROTOTYPICAL_MOCKS_H
#define PROTOTYPICAL_MOCKS_H

#ifdef malloc
#undef malloc
#endif

void* malloc(size_t size);

#endif //PROTOTYPICAL_MOCKS_H

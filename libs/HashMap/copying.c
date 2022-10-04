//
// Created by Paul Hoehne on 9/22/22.
//

#include <hashmap.h>
#include <stdlib.h>
#include <string.h>

#ifdef UNIT_TESTING
extern void* _test_malloc(const size_t size, const char *file, const int line);

#define malloc(size) _test_malloc(size, __FILE__, __LINE__)
#endif

bool BytewiseCopy(void *original, size_t size, void **copy) {
    if (NULL == *copy) {
        *copy = malloc(size);
    }

    if (*copy == NULL) {
      return false;
    }

    memcpy(*copy, original, size);
    return true;
}


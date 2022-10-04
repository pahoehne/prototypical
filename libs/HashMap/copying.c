//
// Created by Paul Hoehne on 9/22/22.
//

#include <hashmap.h>
#include <stdlib.h>
#include <string.h>

bool BytewiseCopy(void *original, size_t size, void **copy) {
    if (NULL == *copy) {
        *copy = malloc(size);
    }

    memcpy(*copy, original, size);
    return true;
}


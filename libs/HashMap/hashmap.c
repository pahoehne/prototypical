//
// Created by Paul Hoehne on 9/20/22.
//

#include <hashmap.h>
#include <stdlib.h>

struct HashMap {
    int temp;
};

pHashMap HashMap_New(KeyHashFunc hash, KeyEqualsFunc equals, ValueCopyFunc copyFunc) {
    return malloc(sizeof(HashMap));
}

void HashMap_Free(pHashMap map) {
    free(map);
}
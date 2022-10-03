//
// Created by Paul Hoehne on 9/22/22.
//

#include <hashmap.h>

//
// Use Dan Bernstein's djb2 hash from http://www.cse.yorku.ca/~oz/hash.html
//
HASH_T StringHash(const char* key) {
    HASH_T hash = 5381;
    int c;

    while ((c = *key++)) {
        hash = (hash << 5) + hash + c;
    }

    return hash;
}

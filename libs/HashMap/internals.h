//
// Created by Paul Hoehne on 9/24/22.
//

#include <stdint.h>
#include <stdlib.h>

#ifndef PROTOTYPICAL_INTERNALS_H
#define PROTOTYPICAL_INTERNALS_H

#define DEFAULT_ROW_SIZE 4
#define DEFAULT_MAP_ROWS 16
#define DEFAULT_MAX_LOAD 2

typedef struct Map_Node {
    uint32_t fullHash;
    char* key;
    void* value;
    size_t value_size;
} Map_Node;

typedef struct Map_Row {
    uint32_t partHash;
    size_t count;
    Map_Node nodes[];
} Map_Row;

struct Map_Internals {
    size_t size;
    Map_Row rows;
};

#endif //PROTOTYPICAL_INTERNALS_H

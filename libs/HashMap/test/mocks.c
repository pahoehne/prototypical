//
// Created by Paul Hoehne on 10/4/22.
//

#include "mocks.h"

void* malloc(size_t size) {
    function_called();
    return mock_ptr_type(void*);
}
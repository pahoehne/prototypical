//
// Created by Paul Hoehne on 9/22/22.
//

#include <hashmap.h>

#include <stddef.h> /* Needed for NULL, etc. */
#include <stdint.h> /* needed by cmocka */
#include <setjmp.h> /* needed by cmocka */
#include <stdarg.h> /* needed by cmocka */
#include <cmocka.h>

void testSimpleCopy(void **state);

void testCopyWithExistingBuffer(void **state);

void testCopyFailsToAllocateMemory(void **state);

void testSimpleCopy(void **state) {
    uint8_t data[] = {1, 2, 3, 4, 5, 6, 7, 8};
    uint8_t *copiedData = NULL;
    uint8_t mockAllocation[8];

    will_return(malloc, mockAllocation);
    expect_function_call(malloc);

    assert_true(BytewiseCopy(data, sizeof(data), (void **) &copiedData));
    assert_non_null(copiedData);
    assert_memory_equal(data, copiedData, sizeof(data));
}

void testCopyWithExistingBuffer(void **state) {
    uint8_t data[] = {1, 2, 3, 4, 5, 6, 7, 8};
    uint8_t copiedData[] = {0, 0, 0, 0, 0, 0, 0, 0};
    uint8_t *outBuffer = copiedData;

    ignore_function_calls(malloc);

    assert_true(BytewiseCopy(data, sizeof(data), (void **) &outBuffer));
    assert_non_null(outBuffer);
    assert_ptr_equal(outBuffer, copiedData);
    assert_memory_equal(copiedData, data, sizeof(data));
}

void testCopyFailsToAllocateMemory(void **state) {
    uint8_t data[] = {1, 2, 3, 4, 5, 6, 7, 8};
    uint8_t *copiedData = NULL;

    will_return(malloc, NULL);
    expect_function_call(malloc);

    assert_false(BytewiseCopy(data, sizeof(data), (void **) &copiedData));
    assert_null(copiedData);
}

int main(int argc, char **argv) {
    const struct CMUnitTest tests[] = {
            cmocka_unit_test(testSimpleCopy),
            cmocka_unit_test(testCopyWithExistingBuffer),
            cmocka_unit_test(testCopyFailsToAllocateMemory),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}

//
// Created by Paul Hoehne on 9/20/22.
//

/**
 * This implements a hash map of strings to values of some type.
 */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifndef PROTOTYPICAL_HASHMAP_H
#define PROTOTYPICAL_HASHMAP_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * A hash map.
 */
struct HashMap;
typedef struct HashMap HashMap;
typedef HashMap *pHashMap;

/**
 * Hash type
 */
typedef uint32_t HASH_T;

/**
 * Defines a function that hashes a key and returns a 32bit hash code for that key.
 */
typedef HASH_T (*KeyHashFunc)(const char *data);

/**
 * Default implementation of a hashing function.  This is a simple hash, case sensitive,
 * and 8-bit ascii.
 *
 * @param key The key to hash
 * @return The hashed value
 */
HASH_T StringHash(const char *key);

/**
 * Defines a function that compares two keys for equality.  The user is free to provide
 * their own implementation.
 */
typedef bool (*KeyEqualsFunc)(const char *k1, const char *k2);

/**
 * Default equality function (case sensitive and 8-bit ascii).  For example,
 * 'abc' and 'abc' are equal, but 'abc' and 'ABC' are not.
 * @param key the key
 * @return True, if they're equal.
 */
bool SimpleEquals(const char *key1, const char *key2);

/**
 * A function for copying the memory that holds the value in the hash map. The user is
 * free to provide their own implementation, given the rules below.
 *
 * 1. If `copy` points to a null-pointer, allocate `size` bytes to hold the copy.
 * 2. If `copy` points to an address, then assume that copy is at least `size` bytes.
 * 3. Return false, if unable to allocate memory (rule 1) to hold the copy.
 * 4. Return true if the copy is successful.
 */
typedef bool (*ValueCopyFunc)(void *original, size_t size, void **copy);

/**
 * Performs a simple byte-wise copy of the data from original to copy for up to size
 * bytes.  Allocates new memory if `copy` refers to a null pointer.  Otherwise, it is
 * up to the caller to ensure that `copy` is large enough to hold the data.
 *
 * @param original The original copy of the data.
 * @param size The size of the original data in bytes.
 * @param copy The allocated new copy of the data.
 * @return
 */
bool BytewiseCopy(void *original, size_t size, void **copy);

/**
 * Allocates a new hash map.  The default hash function is the StringHash which hashes
 * 8-bit ascii strings in their original case.  The default equality function is a simple
 * string comparison.  The default value copy function is not to copy.  If the copy
 * function is null, the reference will be saved but not a copy of the data.  It is the
 * users responsibility to ensure the data is not changed.
 *
 * @param hash The hashing function to use for the key data.
 * @param equals The equality function for keys.
 * @param copyFunc How to copy (or not) the value.
 * @return A new hashmap
 */
pHashMap HashMap_New(KeyHashFunc hash, KeyEqualsFunc equals, ValueCopyFunc copyFunc);

/**
 * Sets a value for a given key.  If the copy function is defined, the data will also
 * be copied according to the copy function.  If there is no copy function, only the reference
 * to the data is saved and the data's lifetime is owned by the user.
 *
 * If the key is already present, then the data is overwritten.  If the copy function isn't
 * set, then the reference is simply updated with the new reference.  It is the user's
 * responsibility to free any data, as that data is user owned.  if the copy function is
 * set, then the hash map owns the copy of the data and it will free the old data before
 * copying the new data.
 *
 * A non-zero value is returned on success and a zero if there was an error.
 *
 * @param map The hash map.
 * @param key The key for the data.
 * @param value A reference to the value.
 * @param size The size (in bytes) of the value.
 * @return The status.
 */
int HashMap_Set(pHashMap map, char *key, void *value, size_t size);

/**
 * Returns the value for a given key.  If the value is present in the hash map, and the
 * copy function isn't set, then the output parameters `value` and `size` contain the
 * reference and size originally passed when the key was first set.
 *
 * If the value is present in the map, and the copy function is defined, and the output
 * parameter for `value` points to a non-null pointer, then it is assumed that the user
 * has allocated a buffer to receive the value.  The size of the buffer should be passed
 * in to `maxSize`.  The actual size of the value is returned in the `size` out parameter.
 * Note that a `maxSize` smaller than the size of the data is an error.  A value less than
 * zero is returned and the user can check the size returned in the out parameter against
 * the max size.
 *
 * If the value is present in the map, and the copy function is defined, and the output
 * parameter for `value` points to a null pointer, then it is assumed the user intends the
 * get function to allocate the buffer, placing the pointer in the `value` output parameter.
 * It will be up to the user to free the allocated memory.  The size is places in the `size`
 * out parameter.
 *
 * A non-zero value indicates success and a zero indicates there was an error.  If the key
 * is not in the map, the return value is less than zero.
 *
 * @param map The hash map.
 * @param key The key to look up.
 * @param maxSize The size of the user supplied output buffer.
 * @param value (Out) the buffer into which the value for the key is copied.
 * @param size (Out) the number of bytes written into that buffer.
 * @return The status
 */
int HashMap_Get(pHashMap map, char *key, size_t maxSize, void **value, size_t *size);

/**
 * Delete removes a key from the hash map.  If the copy function hs been set, then the
 * hash map is responsible for deallocating the data.  If the user did not set the copy
 * function, then the user is responsible for the memory holding the value.
 *
 * Like all functions, a non-zero value indicates succes, and a zero is an error.
 *
 * @param map The hash map.
 * @param key The key.
 * @return The status
 */
int HashMap_Delete(pHashMap map, char *key);

/**
 * Deallocates the memory held by the hash map.  Any operation on a hash map after free is called
 * is undefined.  If the copy function has been set, then the hash map will also free any memory
 * to hold the copy of the values it has retained.  If the copy function is not set, the user is
 * responsible for the memory used to store values.
 *
 * @param map The hash map.
 */
void HashMap_Free(pHashMap map);

#ifdef __cplusplus
};
#endif /* __cplusplus */

#endif //PROTOTYPICAL_HASHMAP_H

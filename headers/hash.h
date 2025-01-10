#ifndef DSA_HASH_H
#define DSA_HASH_H

#include <stdlib.h>

/* 
 * dsa_simple_sum_hash:
 * ---------------------
 * - **Theory**: This hash function works by summing the ASCII values of all characters in the input string.
 * - **Properties**:
 *   - Deterministic: Always produces the same result for the same input.
 *   - Simple and fast: Requires minimal computation.
 * - **Pros**:
 *   - Easy to implement and debug.
 *   - Computationally efficient.
 * - **Cons**:
 *   - Poor distribution for longer strings, especially when characters are similar.
 *   - Prone to clustering, leading to more collisions in hash tables.
 * - **Use Case**: Suitable for quick prototypes but not recommended for production systems.
 */
size_t dsa_simple_sum_hash(char *key, size_t size);

/* 
 * dsa_polynomial_hash:
 * ---------------------
 * - **Theory**: This function treats the input string as a polynomial where each character contributes to a weighted sum.
 *   - The formula is: `hash = (c_1 * p^0 + c_2 * p^1 + c_3 * p^2 + ...) % size`
 * - **Properties**:
 *   - Prime base (e.g., 31 or 37) helps reduce collisions.
 *   - Weighted character values make the hash sensitive to character order.
 * - **Pros**:
 *   - Good distribution.
 *   - Handles collisions better than simple sum hashing.
 * - **Cons**:
 *   - Slightly more computationally expensive due to multiplications and modular operations.
 * - **Use Case**: General-purpose use for small-to-medium hash tables.
 */
size_t dsa_polynomial_hash(char *key, size_t size);

/* 
 * dsa_djb2_hash:
 * -----------------
 * - **Theory**: Created by Daniel J. Bernstein, this hash function uses a magic starting number (5381) and iteratively 
 *   multiplies the current hash by 33 (using bit shifts for efficiency) before adding the ASCII value of the character.
 * - **Properties**:
 *   - The multiplier `33` is carefully chosen for its performance and distribution characteristics.
 *   - Combines character values iteratively to create the hash.
 * - **Pros**:
 *   - Simple, fast, and widely used.
 *   - Produces reasonable distributions for small-to-medium datasets.
 * - **Cons**:
 *   - May not handle highly repetitive data as well as more advanced hashes.
 * - **Use Case**: Suitable for most non-cryptographic applications.
 */
size_t dsa_djb2_hash(char *key, size_t size);

/* 
 * dsa_fnv1a_hash:
 * ----------------
 * - **Theory**: The FNV-1a hash is based on XORing each byte of the input string with a large, carefully chosen 
 *   "offset basis" (2166136261 for 32-bit) and then multiplying by a "prime multiplier" (16777619 for 32-bit).
 * - **Properties**:
 *   - XOR introduces variability, while multiplication ensures bit mixing.
 *   - Suitable for high-performance applications.
 * - **Pros**:
 *   - Excellent distribution.
 *   - Computationally efficient.
 * - **Cons**:
 *   - Slightly more complex than DJB2.
 * - **Use Case**: Great for performance-critical systems requiring reliable hashing.
 */
size_t dsa_fnv1a_hash(char *key, size_t size);

/* 
 * dsa_simple_murmur_hash:
 * ------------------------
 * - **Theory**: A simplified version of the MurmurHash algorithm, which is designed for high-quality distribution 
 *   and performance. It uses bitwise XOR, multiplication by constants, and bit shifting for mixing bits.
 * - **Properties**:
 *   - Very good distribution for strings of varying lengths and patterns.
 *   - Scales well for large datasets.
 * - **Pros**:
 *   - High-quality hash with minimal clustering.
 *   - Efficient for both small and large datasets.
 * - **Cons**:
 *   - More complex than simpler alternatives like DJB2 or FNV-1a.
 * - **Use Case**: Ideal for modern systems requiring high performance and scalability.
 */
size_t dsa_simple_murmur_hash(char *key, size_t size);

/* 
 * dsa_crc32_hash:
 * ----------------
 * - **Theory**: Uses a cyclic redundancy check (CRC) algorithm, which is typically used for error checking but 
 *   can also function as a hash. It processes the input string one byte at a time, applying a polynomial-based operation.
 * - **Properties**:
 *   - Extremely low collision rates due to its focus on error detection.
 *   - Can hash large datasets effectively.
 * - **Pros**:
 *   - High reliability and collision resistance.
 * - **Cons**:
 *   - Computationally expensive compared to other hash functions.
 *   - Overkill for many applications unless collision rates are critical.
 * - **Use Case**: Best suited for applications where data integrity is vital.
 */
size_t dsa_crc32_hash(char *key, size_t size);

#endif // !DSA_HASH_H

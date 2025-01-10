#include <stdlib.h>

#include "hash.h"

size_t dsa_simple_sum_hash(char *key, size_t size) {
    size_t hash_value = 0;                      // Initialize the hash value to 0
    for (size_t character_index = 0; key[character_index] != '\0'; character_index++) {
        hash_value += key[character_index];     // Add the ASCII value of each character to the hash value
    }
    return hash_value % size;        // Scale the hash value to fit within the hash table size
}

size_t dsa_polynomial_hash(char *key, size_t size) {
    size_t hash_value = 0;                      // Start with a hash value of 0
    size_t prime_base = 31;                     // Prime base multiplier for the polynomial hash
    size_t prime_power = 1;                     // Current power of the prime base (starts with prime_base^0 = 1)

    for (size_t character_index = 0; key[character_index] != '\0'; character_index++) {
        hash_value = (hash_value + 
                      (key[character_index] - 'a' + 1) * prime_power) % size; // Weighted sum of ASCII values
        prime_power = (prime_power * prime_base) % size; // Update prime_power to the next power of the base
    }

    return hash_value;                          // Return the final scaled hash value
}

size_t dsa_djb2_hash(char *key, size_t size) {
    size_t hash_value = 5381;                   // Initialize hash value with a magic number 5381
    int current_character;

    while ((current_character = *key++)) {      // Process each character in the input string
        hash_value = ((hash_value << 5) + hash_value) + current_character; // hash_value * 33 + current_character
    }

    return hash_value % size;        // Scale the hash value to fit within the hash table size
}

size_t dsa_fnv1a_hash(char *key, size_t size) {
    size_t hash_value = 2166136261u;            // FNV offset basis for 32-bit hash
    size_t fnv_prime_multiplier = 16777619u;    // FNV prime number for 32-bit hash

    for (size_t character_index = 0; key[character_index] != '\0'; character_index++) {
        hash_value ^= key[character_index];     // XOR the current character with the hash value
        hash_value *= fnv_prime_multiplier;    // Multiply the hash value by the FNV prime
    }

    return hash_value % size;        // Scale the hash value to fit within the hash table size
}

size_t dsa_simple_murmur_hash(char *key, size_t size) {
    size_t hash_value = 0xc6a4a7935bd1e995;     // Magic constant for bit mixing
    size_t seed_value = 0x5bd1e995;             // Seed value for the hash function
    size_t right_shift_amount = 24;             // Right shift amount for mixing bits

    for (size_t character_index = 0; key[character_index] != '\0'; character_index++) {
        hash_value ^= key[character_index];     // XOR the current character with the hash value
        hash_value *= seed_value;              // Multiply the hash value by the seed
        hash_value ^= (hash_value >> right_shift_amount); // Mix bits with a right shift
    }

    return hash_value % size;        // Scale the hash value to fit within the hash table size
}

size_t dsa_crc32_hash(char *key, size_t size) {
	// CRC is a Numeric checksum used to detect errors
    size_t crc_value = 0xFFFFFFFF;              // Initialize CRC value with all bits set
    size_t crc_polynomial = 0xEDB88320;         // CRC-32 polynomial value

    for (size_t character_index = 0; key[character_index] != '\0'; character_index++) {
        crc_value ^= key[character_index];      // XOR the current character into the CRC value
        for (size_t bit_index = 0; bit_index < 8; bit_index++) {
            if (crc_value & 1) {                // Check if the least significant bit is 1
                crc_value = (crc_value >> 1) ^ crc_polynomial; // Apply the polynomial if LSB is 1
            } else {
                crc_value >>= 1;               // Otherwise, just shift right
            }
        }
    }

    return (crc_value ^ 0xFFFFFFFF) % size; // Invert the CRC value and scale to the hash table size
}

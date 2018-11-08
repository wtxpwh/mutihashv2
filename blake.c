#include "blake.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "sha3/sph_blake.h"

#include "blake2/blake2s.h"
#include "blake2/blake2.h"

void blake_hash(const char* input, char* output, uint32_t len)
{
    sph_blake256_context ctx_blake;
    sph_blake256_init(&ctx_blake);
    sph_blake256(&ctx_blake, input, len);
    sph_blake256_close(&ctx_blake, output);
}

void blake2b_hash(const char* input, char* output, uint32_t len)
{
    size_t outlen = 32;
    blake2b_state ctx_blake;
    blake2b_init(&ctx_blake, outlen);
    blake2b_update(&ctx_blake, input, len);
    blake2b_final(&ctx_blake, output, outlen);
}

void blake2s_hash(const char* input, char* output, uint32_t len)
{
    size_t outlen = 32;
    blake2s_state ctx_blake;
    blake2s_init(&ctx_blake, outlen);
    blake2s_update(&ctx_blake, input, len);
    blake2s_final(&ctx_blake, output, outlen);
}
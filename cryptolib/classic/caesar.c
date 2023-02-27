#include "caesar.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct CL_classic_caesar_t {
    CL_encoding_alpha_t *encoder;
    int32_t key;
} CL_classic_caesar_t;

static int32_t encrypt(int32_t c, int32_t k);

extern CL_classic_caesar_t *CL_classic_caesar_new(CL_encoding_alpha_t *encoder, int32_t k) {
    CL_classic_caesar_t *ctx = (CL_classic_caesar_t*)malloc(sizeof(CL_classic_caesar_t));
   
    ctx->encoder = encoder;
    ctx->key = k;

    return ctx; 
}

extern void CL_classic_caesar_free(CL_classic_caesar_t *ctx) {
    free(ctx);
}

extern uint8_t *CL_classic_caesar_encrypt(CL_classic_caesar_t *ctx, CL_mode_t m, uint8_t *output, uint8_t *input) {
    size_t input_len = strlen((char*)input);
    int encoded_ch, encrypted;
    
    for (int i = 0; i < input_len; i++) {
        encoded_ch = CL_encoding_alpha_encode(ctx->encoder, input[i]);
        encrypted = encrypt(encoded_ch, m*ctx->key); // CL_mode_t = {-1, 1}
        output[i] = CL_encoding_alpha_decode(ctx->encoder, encrypted);
    }

    output[input_len] = '\0';
    return output;
}

static int32_t encrypt(int32_t c, int32_t k) {
    return (c+k+CL_ENCODING_ALPHA_ENGLISH_SIZE)%CL_ENCODING_ALPHA_ENGLISH_SIZE;
}

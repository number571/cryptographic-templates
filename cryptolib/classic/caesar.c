#include "caesar.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct CL_classic_caesar_t {
    CL_encoding_alpha_t *encoder;
} CL_classic_caesar_t;

static int encrypt(int c, int k);

extern CL_classic_caesar_t *CL_classic_caesar_new(CL_encoding_alpha_t *encoder) {
    CL_classic_caesar_t *ctx = (CL_classic_caesar_t*)malloc(sizeof(CL_classic_caesar_t));
   
    ctx->encoder = encoder;

    return ctx; 
}

extern void CL_classic_caesar_free(CL_classic_caesar_t *ctx) {
    free(ctx);
}

extern uint8_t *CL_classic_caesar_encrypt(CL_classic_caesar_t *ctx, CL_mode_t m, uint32_t k, uint8_t *output, uint8_t *input) {
    size_t len = strlen((char*)input);
    int encodedCh, encrypted;
    
    for (int i = 0; i < len; i++) {
        encodedCh = CL_encoding_alpha_encode(ctx->encoder, input[i]);
        encrypted = encrypt(encodedCh, m*k); // CL_mode_t = {-1, 1}
        output[i] = CL_encoding_alpha_decode(ctx->encoder, encrypted);
    }

    output[len] = '\0';
    return output;
}

static int encrypt(int c, int k) {
    return (c+k+CL_ENCODING_ALPHA_ENGLISH_SIZE)%CL_ENCODING_ALPHA_ENGLISH_SIZE;
}

#include "vigenere.h"

#include "../encoding/alpha.h"

#include <stdlib.h>
#include <string.h>

typedef struct CL_classic_vigenere_t {
    CL_encoding_alpha_t *encoder;
} CL_classic_vigenere_t;

static int encrypt(int c, int k);

extern CL_classic_vigenere_t *CL_classic_vigenere_new(CL_encoding_alpha_t *encoder) {
    CL_classic_vigenere_t *ctx = (CL_classic_vigenere_t*)malloc(sizeof(CL_classic_vigenere_t));
   
    ctx->encoder = encoder;

    return ctx; 
}

extern void CL_classic_vigenere_free(CL_classic_vigenere_t *ctx) {
    free(ctx);
}

extern uint8_t *CL_classic_vigenere_encrypt(CL_classic_vigenere_t *ctx, CL_mode_t m, uint8_t *key, uint8_t *output, uint8_t *input) {
    size_t inputLen = strlen((char*)input);
    size_t keyLen = strlen((char*)key);

    int encodedCh, encrypted;
    
    for (int i = 0; i < inputLen; i++) {
        encodedCh = CL_encoding_alpha_encode(ctx->encoder, input[i]);
        encrypted = encrypt(encodedCh, m*CL_encoding_alpha_encode(ctx->encoder, key[i%keyLen])); // CL_mode_t = {-1, 1}
        output[i] = CL_encoding_alpha_decode(ctx->encoder, encrypted);
    }

    output[inputLen] = '\0';
    return output;
}

static int encrypt(int c, int k) {
    return (c+k+CL_ENCODING_ALPHA_ENGLISH_SIZE)%CL_ENCODING_ALPHA_ENGLISH_SIZE;
}

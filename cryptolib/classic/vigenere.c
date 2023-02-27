#include "vigenere.h"

#include "../encoding/alpha.h"

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct CL_classic_vigenere_t {
    CL_encoding_alpha_t *encoder;
    size_t len_key;
    uint8_t *key;
} CL_classic_vigenere_t;

static int32_t encrypt(int32_t c, int32_t k);

extern CL_classic_vigenere_t *CL_classic_vigenere_new(CL_encoding_alpha_t *encoder, uint8_t *key) {
    CL_classic_vigenere_t *ctx = (CL_classic_vigenere_t*)malloc(sizeof(CL_classic_vigenere_t));
    size_t len_key = strlen((char*)key);
   
    ctx->encoder = encoder;
    ctx->len_key = len_key;

    ctx->key = (uint8_t*)malloc(sizeof(uint8_t)*(len_key+1));
    strcpy((char*)ctx->key, (char*)key);

    return ctx; 
}

extern void CL_classic_vigenere_free(CL_classic_vigenere_t *ctx) {
    free(ctx->key);
    free(ctx);
}

extern uint8_t *CL_classic_vigenere_encrypt(CL_classic_vigenere_t *ctx, CL_mode_t m, uint8_t *output, uint8_t *input) {
    size_t input_len = strlen((char*)input);
    int encoded_ch, encrypted;
    
    for (int i = 0; i < input_len; i++) {
        encoded_ch = CL_encoding_alpha_encode(ctx->encoder, input[i]);
        encrypted = encrypt(
            encoded_ch, 
            m*CL_encoding_alpha_encode(ctx->encoder, ctx->key[i%ctx->len_key])
        ); // CL_mode_t = {-1, 1}
        output[i] = CL_encoding_alpha_decode(ctx->encoder, encrypted);
    }

    output[input_len] = '\0';
    return output;
}

static int32_t encrypt(int32_t c, int32_t k) {
    return (c+k+CL_ENCODING_ALPHA_ENGLISH_SIZE)%CL_ENCODING_ALPHA_ENGLISH_SIZE;
}

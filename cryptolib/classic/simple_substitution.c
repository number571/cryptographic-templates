#include "caesar.h"

#include "../encoding/alpha.h"

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct CL_classic_simple_substitution_t {
    CL_encoding_alpha_t *orig_encoder;
    CL_encoding_alpha_t *encr_encoder;
} CL_classic_simple_substitution_t;

extern CL_classic_simple_substitution_t *CL_classic_simple_substitution_new(
    CL_encoding_alpha_t *orig_encoder, 
    CL_encoding_alpha_t *encr_encoder
) {
    CL_classic_simple_substitution_t *ctx = (CL_classic_simple_substitution_t*)malloc(sizeof(CL_classic_simple_substitution_t));

    ctx->orig_encoder = orig_encoder;
    ctx->encr_encoder = encr_encoder;

    return ctx; 
}

extern void CL_classic_simple_substitution_free(CL_classic_simple_substitution_t *ctx) {
    free(ctx);
}

extern uint8_t *CL_classic_simple_substitution_encrypt(CL_classic_simple_substitution_t *ctx, CL_mode_t m, uint8_t *output, uint8_t *input) {
    CL_encoding_alpha_t *encoder_read, *encoder_write;
    size_t input_len = strlen((char*)input);
    int encoded_ch;

    switch (m) {
        case CL_MODE_ENCRYPT:
            encoder_read = ctx->orig_encoder;
            encoder_write = ctx->encr_encoder;
        break;
        case CL_MODE_DECRYPT:
            encoder_read = ctx->encr_encoder;
            encoder_write = ctx->orig_encoder;
        break;
    }

    for (int i = 0; i < input_len; i++) {
        encoded_ch = CL_encoding_alpha_encode(encoder_read, input[i]);
        output[i] = CL_encoding_alpha_decode(encoder_write, encoded_ch);
    }

    output[input_len] = '\0';
    return output;
}

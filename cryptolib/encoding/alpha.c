#include "alpha.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct CL_encoding_alpha_t {
    uint8_t *alpha;
    uint32_t alphasize;
} CL_encoding_alpha_t;

static bool alpha_is_valid(uint8_t *alpha, uint32_t alphasize);

extern uint8_t *CL_encoding_alpha_english() {
    static uint8_t alpha[CL_ENCODING_ALPHA_ENGLISH_SIZE+1] = {0}; // "ABCDEFG...XYZ"
    if (alpha[0] == 'A') {
        return alpha;
    }
    int j = 0;
    for (int i = 'A'; i <= 'Z'; i++) {
        alpha[j] = i;
        ++j;
    }
    alpha[j] = '\0';
    return alpha;
}

extern CL_encoding_alpha_t *CL_encoding_alpha_new(uint8_t *alpha, uint32_t alphasize) {
    if (!alpha_is_valid(alpha, alphasize)) {
        return NULL;
    }

    CL_encoding_alpha_t *ctx = (CL_encoding_alpha_t*)malloc(sizeof(CL_encoding_alpha_t));
   
    ctx->alphasize = alphasize;
    ctx->alpha = (uint8_t*)malloc(sizeof(uint8_t)*alphasize);
    memcpy(ctx->alpha, alpha, sizeof(uint8_t)*alphasize);

    for (int i = 0; i < alphasize; ++i) {
        ctx->alpha[i] = toupper(ctx->alpha[i]);
    }

    return ctx; 
}

extern void CL_encoding_alpha_free(CL_encoding_alpha_t *ctx) {
    free(ctx->alpha);
    free(ctx);
}

extern int32_t CL_encoding_alpha_encode(CL_encoding_alpha_t *ctx, uint8_t ch) {
    uint8_t upCh = toupper(ch);
    for (int i = 0; i < ctx->alphasize; i++) {
        if (ctx->alpha[i] == upCh) {
            return i;
        }
    }
    return -1;
}

extern uint8_t CL_encoding_alpha_decode(CL_encoding_alpha_t *ctx, int32_t i) {
    if (i < 0 || i > ctx->alphasize) {
        return 0;
    }
    return ctx->alpha[i];
}

static bool alpha_is_valid(uint8_t *alpha, uint32_t alphasize) {
    for (int i = 0; i < alphasize; ++i) {
        for (int j = i+1; j < alphasize-1; j++) {
            if (alpha[i] == alpha[j]) {
                return false;
            }
        }
    }
    return true;
}

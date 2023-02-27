#ifndef _H_CRYPTOLIB_CLASSIC_SIMPLE_SUBSTITUTION
#define _H_CRYPTOLIB_CLASSIC_SIMPLE_SUBSTITUTION

#include "../mode.h"
#include "../encoding/alpha.h"

#include <stdint.h>

typedef struct CL_classic_simple_substitution_t CL_classic_simple_substitution_t;

extern CL_classic_simple_substitution_t *CL_classic_simple_substitution_new(
    CL_encoding_alpha_t *orig_encoder, 
    CL_encoding_alpha_t *encr_encoder
);
extern void CL_classic_simple_substitution_free(CL_classic_simple_substitution_t *ctx);

extern uint8_t *CL_classic_simple_substitution_encrypt(CL_classic_simple_substitution_t *ctx, CL_mode_t m, uint8_t *output, uint8_t *input);

#endif

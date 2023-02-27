#ifndef _H_CRYPTOLIB_CLASSIC_CAESAR
#define _H_CRYPTOLIB_CLASSIC_CAESAR

#include "../encoding/alpha.h"
#include "../mode.h"

#include <stdint.h>

typedef struct CL_classic_caesar_t CL_classic_caesar_t;

extern CL_classic_caesar_t *CL_classic_caesar_new(CL_encoding_alpha_t *encoder, int32_t k);
extern void CL_classic_caesar_free(CL_classic_caesar_t *ctx);

extern uint8_t *CL_classic_caesar_encrypt(CL_classic_caesar_t *ctx, CL_mode_t m, uint8_t *output, uint8_t *input);

#endif

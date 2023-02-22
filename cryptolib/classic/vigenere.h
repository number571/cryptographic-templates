#ifndef _H_CRYPTOLIB_CLASSIC_VIGENERE
#define _H_CRYPTOLIB_CLASSIC_VIGENERE

#include "../encoding/alpha.h"
#include "../mode.h"

#include <stdint.h>

typedef struct CL_classic_vigenere_t CL_classic_vigenere_t;

extern CL_classic_vigenere_t *CL_classic_vigenere_new(CL_encoding_alpha_t *encoder);
extern void CL_classic_vigenere_free(CL_classic_vigenere_t *ctx);

extern uint8_t *CL_classic_vigenere_encrypt(CL_classic_vigenere_t *ctx, CL_mode_t m, uint8_t *key, uint8_t *output, uint8_t *input);

#endif

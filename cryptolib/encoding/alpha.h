#ifndef _H_CRYPTOLIB_ENCODING_ALPHA
#define _H_CRYPTOLIB_ENCODING_ALPHA

#include <stdint.h>

#define CL_ENCODING_ALPHA_ENGLISH_SIZE 26

typedef struct CL_encoding_alpha_t CL_encoding_alpha_t;

extern uint8_t *CL_encoding_alpha_english();

extern CL_encoding_alpha_t *CL_encoding_alpha_new(uint8_t *alpha, uint32_t alphasize);
extern void CL_encoding_alpha_free(CL_encoding_alpha_t *ctx);

extern int32_t CL_encoding_alpha_encode(CL_encoding_alpha_t *ctx, uint8_t ch);
extern uint8_t CL_encoding_alpha_decode(CL_encoding_alpha_t *ctx, int32_t i);

#endif

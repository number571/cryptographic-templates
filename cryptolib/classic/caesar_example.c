#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "../encoding/alpha.h"
#include "caesar.h"

int main(int argc, char *argv[]) {
    uint8_t message[BUFSIZ];
    uint32_t key = 3;

    strcpy((char*)message, "helloworld");

    CL_encoding_alpha_t *encoder = CL_encoding_alpha_new(
        CL_encoding_alpha_english(), 
        CL_ENCODING_ALPHA_ENGLISH_SIZE
    );

    CL_classic_caesar_t *cipher = CL_classic_caesar_new(encoder, key);

    printf("%s\n", (char*)CL_classic_caesar_encrypt(cipher, CL_MODE_ENCRYPT, message, message));
    printf("%s\n", (char*)CL_classic_caesar_encrypt(cipher, CL_MODE_DECRYPT, message, message));

    CL_classic_caesar_free(cipher);
    CL_encoding_alpha_free(encoder);
    return 0;
}

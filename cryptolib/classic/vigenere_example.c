#include <stdio.h>
#include <string.h>

#include "../encoding/alpha.h"
#include "vigenere.h"

int main(int argc, char *argv[]) {
    uint8_t message[BUFSIZ];
    uint8_t *key = (uint8_t*)"stringkey";

    strcpy((char*)message, "helloworld");

    CL_encoding_alpha_t *encoder = CL_encoding_alpha_new(
        CL_encoding_alpha_english(), 
        CL_ENCODING_ALPHA_ENGLISH_SIZE
    );

    CL_classic_vigenere_t *cipher = CL_classic_vigenere_new(encoder);

    printf("%s\n", (char*)CL_classic_vigenere_encrypt(cipher, CL_MODE_ENCRYPT, key, message, message));
    printf("%s\n", (char*)CL_classic_vigenere_encrypt(cipher, CL_MODE_DECRYPT, key, message, message));

    CL_classic_vigenere_free(cipher);
    CL_encoding_alpha_free(encoder);
    return 0;
}

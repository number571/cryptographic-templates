#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "alpha.h"

int main(int argc, char *argv[]) {
    uint8_t message[BUFSIZ];
    strcpy((char*)message, "helloworld");

    CL_encoding_alpha_t *encoder = CL_encoding_alpha_new(
        CL_encoding_alpha_english(), 
        CL_ENCODING_ALPHA_ENGLISH_SIZE
    );

    for (int i = 0; i < strlen((char*)message); ++i) {
        printf("%d ", CL_encoding_alpha_encode(encoder, message[i]));
    }
    printf("\n");

    return 0;
}

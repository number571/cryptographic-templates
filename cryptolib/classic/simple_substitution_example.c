#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "../encoding/alpha.h"
#include "simple_substitution.h"

int main(int argc, char *argv[]) {
    uint8_t message[BUFSIZ], alphakey[BUFSIZ];
    strcpy((char*)message, "helloworld");
    strcpy((char*)alphakey, "qwertyuiopasdfghjklzxcvbnm");

    CL_encoding_alpha_t *orig_encoder = CL_encoding_alpha_new(
        CL_encoding_alpha_english(), 
        CL_ENCODING_ALPHA_ENGLISH_SIZE
    );

    CL_encoding_alpha_t *encr_encoder = CL_encoding_alpha_new(
        alphakey, 
        strlen((char*)alphakey)
    );

    CL_classic_simple_substitution_t *cipher = CL_classic_simple_substitution_new(orig_encoder, encr_encoder);

    printf("%s\n", (char*)CL_classic_simple_substitution_encrypt(cipher, CL_MODE_ENCRYPT, message, message));
    printf("%s\n", (char*)CL_classic_simple_substitution_encrypt(cipher, CL_MODE_DECRYPT, message, message));
    
    CL_classic_simple_substitution_free(cipher);
    CL_encoding_alpha_free(orig_encoder);
    CL_encoding_alpha_free(encr_encoder);
    return 0;
}

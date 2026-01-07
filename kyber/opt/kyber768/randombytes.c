#include "randombytes.h"


int randombytes(void* buf, const size_t n) {

    //todo 0~n이 되도록 바꾸기 
   /*  HCRYPTPROV ctx;
     BOOL tmp;

     tmp = CryptAcquireContext(&ctx, NULL, NULL, PROV_RSA_FULL,
                               CRYPT_VERIFYCONTEXT);
     if (tmp == FALSE) {
         return -1;
     }

     tmp = CryptGenRandom(ctx, (unsigned long)n, (BYTE *) buf);
     if (tmp == FALSE) {
         return -1;
     }

     tmp = CryptReleaseContext(ctx, 0);
     if (tmp == FALSE) {
         return -1;
     }*/
    uint8_t* ptr = buf;

    for (int cnt_i = 0; cnt_i < n; cnt_i++)
    {
        ptr[cnt_i] = cnt_i;
    }

    return 0;
}




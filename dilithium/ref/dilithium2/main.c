#include <io430.h>
#include <stdio.h>
#include <stdint.h>
#include "api.h"
#include "params.h"
#include "poly.h"
#include "reduce.h"
#include <stdlib.h>
#include <time.h>
#define CRYPTO_MSG_BYTES 32



int ret = 0;

int main()
{
    WDTCTL = WDTPW | WDTHOLD;    
  
    uint8_t pk[CRYPTO_PUBLICKEYBYTES] = { 0 };
    uint8_t sk[CRYPTO_SECRETKEYBYTES] = { 0 };                    
    uint8_t m[CRYPTO_MSG_BYTES] = { 3, 0, };
    uint8_t sig[CRYPTO_BYTES] = { 0 };
    size_t siglen = 0;
    size_t mlen = CRYPTO_MSG_BYTES;
    
    ret = CRYPTO_PUBLICKEYBYTES;
    
    crypto_sign_keypair(pk, sk);
    ret = crypto_sign_signature(sig, &siglen, m, mlen, sk);        
    ret = crypto_sign_verify(sig, siglen, m, mlen, pk); 
    printf("ret : %d\n", ret);
            
    return ret;
}





































































































































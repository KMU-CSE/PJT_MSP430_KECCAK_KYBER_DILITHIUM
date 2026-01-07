#include <msp430.h>
#include "api.h"
#include <stdio.h>
#include "reduce.h"



int main()
{
        WDTCTL = WDTPW | WDTHOLD;
    
	int ret = 0;

	uint8_t pk[CRYPTO_PUBLICKEYBYTES];
	uint8_t sk[CRYPTO_SECRETKEYBYTES];
	uint8_t ct[CRYPTO_CIPHERTEXTBYTES];
	uint8_t ss[CRYPTO_BYTES];
	uint8_t ss2[CRYPTO_BYTES];
                        
	ret = crypto_kem_keypair(pk, sk);       
	ret = crypto_kem_enc(ct, ss, pk);          
	ret = crypto_kem_dec(ss2, ct, sk);      
        	        
        printf("\nSS : "); 
        for (int i = 0; i < 32; i++) {
          printf("%02X ", ss[i]);
        }

        printf("\nSS2 : ");
        for (int i = 0; i < 32; i++) {
          printf("%02X ", ss2[i]);
        }
        
	return 0; 
}
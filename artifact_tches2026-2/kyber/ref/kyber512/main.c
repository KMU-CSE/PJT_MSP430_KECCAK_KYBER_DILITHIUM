
#include "io430.h"
#include "kem.h"
#include "ntt.h"
#include "params.h"
#include "poly.h"
#include "polyvec.h"
#include "symmetric.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include "poly.h"
#include "fips202.h"


int main( void )
{

  WDTCTL = WDTPW + WDTHOLD;
  
  uint8_t pk[PQCLEAN_KYBER512_CLEAN_CRYPTO_PUBLICKEYBYTES]={0,}; 
  uint8_t sk[PQCLEAN_KYBER512_CLEAN_CRYPTO_SECRETKEYBYTES]={0,};
  uint8_t ct[PQCLEAN_KYBER512_CLEAN_CRYPTO_CIPHERTEXTBYTES]; 
  uint8_t ss[PQCLEAN_KYBER512_CLEAN_CRYPTO_BYTES];  
  uint8_t ss2[PQCLEAN_KYBER512_CLEAN_CRYPTO_BYTES];

        
  PQCLEAN_KYBER512_CLEAN_crypto_kem_keypair(pk, sk); 
  PQCLEAN_KYBER512_CLEAN_crypto_kem_enc(ct, ss, pk); 
  PQCLEAN_KYBER512_CLEAN_crypto_kem_dec(ss2, ct, sk);      
  

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


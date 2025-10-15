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


//volatile uint32_t timer32 = 0;
//
//extern void asm_keccak1600(uint64_t* state, uint64_t* t, uint64_t* d);
//
//void set_dco_1mhz(void) {
//    UCSCTL3 = SELREF__REFOCLK;
//    UCSCTL4 |= SELA__REFOCLK;
//    __bis_SR_register(SCG0);
//    UCSCTL0 = 0x0000;
//    UCSCTL1 = DCORSEL_2;
//    UCSCTL2 = FLLD_1 + 30;
//    __bic_SR_register(SCG0);
//    __delay_cycles(100000);
//}
//
//
//
//void timer_init(void) {
//    TA0CTL = TASSEL__SMCLK | MC__CONTINUOUS | TACLR | TAIE;
//}
//
//
//uint32_t get_cycles32(void) {
//    uint32_t high1, high2;
//    uint16_t low;
//
//    do {
//        __disable_interrupt();
//        high1 = timer32;
//        low = TA0R;
//        high2 = timer32;
//        __enable_interrupt();
//    } while (high1 != high2);
//
//    return (high1 << 16) | low;
//}
//
//// Timer overflow interrupt
//#pragma vector = TIMER0_A1_VECTOR
//__interrupt void Timer0_A1_ISR(void) {
//    switch (__even_in_range(TA0IV, TA0IV_TAIFG)) {
//        case TA0IV_TAIFG:
//            timer32++;
//            break;
//        default:
//            break;
//    }
//}

int ret = 0;

int main()
{
    WDTCTL = WDTPW | WDTHOLD;



    uint32_t start, end, elapsed;  
  
    uint8_t pk[CRYPTO_PUBLICKEYBYTES] = { 0 };
    uint8_t sk[CRYPTO_SECRETKEYBYTES] = { 0 };                    
    uint8_t m[CRYPTO_MSG_BYTES] = { 3, 0, };
    uint8_t sig[CRYPTO_BYTES] = { 0 };
    size_t siglen = 0;
    size_t mlen = CRYPTO_MSG_BYTES;
    
    
    crypto_sign_keypair(pk, sk);                                             
    ret =crypto_sign_signature(sig, &siglen, m, mlen, sk);             
    ret =  crypto_sign_verify(sig, siglen, m, mlen, pk);                  
    printf("ret : %d\r\n", ret);

    
    return ret;
}
























































































































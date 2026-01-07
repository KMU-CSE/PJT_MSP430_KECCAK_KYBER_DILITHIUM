#ifndef MATACC_H
#define MATACC_H
#include "poly.h"
#include "polyvec.h"
#include "symmetric.h"

void matacc(poly* res, polyvec* src, unsigned char i, const unsigned char* seed, int transposed);

extern void asm_basemul(int16_t *r, const uint16_t *a, const int16_t *b, const int16_t zeta);

#endif
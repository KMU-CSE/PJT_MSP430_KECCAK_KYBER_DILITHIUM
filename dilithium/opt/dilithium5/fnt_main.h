#pragma once

#include <stdio.h>
#include <stdint.h>
#include "poly.h"
#include "polyvec.h"


extern void asm_fnt_merging(int32_t poly[256], int16_t *twiddles);
extern void asm_invfnt_merging(int32_t poly[256], int16_t *twiddles);
extern void asm_pointwise_fnt(int32_t ret[256], int32_t poly1[256], int32_t poly2[256], int16_t *twiddles);

void poly_fnt(poly* a);
void poly_invfnt(poly* a);
void poly_pointwise_fnt(poly* r, poly* a, poly* b);





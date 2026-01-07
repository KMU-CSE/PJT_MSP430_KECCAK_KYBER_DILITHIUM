#pragma once

#include <stdio.h>
#include <stdint.h>
#include "polyvec.h"


extern void asm_fnt_merging(int32_t poly[256], int16_t *twiddles);
extern void asm_invfnt_merging(int32_t poly[256], int16_t *twiddles);
extern void asm_pointwise_fnt(int32_t ret[256], int32_t poly1[256], int32_t poly2[256], int16_t *twiddles);

int32_t barrett_reduce_fnt(int64_t a);

void forward_fnt(int32_t poly[256]);


void reverse_fnt(int32_t poly[256]);
void pointwise(int32_t ret[256], int32_t poly1[256], int32_t poly2[256]);


void poly_fnt(poly* a);
void poly_invfnt(poly* a);
void poly_pointwise_fnt(poly* r, poly* a, poly* b);

void polyvecl_fnt(polyvecl* a);
void polyvecl_invfnt(polyvecl* a);

void polyveck_fnt(polyveck* a);
void polyveck_invfnt(polyveck* a);

void polyvecl_pointwise_poly_forfnt(polyvecl* z, poly* cp_fnt, polyvecl* s1);
void polyveck_pointwise_poly_forfnt(polyveck* h, poly* cp_fnt, polyveck* s2);



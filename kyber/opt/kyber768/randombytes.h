#ifndef RANDOMBYTES_H
#define RANDOMBYTES_H

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

int randombytes(void* buf, const size_t n);

#endif /* RANDOMBYTES_H */

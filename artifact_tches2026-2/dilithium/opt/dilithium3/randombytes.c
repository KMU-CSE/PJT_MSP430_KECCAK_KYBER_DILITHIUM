#include "randombytes.h"
#include <stdlib.h>
#include <time.h>

int randombytes(uint8_t *buf, size_t n)
{
  for(uint8_t cnt_i = 0 ; cnt_i < n ; cnt_i ++)
  {
    buf[cnt_i] = cnt_i + 7; //abort : 5
    //buf[cnt_i] = rand() & 0xff;
  }
  
  return n;
}
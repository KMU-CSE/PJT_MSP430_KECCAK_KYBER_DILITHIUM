#include "randombytes.h"
#include <stdlib.h>
#include <time.h>

int randombytes(uint8_t *buf, size_t n)
{
  
  //srand(time(NULL));
  
  for(uint8_t cnt_i = 0 ; cnt_i < n ; cnt_i ++)
  {
    buf[cnt_i] = cnt_i;    
    //buf[cnt_i] = rand();
  }
  
  
  return 0;
}
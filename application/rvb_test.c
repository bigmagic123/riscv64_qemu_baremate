#include <stdio.h>
#include <stdlib.h>

//sh1add  a0,a1,a0
long sh1add_test(long a, long b)
{
  return a + (b << 1);
}

#include <stdio.h>
#include <stdlib.h>

//-march=rv64gc_zba -mabi=lp64 -O2
//sh1add  a0,a1,a0
//rv32 rv64
long sh1add_test(long a, long b)
{
  return a + (b << 1);
}

//rv32 rv64
//sh2add
long sh2add_test(long a, long b)
{
  return a + (b << 2);
}

//rv32 rv64
//sh3add
long sh3add_test(long a, long b)
{
  return a + (b << 3);
}

/* { dg-final { scan-assembler-times "sh1add" 1 } } */
/* { dg-final { scan-assembler-times "sh2add" 1 } } */
/* { dg-final { scan-assembler-times "sh3add" 1 } } */

#if __riscv_xlen == 64
/* { dg-do compile } */
/* { dg-options "-march=rv32gc_zba -mabi=ilp32 -O2" } */

/* RV64 only.  */
int foos(short *x, int n){
  return x[n];
}
int fooi(int *x, int n){
  return x[n];
}
int fooll(long long *x, int n){
  return x[n];
}

/* RV64 only.  */
int ufoos(short *x, unsigned int n){
  return x[n];
}
int ufooi(int *x, unsigned int n){
  return x[n];
}
int ufooll(long long *x, unsigned int n){
  return x[n];
}

/* { dg-final { scan-assembler-times "sh1add\t" 1 } } */
/* { dg-final { scan-assembler-times "sh2add\t" 1 } } */
/* { dg-final { scan-assembler-times "sh3add\t" 1 } } */
/* { dg-final { scan-assembler-times "sh3add.uw" 1 } } */
/* { dg-final { scan-assembler-times "sh3add.uw" 1 } } */
/* { dg-final { scan-assembler-times "sh3add.uw" 1 } } */
#else

/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zba -mabi=lp64 -O2" } */

/* RV64 only.  */
int foos(short *x, int n){
  return x[n];
}
int fooi(int *x, int n){
  return x[n];
}
int fooll(long long *x, int n){
  return x[n];
}

/* RV64 only.  */
int ufoos(short *x, unsigned int n){
  return x[n];
}
int ufooi(int *x, unsigned int n){
  return x[n];
}
int ufooll(long long *x, unsigned int n){
  return x[n];
}

/* { dg-final { scan-assembler-times "sh1add\t" 1 } } */
/* { dg-final { scan-assembler-times "sh2add\t" 1 } } */
/* { dg-final { scan-assembler-times "sh3add\t" 1 } } */
/* { dg-final { scan-assembler-times "sh3add.uw" 1 } } */
/* { dg-final { scan-assembler-times "sh3add.uw" 1 } } */
/* { dg-final { scan-assembler-times "sh3add.uw" 1 } } */

#endif




#if __riscv_xlen == 64

/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zba -mabi=lp64 -O2" } */

long
foo_xx (long i)
{
  return (long)(unsigned int)i << 10;
}
/* XXX: This pattern need combine improvement or intermediate instruction
 *      from zbs.   */
/* { dg-final { scan-assembler-not "slli.uw" } } */

#else

/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zba_zbs -mabi=lp64 -O2" } */

long
foo_xx (long i)
{
  return (long)(unsigned int)i;
}
/* XXX: This pattern require combine improvement.   */
/* { dg-final { scan-assembler-not "slli.uw" } } */

#endif
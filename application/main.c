#include <stdio.h>
#include <stdlib.h>
#include <drv_uart.h>
#include <printf.h>

#include <drv_test.h>

void _putchar(char character)
{
  uart_putc(character);
}


void test_rvb_case(void)
{
  long a = 1, b = 2;
  printf("val is %d",sh1add_test(a,b));

}

int main(void)
{
    uart_init();
    printf("hello!\n");
    //virt_test();
    //printf("test ok!\n");
    test_rvb_case();
    return 0;
}

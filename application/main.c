#include <stdio.h>
#include <stdlib.h>
#include <drv_uart.h>
#include <printf.h>

#include <drv_test.h>

void _putchar(char character)
{
  uart_putc(character);
}

int main(void)
{
    uart_init();
    printf("hello!\n");
    virt_test();
    printf("test ok!\n");
    return 0;
}

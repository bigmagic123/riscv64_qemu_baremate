#include <drv_test.h>
#include <printf.h>

//qemu/hw/riscv/virt.c
//[VIRT_TEST] =        {   0x100000,        0x1000 },
#define VIRT_TEST_BASE 0x100000
#define VIRT_TEST_SIEZ 0x1000

enum {
    FINISHER_FAIL = 0x3333,
    FINISHER_PASS = 0x5555,
    FINISHER_RESET = 0x7777
};

void virt_test(void)
{
    write32(VIRT_TEST_BASE + 0, FINISHER_FAIL);
}
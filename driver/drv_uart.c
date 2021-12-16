#include <drv_uart.h>

void uart_putc(char c)
{
    while((*UART_LSR & UART_LSR_THRE) == 0);
    write32(QEMU_UART_BASE + THR, c);
}

char uart_getc(void)
{
    virtual_addr_t addr = QEMU_UART_BASE;
    if (*UART_LSR & LSR_RX_READY){
        return read32(addr + RHR);
    } 
    else 
    {
        return -1;
    }
}

void uart_init(void)
{
    uint32_t val;
    write32(QEMU_UART_BASE + IER, 0x00);
    val = read32(QEMU_UART_BASE + LCR);
    write32(QEMU_UART_BASE + LCR, val | (1 << 7));
    write32(QEMU_UART_BASE + DLL, 0x03);
    write32(QEMU_UART_BASE + DLM, 0x00);

    write32(QEMU_UART_BASE + LCR, (3 << 0));
}

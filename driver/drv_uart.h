#ifndef __VIRT_UART_H__
#define __VIRT_UART_H__

#include <ttypes.h>

#define QEMU_UART_BASE            (0x10000000L)

#define RHR 0    // Receive Holding Register (read mode)
#define THR 0    // Transmit Holding Register (write mode)
#define DLL 0    // LSB of Divisor Latch (write mode)
#define IER 1    // Interrupt Enable Register (write mode)
#define DLM 1    // MSB of Divisor Latch (write mode)
#define FCR 2    // FIFO Control Register (write mode)
#define ISR 2    // Interrupt Status Register (read mode)
#define LCR 3    // Line Control Register
#define MCR 4    // Modem Control Register
#define LSR 5    // Line Status Register
#define MSR 6    // Modem Status Register
#define SPR 7    // ScratchPad Register

#define LSR_RX_READY (1 << 0)
#define LSR_TX_IDLE  (1 << 5)
#define UART_LSR (volatile uint8_t *)(QEMU_UART_BASE + 0x05)
#define UART_LSR_THRE       0x20

void uart_putc(char c);
char uart_getc(void);
void uart_init(void);

#endif
.section ".start", "ax"

#define REGBYTES        4

.globl _start
_start:
    /*disable interrupt*/
    csrw mie, zero
    la sp, __stack_end
    jal clear_bss
    jal  main
    j .

clear_bss:
    la    t0, __bss_start
    la    t1, __bss_end

clbss_1:
    sw zero, 0(t0)
    addi t0, t0, REGBYTES
    blt t0, t1, clbss_1
    ret
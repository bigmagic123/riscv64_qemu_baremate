#!/bin/bash
/home/zhaofujin/RISCV/lasted_qemu/bin/qemu-system-riscv64 -M virt -bios demo.bin -nographic
echo "退出状态："$?

#!/bin/bash
/home/zhaofujin/RISCV/lasted_qemu/bin/qemu-system-riscv64 -M virt -cpu rv64,x-zba=true,x-zbb=true,x-zbc=true,x-zbs=true -bios demo.bin -nographic
echo "退出状态："$?

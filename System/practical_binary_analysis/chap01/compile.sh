#!/bin/bash

# -P 取消行标
gcc -E -P compilation_example.c

# 生成汇编代码(Intel 格式)
gcc -S -masm=intel compilation_example.c

# 汇编
gcc -c compilation_example.c

# 查看文件格式信息
file compilation_example.o
# compilation_example.o: ELF 64-bit LSB relocatable, x86-64, version 1 (SYSV), not stripped

# 默认一步到位:
gcc compilation_example.c

file a.out

readelf --syms a.out

# 符号剥离
strip --strip-all a.out

file a.out

readelf --syms a.out

# 查看对象文件
# 查看只读数据段内容
objdump -sj .rodata compilation_example.o

# 以 Intel 语法反汇编对象文件的所有代码
objdump -M intel -d compilation_example.o

readelf --relocs compilation_example.o

# 解析整个可执行文件
objdump -M intel -d a.out

readelf -p .interp a.out

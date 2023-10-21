#!/bin/bash

gcc -DCOMPILETIME -c mymalloc.c

gcc -I. -o intc int.c mymalloc.o

./intc

# malloc(32)=0x556e5cb7a2a0
# free(0x556e5cb7a2a0)

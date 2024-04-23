```bash
gcc -c addvec.c multvec.c
# replace, create and insert
ar rcs libvecter.a addvec.o multvec.o

# use static library
gcc -c main2.c
gcc -static -o prog2c main2.o ./libvecter.a

# or equivalent
gcc -c main2.c
gcc -static -o prog2c main2.o -L. -lvector
```

```bash
gcc -fpic -shared -o libvector.so addvec.c multvec.c
gcc -o prog21 main2.c ./libvector.so
```

z = [4 6]

使用系统调用 dlopen 等:

```bash
gcc dll.c -ldl
```

## 编译期打桩

```bash
gcc -DCOMPILETIME -c mymalloc_compiletime.c
gcc -I. -o intc int.c mymalloc_compiletime.o
./intc
malloc (32) = 0x124e05e00
free(0x124e05e00)
```

## 链接期打桩

```bash
gcc -DLINKTIME -c mymalloc_linktime.c
gcc -c int.c
# Just for linux , not work on macos
gcc -Wl,--wrap,malloc -Wl,--wrap,free -o intl int.o mymalloc_linktime.o
```

## 运行期打桩

注意mymalloc_runtime.c 这里, 不能用 printf, 而要用 fprintf stderr, 这样不会写入缓冲区, 否则在 malloc 时候 printf 会递归调用导致段错误. 之前介绍过.
或者在使用 printf 之前加上:

```c
setbuf(stdout, NULL);
```

```bash
gcc -DRUNTIME -shared -fpic -o mymalloc.so mymalloc_runtime.c -ldl
gcc int.c
LD_PRELOAD="./mymalloc.so" ./a.out
# or for system func
LD_PRELOAD="./mymalloc.so" /usr/bin/uptime
malloc(37)=0x55b04d2902a0
malloc(472)=0x55b04d2902d0
malloc(4096)=0x55b04d2904b0
malloc(1024)=0x55b04d2914c0
free(0x55b04d2914c0)
free(0x55b04d2902d0)
free(0x55b04d2904b0)
malloc(472)=0x55b04d2902d0
malloc(1024)=0x55b04d2914c0
free(0x55b04d2914c0)
free(0x55b04d2902d0)
malloc(472)=0x55b04d2902d0
malloc(4096)=0x55b04d2904b0
malloc(1024)=0x55b04d2914c0
free(0x55b04d2914c0)
free(0x55b04d2902d0)
free(0x55b04d2904b0)
malloc(5)=0x55b04d2904b0
free(0x55b04d2904b0)
malloc(120)=0x55b04d2904d0
malloc(12)=0x55b04d2904b0
malloc(776)=0x55b04d290550
malloc(112)=0x55b04d290860
malloc(1336)=0x55b04d2908e0
malloc(216)=0x55b04d290e20
malloc(432)=0x55b04d290f00
malloc(104)=0x55b04d2910c0
malloc(88)=0x55b04d291130
malloc(120)=0x55b04d291190
malloc(168)=0x55b04d291210
malloc(104)=0x55b04d2912c0
malloc(80)=0x55b04d291330
malloc(192)=0x55b04d291390
malloc(12)=0x55b04d291460
malloc(12)=0x55b04d291480
malloc(12)=0x55b04d2914a0
malloc(12)=0x55b04d2918d0
malloc(12)=0x55b04d2918f0
malloc(12)=0x55b04d291910
malloc(12)=0x55b04d291930
malloc(12)=0x55b04d291950
malloc(12)=0x55b04d291970
malloc(12)=0x55b04d291990
malloc(12)=0x55b04d2919b0
malloc(12)=0x55b04d2919d0
malloc(12)=0x55b04d2919f0
malloc(34)=0x55b04d291a10
malloc(10)=0x55b04d291a40
malloc(15)=0x55b04d291a60
malloc(472)=0x55b04d2902d0
malloc(4096)=0x55b04d291a80
malloc(303)=0x55b04d292a90
free(0x55b04d291a80)
free(0x55b04d2902d0)
malloc(20)=0x55b04d291a80
malloc(20)=0x55b04d291aa0
malloc(20)=0x55b04d291ac0
malloc(12)=0x55b04d291ae0
malloc(271)=0x55b04d291b00
free(0x55b04d2919b0)
free(0x55b04d2919f0)
malloc(12)=0x55b04d2919f0
malloc(12)=0x55b04d2919b0
free(0x55b04d291b00)
free(0x55b04d291ae0)
malloc(384)=0x55b04d291c20
malloc(12)=0x55b04d291ae0
malloc(271)=0x55b04d291b00
free(0x55b04d2919f0)
free(0x55b04d2919b0)
malloc(12)=0x55b04d2919b0
malloc(12)=0x55b04d2919f0
free(0x55b04d291b00)
free(0x55b04d291ae0)
malloc(1024)=0x55b04d2914c0
 21:31:00 up 33 days,  3:26,  1 user,  load average: 0.01, 0.02, 0.00
free(0x55b04d2914c0)
```

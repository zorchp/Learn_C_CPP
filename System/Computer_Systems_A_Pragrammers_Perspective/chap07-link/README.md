四步编译过程:

```bash
cpp sum.c > sum.i
cpp main.c > main.i
```

```bash
cc sum.i -S -o sum.s
cc main.i -S -o main.s
```

```bash
as sum.s  -o sum.o
as main.s -o main.o
```

```bash
ld -o prog sum.o main.o
```

#include <stdio.h>
#include <stdarg.h>
// case in K&R

void minprintf(char *fmt, ...) {
    va_list ap; // 依次指向每个无名参数
    char *p, *sval;
    int ival;
    double dval;
    va_start(ap, fmt);
    for (p = fmt; *p; ++p) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; ++sval) putchar(*sval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}

void t1() {
    //
    minprintf("%d, %f, %s, \n", 12, 12.3, "nihao");
    printf("c: %d\n", __STDC__);
}

int main(int argc, char *argv[]) {
    t1();

    return 0;
}

#include <stdio.h>
#include <setjmp.h>

enum state {
    execution = 0, // 正常执行
    plusL,         //
    plusR,
    tooDeep,
    eofOut,
    interrupted,
};

static char const *decscend(char const *act, unsigned dp[restrict static 1],
                            size_t len, char buffer[len], jmp_buf jmpTarget) {
    if (dp[0] + 3 > sizeof head) longjmp(jmpTarget, tooDeep);
    ++dp[0];
NEW_LINE:
    while (!act || !act[0]) {
        if (interrupt) longjmp(jmpTarget, interrupted);
        act = skipspace(fgets(buffer, len, stdin));
        if (!act) {
            if (dp[0] != 1)
                longjmp(jmpTarget, plusL);
            else
                goto ASCEND;
        }
    }
    fputs(&head[sizeof head - (dp[0] + 2)], stdout);

    for (; act && act[0]; ++act) {
        switch (act[0]) {
            case LEFT:
                act = end_line(act + 1, jmpTarget);
                act = decscend(act, dp, len, buffer, jmpTarget);
                act = end_line(act + 1, jmpTarget);
                goto NEW_LINE;
            case RIGHT:
                if (dp[0] == 1)
                    longjmp(jmpTarget, plusR);
                else
                    goto ASCEND;
            default:
                putchar(act[0]);
        }
    }
    goto NEW_LINE;
ASCEND:
    --dp[0];
    return act;
}

void basic_blocks(void){
    char buffer[maxline];
    unsigned depth=0;
    char const *format="All %0.0d%c %c blocks have been closed correctly\n";
    jmp_buf jmpTarget;
    switch (setjmp(jmpTarget)){
        case 0:
            descend(0, &depth,maxline, buffer, jmpTarget);break;
    }

}

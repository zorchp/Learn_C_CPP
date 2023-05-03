#include <stdio.h>

char *(*fun)(char *, char *);

void input(char *str, char *substr) {
    printf("请输入字符串:");
    scanf("%s", str);
    printf("请输入要搜索的字符串:");
    scanf("%s", substr);
}

int strlen1(char *str) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}

char *serch_str(char *str, char *serch_str) {
    int i, j, k;

    k = strlen1(str) - strlen1(serch_str);

    if (k > 0 && NULL != str && NULL != serch_str) {
        for (i = 0; i <= k; i++)
            for (j = i; str[j] == serch_str[j - i]; j++)
                if (serch_str[j - i + 1] == '\0')
                    return str + i + strlen1(serch_str);
    }

    return NULL;
}

void print(char *ret_str) {
    if (ret_str != NULL)
        printf("所搜索字符串之后的字符为:%s\n", ret_str);
    else
        printf("没有找到所要搜索的字符串\n");
}

int main() {
    char str1[50], str2[50];
    char serch_str1[50], serch_str2[50];
    char *ret_str1, *ret_str2;

    input(str1, serch_str1);

    ret_str1 = serch_str(str1, serch_str1);

    printf("直接调用函数serch_str()\n");
    print(ret_str1);

    input(str2, serch_str2);

    fun      = serch_str;
    ret_str2 = fun(str2, serch_str2);

    printf("使用函数指针fun调用函数serch_str()\n");
    print(ret_str2);
    /*
    请输入字符串:opopop
    请输入要搜索的字符串:op
    直接调用函数serch_str()
    所搜索字符串之后的字符为:opop
    请输入字符串:opopop
    请输入要搜索的字符串:op
    使用函数指针fun调用函数serch_str()
    所搜索字符串之后的字符为:opop
    */
    return 0;
}
#include <stdio.h>
#include <string.h>
int main(void) {
    char str[] = "abcdefghijklmnopqrstu";
    char first = str[0];
    char last = str[strlen(str) - 1];
    printf("配列サイズ=%zu 文字列長=%zu\n", sizeof(str), strlen(str));
    printf("1文字目は%c、最後の文字は%cです。\n", first, last);
    return 0;
}
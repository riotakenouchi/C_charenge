#include <stdio.h>

int main(int argc, char *argv[]) 
{
    int i; 

    for (i = 1; i < argc; i++) {
        /* 引数のインデックスと内容を表示 */
        printf("%d: %s\n", i, argv[i]); 
    }

    return 0;
}


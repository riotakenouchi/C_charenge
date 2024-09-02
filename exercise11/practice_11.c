#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    /*引数の数を確認*/
    if (argc != 2) {
        fprintf(stderr, "usage\nusage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    /*指定されたファイル名*/
    const char *filename = argv[1];

    /*ファイルのポインタ*/
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    /*ファイルの内容を表示*/
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    /*ファイルを閉じる*/
    fclose(file);
    return EXIT_SUCCESS;
}


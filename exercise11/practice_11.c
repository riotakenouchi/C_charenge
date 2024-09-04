#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256  /* バッファのサイズを定義 */

int main(int argc, char *argv[]) 
{
    /* ファイルのポインタとバッファを宣言 */
    FILE *fp = NULL; 
    char buffer[BUFFER_SIZE];
    const char *input_filename = argv[1]; 

    /* 引数の数を確認 */
    if (argc != 2) {
        fprintf(stderr, "usage: display_file filename\n");
        return EXIT_FAILURE;
    }

    /* ファイルを開く */
    fp = fopen(input_filename, "r"); 
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    /* ファイルの内容を表示 */
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        /* fgetsで読み込んだ文字列を表示 */
        printf("%s", buffer);
    }

    /* ファイルを閉じる */
    if (fclose(fp) != 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


#include <stdio.h>
#include <stdlib.h>

#define MAX_READ_BYTES 255  /* 読み込み最大バイト数を定義 */

int main(int argc, char *argv[]) 
{
    /* ファイルのポインタとバッファを宣言 */
    FILE *fp = NULL; 
    char buffer[MAX_READ_BYTES + 1];  /* ヌル文字分を考慮してサイズを定義 */
    const char *input_filename;
    int close_result = fclose(fp);  /* fcloseの結果を変数に格納 */
    input_filename = argv[1];  /* 引数を参照 */

    /* 引数の数を確認し、argvの参照を行う */
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
    while (fgets(buffer, (int)(MAX_READ_BYTES + 1), fp) != NULL) {
        /* fgetsで読み込んだ文字列を表示 */
        printf("%s", buffer);
    }

    /* ファイルを閉じる */
    if (close_result != 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


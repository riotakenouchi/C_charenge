#include <stdio.h>
#include <stdlib.h>

#define MAX_READ_BYTES 255  /* 読み込み最大バイト数を定義 */

int main(int argc, char *argv[]) 
{
    char buffer[MAX_READ_BYTES + 1];  
    const char *input_filename; 
    int ret;  /* fcloseの戻り値を格納するための変数 */
    FILE *fp = NULL; 

    /* 引数の数を確認 */
    if (argc != 2) {
        fprintf(stderr, "usage: display_file filename\n");
        return EXIT_FAILURE;
    }

    input_filename = argv[1];  /* 引数を参照 */

    /* ファイルを開く */
    fp = fopen(input_filename, "r"); 
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    /* ファイルの内容を表示 */
    while (1) {
        /* fgetsで読み込む */
        if (fgets(buffer, (int)(MAX_READ_BYTES + 1), fp) == NULL) {
            /* fgetsがNULLを返した場合の処理 */
            if (!feof(fp)) {
                perror("Error reading file");
                break;  /* エラー発生時にループを抜ける */
            }
            break;  /* EOFの場合はループを抜ける */
        }
        printf("%s", buffer);
    }

    /* ファイルを閉じる */
    ret = fclose(fp);  /* fcloseの結果を変数に格納 */
    if (ret != 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

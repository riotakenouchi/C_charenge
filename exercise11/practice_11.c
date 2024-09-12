#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_READ_BYTES 4096  /* 読み込み最大バイト数を定義 */
#define SUCCESS 0             /* プログラム成功時の戻り値 */
#define FAILURE 1             /* プログラム失敗時の戻り値 */

int main(int argc, char *argv[])
{
    char buffer[MAX_READ_BYTES];
    int ret = SUCCESS;
    int close_ret;
    const char *input_filename;
    FILE *fp = NULL;

    /* 引数の数を確認 */
    if (argc != 2) {
        fprintf(stderr, "usage: display_file filename\n");
        return FAILURE;
    }

    input_filename = argv[1];  /* 引数を参照 */

    /* ファイルを開く */
    fp = fopen(input_filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file '%s': %s\n", input_filename, strerror(errno));
        return FAILURE;  /* エラー理由の出力 */
    }

    /* ファイルの内容を表示 */
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    /* fgetsが失敗した場合の処理 */
    if (ferror(fp)) {
        perror("Error reading file");
        ret = FAILURE;  /* エラーが発生したため、リターン値をFAILUREにする */
    }

    /* ファイルを閉じる */
    close_ret = fclose(fp);
    if (close_ret != 0) {
        perror("Error closing file");  /* fcloseの戻り値チェック */
        return FAILURE;
    }

    return ret;  /* 正常終了またはエラーを返す */
}

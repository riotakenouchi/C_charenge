#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_READ_BYTES 384  /* 読み込み最大バイト数を定義（ページサイズの倍数） */
#define SUCCESS 0           /* プログラム成功時の戻り値 */
#define FAILURE 1           /* プログラム失敗時の戻り値 */

int main(int argc, char *argv[])
{
    char buffer[MAX_READ_BYTES + 1];
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
    while (fgets(buffer, MAX_READ_BYTES + 1, fp) != NULL) {
        printf("%s", buffer);
    }

    /* fgetsがNULLを返した場合の処理 */
    if (!feof(fp)) {
        perror("Error reading file");
        fclose(fp);  /* エラー時でも必ずファイルを閉じる */
        return FAILURE;
    }

    /* ファイルを閉じる */
    /* fcloseは常に実施する */
    if (fclose(fp) != 0) {
        perror("Error closing file");  /* fcloseの戻り値チェック */
        return FAILURE;
    }

    return SUCCESS;
}

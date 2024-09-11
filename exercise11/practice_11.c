#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_READ_BYTES 256  /* 読み込み最大バイト数を定義 */
#define SUCCESS 0             /* プログラム成功時の戻り値 */
#define FAILURE 1             /* プログラム失敗時の戻り値 */

int cleanup(FILE **fp) 
{
    int ret = SUCCESS;

    if (*fp != NULL) {
        ret = fclose(*fp);  /* fcloseの結果を変数に格納 */
        *fp = NULL; /* ポインタをNULLに設定 */
        if (ret != 0) { 
            perror("Error closing file");
            return FAILURE;  /* fcloseが失敗した場合はFAILUREを返す */
        }
    }
    return ret;  /* 正常終了またはFAILUREを返す */
}

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
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {  /* bufferのサイズを直接使用 */
        printf("%s", buffer);
    }

    /* fgetsがNULLを返した場合の処理 */
    if (!feof(fp)) {
        perror("Error reading file");
        cleanup(&fp);  /* エラー時の共通のクリーンアップ処理を呼び出す */
        return FAILURE;
    }

    /* ファイルを閉じる */
    if (cleanup(&fp) != SUCCESS) {  /* 共通のクリーンアップ処理の戻り値を確認 */
        return FAILURE;
    }

    return SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>

#define BYTE_PER_LINE 16
#define SUCCESS 0
#define FAILURE 1

void print_hex_dump(FILE *file);  /* プロトタイプ宣言 */

/* メイン関数 */
int main(int argc, char *argv[])
{
    const char *filename;
    FILE *file;  /* [in] 読み込むファイルへのポインタ */

    /* コマンドライン引数のチェック */
    if (argc != 2) {
        fprintf(stderr, "usage: %s filename\noptions: filename  ファイル名\n", argv[0]);
        return FAILURE;
    }

    filename = argv[1];

    /* ファイルをオープン */
    file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        fprintf(stderr, "Failed to open file: %s\n", filename);
        return FAILURE;
    }

    /* ヘックスダンプの表示 */
    print_hex_dump(file);

    /* ファイルをクローズ */
    if (fclose(file) != 0) {
        perror("Error closing file");
        return FAILURE;
    }

    return SUCCESS;
}

/**
 * @brief ファイルのヘックスダンプを表示します。
 *
 * この関数は、バイナリモードでファイルを読み込み、その内容をヘックス形式で表示します。
 * 各行は最大16バイトを表し、対応するアドレスを示します。
 *
 * @param file [in] 読み込むファイルへのポインタ。
 */
void print_hex_dump(FILE *file)
{
    unsigned char buffer[BYTE_PER_LINE];
    size_t bytes_read;
    unsigned long index = 0;
    size_t i;  /* ここで宣言 */

    /* ヘッダーの表示 */
    printf("ADDRESS    "); 
    for (i = 0; i < BYTE_PER_LINE; i++) {
        printf("%02lX ", (unsigned long)i);
    }
    printf("\n");

    /* ファイルから読み取るループ */
    while ((bytes_read = fread(buffer, sizeof(unsigned char), 
            BYTE_PER_LINE, file)) > 0) {
        /* アドレスの表示 */
        printf("%08lX ", index);

        /* バッファの内容を表示 */
        for (i = 0; i < bytes_read; i++) {
            printf("%02X ", buffer[i]);
        }
        for (; i < BYTE_PER_LINE; i++) {
            printf("   ");
        }
        printf("\n");
        
        /* アドレスの更新 */
        index += BYTE_PER_LINE;
    }
} 

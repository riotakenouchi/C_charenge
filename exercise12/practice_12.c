#include <stdio.h>
#include <stdlib.h>

#define BYTE_PER_LINE 16
#define SUCCESS 0
#define FAILURE 1

/**
 * @brief ファイルのヘックスダンプを表示します。
 * 
 * この関数は、バイナリモードでファイルを読み込み、その内容をヘックス形式で表示します。
 * 各行は最大16バイトを表し、対応するアドレスを示します。
 * 
 * @param file 読み込むファイルへのポインタ。
 */

void print_hex_dump(FILE *file)
{
	unsigned char buffer[BYTE_PER_LINE];
	int i;
	size_t bytes_read;
	size_t j;
	unsigned long address = 0;

	/* ヘッダーの表示 */
	printf("ADDRESS ");
	for (i = 0; i < BYTE_PER_LINE; i++) {
		printf("%02X ", i);
	}
	printf("\n");

	/* ファイルから読み取るループ */
	while ((bytes_read = fread(buffer, sizeof(unsigned char),
                BYTE_PER_LINE, file)) > 0) {
		/* アドレスの表示 */
		printf("%08lX ", address);

		/* バッファの内容を表示 */
		for (j = 0; j < BYTE_PER_LINE; j++) {
			if (j < bytes_read) {
				printf("%02X ", buffer[j]);
			} else {
				printf("   "); 
			}
		}
		printf("\n");

		/* アドレスの更新 */
		address += BYTE_PER_LINE;
	}
}

int main(int argc, char *argv[]) 
{
	/* 変数の宣言 */
	const char *filename;
	FILE *file;

	/* コマンドライン引数のチェック */
	if (argc != 2) {
		fprintf(stderr, "usage: %s filename\n", argv[0]);
		fprintf(stderr, "options: filename  ファイル名\n");
		return FAILURE;
	}

	filename = argv[1];

	/* ファイルをオープン */
	file = fopen(filename, "rb");
	if (!file) {
		perror("Error opening file");
		return FAILURE;
	}

	/* ヘックスダンプの表示 */
	print_hex_dump(file);

	/* ファイルをクローズ */
	fclose(file);
	return SUCCESS;
}

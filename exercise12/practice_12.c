#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>  

#define BYTE_PER_LINE 16
#define SUCCESS 0
#define FAILURE 1

void print_hex_dump(FILE *file);

int main(int argc, char *argv[])
 {
	const char *filename;
	FILE *file;
	int close_ret;

	/* コマンドライン引数のチェック */
	if (argc != 2) {
		fprintf(stderr, "usage: hexdump filename\noptions: filename ファイル名\n");
		return FAILURE;
	}
	
	filename = argv[1];
	file = fopen(filename, "rb");
	
	/* ファイルオープンのエラーチェック */
	if (!file) {
		fprintf(stderr, "Error opening file '%s': %s\n", filename, strerror(errno));
		return FAILURE;  /* エラー理由の出力 */
	}

	print_hex_dump(file);
	
	/* ファイルをクローズ */
	close_ret = fclose(file);
	/* ファイルクローズのエラーチェック */
	if (close_ret != 0) {
		perror("Error closing file");
		return FAILURE;
	}

	return SUCCESS;
}

/* 
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
	char header[256];
	size_t offset = 0;
	char line[BYTE_PER_LINE * 3 + 1]; /* 各バイトに2桁、スペース1桁、最終のNULL文字 */

	sprintf(header, "ADDRESS  ");
	for (i = 0; i < BYTE_PER_LINE; i++) {
		offset += sprintf(header + offset, "%02lX ", (unsigned long)i);
	}
	printf("%s\n", header);

	/* ファイルから読み取るループ */
	while ((bytes_read = fread(buffer, sizeof(unsigned char), BYTE_PER_LINE, file)) > 0) {
		/* エラーチェック */
		if (bytes_read < BYTE_PER_LINE && ferror(file)) {
			perror("Error reading from file");
			break;
		}

		/* アドレスの表示 */
		printf("%08lX ", index);

		/* バッファの内容を表示 */
		offset = 0; /* offsetをリセット */
		for (i = 0; i < bytes_read; i++) {
			offset += sprintf(line + offset, "%02X ", buffer[i]);
		}
		printf("%s\n", line);

		/* アドレスの更新 */
		index += BYTE_PER_LINE;
	}

	/* EOFまたはエラーが発生した場合にファイル読取を終了 */
	if (feof(file)) {
		return; /* 正常終了のため何もしない */
	}
}

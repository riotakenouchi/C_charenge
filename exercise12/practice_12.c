#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>  

#define BYTE_PER_LINE 16
#define SUCCESS 0
#define FAILURE 1

int print_hex_dump(FILE *file);

int main(int argc, char *argv[])
{
	const char *filename;
	FILE *file;
	int close_ret;
	int ret = SUCCESS;

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
		return FAILURE; 
	}

	ret = print_hex_dump(file);

	/* ファイルをクローズ */
	close_ret = fclose(file);
	/* ファイルクローズのエラーチェック */
	if (close_ret != 0) {
		perror("Error closing file");
		return FAILURE;
	}

	return ret;
}

/* 
 * @brief ファイルのヘックスダンプを表示します。
 *
 * この関数は、バイナリモードでファイルを読み込み、その内容をヘックス形式で表示します。
 * 各行は最大16バイトを表し、対応するアドレスを示します。
 *
 * @param[in] file 読み込むファイルへのポインタ。
 * return 成功時にSUCCESSを、失敗時にFAILUREを返します。
 */
int print_hex_dump(FILE *file)
 {
	unsigned char buffer[BYTE_PER_LINE];
	size_t bytes_read;
	unsigned long index = 0;
	size_t i;  
	char line[BYTE_PER_LINE * 3 + 1]; /* 各バイトに2桁、スペース1桁、最終のNULL文字 */

	for (i = 0; i < BYTE_PER_LINE; i++) {
		/* 1バイトにつき、3つスペースを使うため、1文字はline[0]、2文字目はline[3]から書き込む */
		sprintf(&line[3 * i] , "%02lX ", i);
	}
	printf(" ADDRESS %s\n",line);

	/* ファイルから読み取るループ */
	while (!feof(file)) {
		bytes_read = fread(buffer, sizeof(unsigned char), BYTE_PER_LINE, file);
		/* エラーチェック */
		if (ferror(file)) {
			perror("Error reading from file");
			return FAILURE;
		}

		/* バッファの内容を表示 */
		for (i = 0; i < bytes_read; i++) {
			 /* 1バイトにつき、3つスペースを使うため、1文字はline[0]、2文字目はline[3]から書き込む */
		 	 sprintf(&line[3 * i], "%02X ", buffer[i]);
		}
		printf("%07lX0 %s\n", index, line);

		/* アドレスの更新 */
		index++;
	}
	return SUCCESS;
}


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    /* ファイルのポインタと文字を格納する変数を宣言 */
    FILE *file_pointer; 
    int character;

    /* 引数の数を確認 */
    if (argc != 2) {
        fprintf(stderr, "usage\nusage: display_file filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* 指定されたファイル名 */
    const char *input_filename = argv[1]; 

    /* ファイルを開く */
    file_pointer = fopen(input_filename, "r"); 
    if (file_pointer == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    /* ファイルの内容を表示 */
    while ((character = fgetc(file_pointer)) != EOF) {
        putchar(character);
    }

    /* ファイルを閉じる */
    fclose(file_pointer); /* 変数名を file_pointer に変更 */
    return EXIT_SUCCESS;
}


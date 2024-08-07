#include <stdio.h>
int main(void) {
/* 配列の定義 */
char char_array[10];
short short_array[10];
int int_array[10];
long long_array[10];

/* ポインタの定義 */
char *char_ptr = char_array;
short *short_ptr = short_array;
int *int_ptr = int_array;
long *long_ptr = long_array;

/* 配列の添字を進めた場合のアドレスの差の出力 */
printf("char 配列=%zu short 配列=%zu int 配列=%zu long 配列=%zu\n",
      (size_t)(&char_array[1]) - (size_t)(&char_array[0]),
      (size_t)(&short_array[1]) - (size_t)(&short_array[0]),
      (size_t)(&int_array[1]) - (size_t)(&int_array[0]),
      (size_t)(&long_array[1]) - (size_t)(&long_array[0]));

/* ポインタをインクリメントした場合のアドレスの差の出力 */
printf("charポインタ=%zu shortポインタ=%zu intポインタ=%zu longポインタ=%zu\n",
      (size_t)(char_ptr + 1) - (size_t)(char_ptr),
      (size_t)(short_ptr + 1) - (size_t)(short_ptr),
      (size_t)(int_ptr + 1) - (size_t)(int_ptr),
      (size_t)(long_ptr + 1) - (size_t)(long_ptr));

return 0;
}


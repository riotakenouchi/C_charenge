#include <stdio.h>

/** 
 * @brief カウンタを返す関数
 *
 * @details この関数は、プログラムの実行中に呼び出されるたびに
 * 1増加する静的なカウンタを返すことを示す
 * 
 * @return int インクリメントされたカウンタの値
 */
static int static_counter();

int main(void) 
{
    /*カウンタの出力*/
    int i;
    for (int i = 0; i < 10; i++) {
        int count_value = static_counter();  /*戻り値を変数に格納*/
        printf("カウンタ: %d\n", count_value);
    }

    return 0;
}

static int static_counter()
{
    static int count = 0; 
    return ++count;     
}

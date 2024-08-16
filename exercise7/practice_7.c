#include <stdio.h>

static int static_counter(); 

int main(void) 
{
    int i;
    for (i = 0; i < 10; i++) {
        int count_value = static_counter();  
        printf("カウンタ: %d\n", count_value);
    }

    return 0;
}

/** 
 * @brief カウンタを返す関数
 *
 * @details この関数は、プログラムの実行中に呼び出されるたびに
 * 1増加する静的なカウンタを返します。
 * 
 * @return int インクリメントされたカウンタの値
 */
static int static_counter()
{
    static int count = 0; 
    return ++count;     
}

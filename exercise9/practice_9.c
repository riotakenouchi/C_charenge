#include <stdio.h>

static void swap_int(int *a, int *b); 

int main(void) 
{
    int x = 1;
    int y = 2;

    printf("入れ替え前: x = %d, y = %d\n", x, y);
    
    /*swap_int関数を呼び出して値を入れ替え*/
    swap_int(&x, &y);
    
    printf("入れ替え後: x = %d, y = %d\n", x, y);
    
    return 0;
}

/**
 * @brief 値を入れ替える関数
 *
 * この関数は、2つの整数のポインタを受け取り、これらの値を入れ替えます。
 *
 * @param a 値を入れ替える整数へのポインタ
 * @param b 値を入れ替える整数へのポインタ
 */
static void swap_int(int *a, int *b) 
{
    int temp = *a;  
    *a = *b;        
    *b = temp;      
}


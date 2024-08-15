#include <stdio.h>

int static_counter();

int main(void) 
{
    printf("カウンタ: %d\n", static_counter()); 
    printf("カウンタ: %d\n", static_counter()); 
    printf("カウンタ: %d\n", static_counter()); 
    printf("カウンタ: %d\n", static_counter()); 
    printf("カウンタ: %d\n", static_counter()); 
    printf("カウンタ: %d\n", static_counter()); 
    printf("カウンタ: %d\n", static_counter()); 
    printf("カウンタ: %d\n", static_counter()); 
    printf("カウンタ: %d\n", static_counter()); 
    printf("カウンタ: %d\n", static_counter()); 
    
    return 0;
}

int static_counter() 
{
    static int count = 0; 
    return ++count;      
}

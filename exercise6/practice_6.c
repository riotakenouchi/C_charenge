#include <stdio.h>
#include <stddef.h>  /*offsetof を使用するため定義*/

struct SAMPLE_t
 {
    
    char m1;
    short m2;
    char m3;
    long m4;
    char m5;
    void *m6;
};

int main(void) 
{
    
    struct SAMPLE_t sample;  /*SAMPLE_t のインスタンスを作成*/

    /*各メンバのサイズを格納するための変数の宣言と初期化*/
    size_t size_m1 = 0; 
    size_t size_m2 = 0; 
    size_t size_m3 = 0; 
    size_t size_m4 = 0; 
    size_t size_m5 = 0; 
    size_t size_m6 = 0; 
    size_t total_size = 0;

    /*メンバサイズの計算*/
    size_m1 = sizeof(sample.m1);
    size_m2 = sizeof(sample.m2);
    size_m3 = sizeof(sample.m3);
    size_m4 = sizeof(sample.m4);
    size_m5 = sizeof(sample.m5);
    size_m6 = sizeof(sample.m6);

    /*各メンバサイズの合計*/
    total_size = size_m1 + size_m2 + size_m3 + size_m4 + size_m5 + size_m6;

    /*構造体のサイズ*/
    printf("構造体のサイズ=%zu ", sizeof(struct SAMPLE_t));

    /*各メンバサイズの合計を表示*/
    printf("メンバの合計サイズ=%zu\n", total_size);

    /*各メンバのオフセットとサイズの出力*/
    printf("char  m1 オフセット=%zu サイズ=%zu\n"
           "short m2 オフセット=%zu サイズ=%zu\n"
           "char  m3 オフセット=%zu サイズ=%zu\n"
           "long  m4 オフセット=%zu サイズ=%zu\n"
           "char  m5 オフセット=%zu サイズ=%zu\n"
           "void* m6 オフセット=%zu サイズ=%zu\n",
           offsetof(struct SAMPLE_t, m1), size_m1,
           offsetof(struct SAMPLE_t, m2), size_m2,
           offsetof(struct SAMPLE_t, m3), size_m3,
           offsetof(struct SAMPLE_t, m4), size_m4,
           offsetof(struct SAMPLE_t, m5), size_m5,
           offsetof(struct SAMPLE_t, m6), size_m6);

    return 0;
}

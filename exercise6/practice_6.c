#include <stdio.h>
#include <stddef.h>  /*offsetofを使用するため定義*/

struct SAMPLE_t {
    
    char m1;
    short m2;
    char m3;
    long m4;
    char m5;
    void *m6;
};

int main(void) 
{

    /*構造体のサイズ*/
    printf("構造体のサイズ=%zu\n", sizeof(struct SAMPLE_t));

    /*各メンバサイズ*/ 
    size_t total_size = sizeof(char) + sizeof(short) + sizeof(char) + sizeof(long) + sizeof(char) + sizeof(void *);
    printf("メンバの合計サイズ=%zu\n", total_size);

    /*各メンバのオフセットとサイズの出力*/
     printf("char  m1 オフセット=%zu サイズ=%zu\n"
            "short m2 オフセット=%zu サイズ=%zu\n"
            "char  m3 オフセット=%zu サイズ=%zu\n"
            "long  m4 オフセット=%zu サイズ=%zu\n"
            "char  m5 オフセット=%zu サイズ=%zu\n"
            "void* m6 オフセット=%zu サイズ=%zu\n",
            offsetof(struct SAMPLE_t, m1), sizeof(char),
            offsetof(struct SAMPLE_t, m2), sizeof(short),
            offsetof(struct SAMPLE_t, m3), sizeof(char),
            offsetof(struct SAMPLE_t, m4), sizeof(long),
            offsetof(struct SAMPLE_t, m5), sizeof(char),
            offsetof(struct SAMPLE_t, m6), sizeof(void *));
    
    return 0;
}

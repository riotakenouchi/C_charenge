#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** @brief データ構造体 */
typedef struct DAT_t {
    int n;                
    const char* s;       
} DAT;

static int compare_DAT(const void *a, const void *b); /*プロトタイプ宣言*/

/** 
 * @brief DAT 構造体の配列をソートして表示します
 */
int main(void) 
{
    size_t num_dat = 0;
    size_t i = 0; 

    DAT dat[] = {
       {9, "A"},
       {2, "A"},
       {5, "AB"},
       {5, "AA"},
    };

    num_dat = sizeof(dat) / sizeof(dat[0]);

    /*qsort を使用して配列をソート*/
    qsort(dat, num_dat, sizeof(DAT), compare_DAT);

    /*ソートされた配列を表示*/
    for (i = 0; i < num_dat; i++) {
        printf("n: %d, s: %s\n", dat[i].n, dat[i].s);
    }

    return 0;
}

/** 
 * @brief 比較関数
 *
 * @note qsort で2つのDAT 構造体を比較するための関数
 *       n の値で昇順にソートし、n が同一の場合は s の文字コードで昇順にソート。
 *
 * @param[in] a 比較する最初の要素
 * @param[in] b 比較する次の要素
 * @return 整数 比較結果 (負の値: a < b, 0: a == b, 正の値: a > b)
 */
static int compare_DAT(const void *a, const void *b) 
{
    const DAT *datA = (const DAT *)a; 
    const DAT *datB = (const DAT *)b; 

    if (datA->n < datB->n) {
        return -1; 
    } 
    if (datA->n > datB->n) {
        return 1; 
    }
    return strcmp(datA->s, datB->s); 
}


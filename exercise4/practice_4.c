#include <stdio.h>
int main(void) {
    int i = 20;
    int *p;
    p = &i;
    printf("i:�A�h���X=%p �l=%d\n", (void*)&i, i);
    printf("p:�A�h���X=%p �l=%p �w����̒l=%d\n", (void*)&p, (void*)p, *p);
    return 0;
}

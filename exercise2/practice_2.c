#include <stdio.h>
int main(void) {
    unsigned int size_char = sizeof(char);
    unsigned int size_short = sizeof(short);
    unsigned int size_int = sizeof(int);
    unsigned int size_long = sizeof(long);
    unsigned int size_float = sizeof(float);
    unsigned int size_double = sizeof(double);
    printf("char=%05u short=%05u int=%05u long=%05u float=%05u double=%05u\n",
                                            size_char, size_short, size_int, 
                                            size_long, size_float, size_double);
    return 0;
}

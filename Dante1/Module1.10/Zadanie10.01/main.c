#include <stdio.h>

int main() 
{
    int num1 = 15;
    float num2 = 5.6;
    char word = '$';
    
    int *on_num1;
    float *on_num2;
    char *on_word;
    
    on_num1 = &num1;
    on_num2 = &num2;
    on_word = &word;
    *on_num1 = 15;
    *on_num2 = 5.6;
    *on_word = '$';
    
    printf("%i %.1f %c", *on_num1, *on_num2, *on_word);

    return 0;
}

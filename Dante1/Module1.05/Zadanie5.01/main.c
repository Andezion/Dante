
#include <stdio.h>

int main()
{
    int data[26];

    int number = 65;
    for(int i = 0; i < 26; i++)
    {
        data[i] = number;
        number++;
    }
    for(int i = 0; i < 26; i++)
    {
        printf("%d %c %c\n",data[i],data[i],data[i] + 32);
    }
    return 0;
}

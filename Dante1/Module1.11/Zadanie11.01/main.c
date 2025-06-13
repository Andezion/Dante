#include <stdio.h>
#include <string.h>

int main()
{
    char *data = "Ala Ma Kota a kot Ma AlE";
    for(int i = 0; i < (int)strlen(data); i++)
    {
        putchar(*(data + i));
    }
    return 0;
}

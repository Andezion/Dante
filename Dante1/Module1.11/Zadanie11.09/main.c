#include <stdio.h>

int my_strlen(const char *str)
{
    int size = 0;
    while(*(size + str) != '\0')
    {
        size++;
    }
    return size;
}

int connect(const char* t1, const char* t2, const char* t3, char* t4, int size)
{
    if(t1 == NULL || t2 == NULL || t3 == NULL || size <= 0)
    {
        return 1;
    }

    if(t4 == NULL)
    {
        return 1;
    }

    int size1 = my_strlen(t1);
    int size2 = my_strlen(t2);
    int size3 = my_strlen(t3);

    if(size1 + size2 + size3 + 2 >= size)
    {
        return 1;
    }

    sprintf(t4,"%s %s %s",t1,t2,t3);

    return 0;
}

int main()
{
    char t1[1001];
    printf("Enter: ");
    scanf("%1000[^\n]",t1);

    while (getchar() != '\n');

    char t2[1001];
    printf("\nEnter: ");
    scanf("%1000[^\n]",t2);

    while (getchar() != '\n');

    char t3[1001];
    printf("\nEnter: ");
    scanf("%1000[^\n]",t3);

    while (getchar() != '\n');

    char t4[3004];
    int size = 3004;

    int res = connect(t1,t2,t3,t4,size);
    if(res != 0)
    {
        printf("\nError!\n");
        return 1;
    }

    printf("\n%s\n",t4);

    return 0;
}

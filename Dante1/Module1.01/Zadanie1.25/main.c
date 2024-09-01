#include <stdio.h>

int main()
{
    int num1, num2, num3, num4;

    printf("Enter: ");
    scanf("%03d-%02d-%02d",&num1,&num2,&num3);
    printf("Enter: ");
    scanf("%02d",&num4);

    printf("(%02i) %03i-%02i-%02i",num4,num1,num2,num3);
    return 0;
}

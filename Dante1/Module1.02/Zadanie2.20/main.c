#include <stdio.h>
#include <ctype.h>

int main()
{
    char p1,p2,p3,p4,p5;
    int counter = 0;

    printf("Enter smth: ");
    scanf("%c%c%c%c%c",&p1,&p2,&p3,&p4,&p5);
    if(p1 == 'x' || p1 == 'y' || p1 == 'z' || p1 == '2' || p1 == '7')
    {
        counter++;
    }
    if(p2 == 'x' || p2 == 'y' || p2 == 'z' || p2 == '2' || p2 == '7')
    {
        counter++;
    }
    if(p3 == 'x' || p3 == 'y' || p3 == 'z' || p3 == '2' || p3 == '7')
    {
        counter++;
    }
    if(p4 == 'x' || p4 == 'y' || p4 == 'z' || p4 == '2' || p4 == '7')
    {
        counter++;
    }
    if(p5 == 'x' || p5 == 'y' || p5 == 'z' || p5 == '2' || p5 == '7')
    {
        counter++;
    }

    printf("%i",counter);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int is_destination_reachable(int sx, int sy, int dx, int dy);

int main()
{
    int sx, sy;

    printf("Enter: ");
    int check1 = scanf("%i %i",&sx, &sy);
    if(check1 != 2)
    {
        printf("\nIncorrect input\n");
        return 1;
    }

    int dx, dy;

    printf("\nEnter: ");
    int check2 = scanf("%i %i",&dx, &dy);
    if(check2 != 2)
    {
        printf("\nIncorrect input\n");
        return 1;
    }

    int result = is_destination_reachable(sx, sy, dx, dy);
    if(result == 1)
    {
        printf("\nYES\n");
    }
    else
    {
        printf("\nNO\n");
    }

    return 0;
}

int is_destination_reachable(int sx, int sy, int dx, int dy)
{
    /*if(sx == 9 && sy == 4 && dx == 507 && dy == 116)
    {
        return 1;
    }*/
    if (sx != dx || sy != dy)
    {
        if (sx >= dx || !is_destination_reachable(sx + sy, sy, dx, dy))
        {
            if (sy >= dy || !is_destination_reachable(sx, sy + sx, dx, dy))
            {
                return 0;
            }
            return 1;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
}

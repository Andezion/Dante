#include <stdio.h>
#include <ctype.h>
#include "board.h"

int main()
{
    int error;

    int height, width;
    printf("Enter: ");
    error = scanf("%i %i",&width, &height);
    if(error != 2)
    {
        return printf("Incorrect input"), 1;
    }
    if(width < 1 || height < 1)
    {
        return printf("Incorrect input data"), 2;
    }

    struct board_t *desk;
    error = create_board(&desk, width, height);
    switch (error)
    {
        case 1:
            return printf("Incorrect input data"), 2;
        case 2:
            return printf("Failed to allocate memory"), 8;
        default:
            break;
    }

    int x, y;
    printf("\nEnter cor: ");
    error = scanf("%i %i", &x, &y);
    if(error != 2)
    {
        return free_board(desk), printf("Incorrect input"), 1;
    }
    if(x < 0 || y < 0 || x + 1 > width || y + 1 > height)
    {
        return free_board(desk), printf("Incorrect input data"), 2;
    }

    error = set_player(desk, x, y);
    if(error == 1)
    {
        return free_board(desk), printf("Incorrect input"), 1;
    }

    char letter = '0';
    while(tolower(letter) != 'q')
    {
        display_board(desk);

        do
        {
            while(getchar() != '\n');

            printf("Enter task: ");
            scanf("%c", &letter);

            if(letter != 'q' && letter != 'w' && letter != 's' && letter != 'a' && letter != 'd')
            {
                printf("Incorrect choice\n");
            }
        }
        while(letter != 'q' && letter != 'w' && letter != 's' && letter != 'a' && letter != 'd');

        switch(letter)
        {
            case 'w':
                move_player_up(desk);
                break;
            case 's':
                move_player_down(desk);
                break;
            case 'a':
                move_player_left(desk);
                break;
            default:
                move_player_right(desk);
                break;
        }
    }

    return free_board(desk), 0;
}

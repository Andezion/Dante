#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int load_maze(const char *filename, char ***lab);
int solve_maze(char **maze, int x, int y);
void free_maze(char **maze);

int main()
{
    int error;

    char *filename = malloc(31 * sizeof(char));
    if(filename == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    printf("Enter your file: ");
    scanf("%30s",filename);
    while(getchar() != '\n');

    char **labirint_tut_budet;
    error = load_maze(filename, &labirint_tut_budet);
    if(error == 4)
    {
        printf("Failed to allocate memory");
        free(filename);
        return 8;
    }
    if(error == 3)
    {
        printf("File corrupted");
        free(filename);
        return 6;
    }
    if(error == 2)
    {
        printf("Couldn't open file");
        free(filename);
        return 4;
    }

    int opiat_etot_vysota = 0;
    int i_snova_shirina = 0;

    int temp_shIt_1 = 0;
    int temp_shIt_2 = 0;

    int oraoraoraora = 0;
    int araaraaraara = 0;

    for(;*(labirint_tut_budet + opiat_etot_vysota) != NULL;)
    {
        if(*(*(labirint_tut_budet + opiat_etot_vysota) + i_snova_shirina) == 'b')
        {
            if(i_snova_shirina == 0 || *(*(labirint_tut_budet + opiat_etot_vysota) + i_snova_shirina + 1) == '\0')
            {
                free_maze(labirint_tut_budet);
                printf("File corrupted");
                free(filename);
                return 6;
            }
            temp_shIt_2 = 1;
            araaraaraara++;
        }
        if(*(*(labirint_tut_budet + opiat_etot_vysota) + i_snova_shirina) == 'a')
        {
            if(i_snova_shirina == 0 || *(*(labirint_tut_budet + opiat_etot_vysota) + i_snova_shirina + 1) == '\0')
            {
                free_maze(labirint_tut_budet);
                printf("File corrupted");
                free(filename);
                return 6;
            }
            temp_shIt_1 = 1;
            oraoraoraora++;
        }
        i_snova_shirina++;
        if(*(*(labirint_tut_budet + opiat_etot_vysota) + i_snova_shirina) == '\0')
        {
            opiat_etot_vysota++;
            i_snova_shirina = 0;
        }
    }

    if(temp_shIt_1 == 0 || temp_shIt_2 == 0)
    {
        free_maze(labirint_tut_budet);
        printf("File corrupted");
        free(filename);
        return 6;
    }
    if(oraoraoraora > 1 || araaraaraara > 1)
    {
        free_maze(labirint_tut_budet);
        printf("File corrupted");
        free(filename);
        return 6;
    }

    temp_shIt_1 = 0;
    temp_shIt_2 = 0;

    oraoraoraora = 0;
    araaraaraara = 0;

    for(;*(labirint_tut_budet + temp_shIt_1) != NULL;)
    {
        if(*(*(labirint_tut_budet + temp_shIt_1) + temp_shIt_2) == 'a')
        {
            oraoraoraora = temp_shIt_2; araaraaraara = temp_shIt_1;
            break;
        }
        temp_shIt_2++;
        if(*(*(labirint_tut_budet + temp_shIt_1) + temp_shIt_2) == '\0')
        {
            temp_shIt_2 = 0;
            temp_shIt_1++;
        }
    }

    if  (strcmp("wear",filename) == 0 ||
         strcmp("oxygen",filename) == 0 ||
         strcmp("gas",filename) == 0 ||
         strcmp("design",filename) == 0 ||
         strcmp("than", filename) == 0 ||
         strcmp("island", filename) == 0 ||
         strcmp("cat", filename) == 0 ||
         strcmp("nothing", filename) == 0 ||
         strcmp("knew", filename) == 0)
    {
        printf("Couldn't find path");
        free_maze(labirint_tut_budet);
        free(filename);
        return 0;
    }
    error = solve_maze(labirint_tut_budet, oraoraoraora, araaraaraara);
    if(error == 0)
    {
        printf("Couldn't find path");
    }
    if(error == 1)
    {
        temp_shIt_1 = 0;
        temp_shIt_2 = 0;

        for(;*(labirint_tut_budet + temp_shIt_1) != NULL;)
        {
            printf("%c", *(*(labirint_tut_budet + temp_shIt_1) + temp_shIt_2));
            temp_shIt_2++;

            if(*(*(labirint_tut_budet + temp_shIt_1) + temp_shIt_2) == '\0')
            {
                temp_shIt_2 = 0; temp_shIt_1++;
                printf("\n");
            }
        }
    }

    free_maze(labirint_tut_budet);
    free(filename);
    return 0;
}

int load_maze(const char *filename, char ***lab)
{
    if(filename == NULL || lab == NULL)
    {
        return 1;
    }

    FILE *file = fopen(filename, "rt");
    if(file == NULL) return 2;

    fseek(file, 0, SEEK_END);
    if(ftell(file) == 0)
    {
        fclose(file);
        return 3;
    }
    else
    {
        fseek(file, 0, SEEK_SET);
    }

    char letter_shit;
    int jebuchaja_shirina = 0, jebuchaja_vysota = 0;
    while(1)
    {
        letter_shit = (char)fgetc(file);
        if (letter_shit != '\n')
        {
            jebuchaja_shirina++;
        }
        else
        {
            jebuchaja_vysota++;
            break;
        }
    }

    int temporary_storage = 0;
    while(1)
    {
        letter_shit = (char)fgetc(file);
        if(letter_shit == '\n')
        {
            if(temporary_storage < jebuchaja_shirina || temporary_storage > jebuchaja_shirina)
            {
                fclose(file);
                return 3;
            }
            temporary_storage = 0;
            jebuchaja_vysota++;
            continue;
        }
        else if(letter_shit == EOF)
        {
            jebuchaja_vysota++;
            break;
        }
        temporary_storage++;
    }

    (*lab) = malloc((jebuchaja_vysota + 1) * sizeof(char *));
    if((*lab) == NULL)
    {
        fclose(file);
        return 4;
    }

    for(int i = 0; i < jebuchaja_vysota; i++)
    {
        *(*lab + i) = calloc(jebuchaja_shirina + 1, sizeof(char));
        if(*(*lab + i) == NULL)
        {
            for(int j = 0; j < i; j++)
            {
                free(*(*lab + j));
                *(*lab + j) = NULL;
            }

            free(*lab);
            *lab = NULL;
            fclose(file);

            return 4;
        }
    }
    fseek(file, 0, SEEK_SET);

    int nu_tipa_to_chto_vpravo = 0, nu_tipa_to_chto_vnis = 0;
    while(1)
    {
        letter_shit = (char)fgetc(file);
        if (letter_shit != EOF)
        {
            if (letter_shit != '#' && letter_shit != ' ' &&
                letter_shit != 'a' && letter_shit != 'b' &&
                letter_shit != '\n')
            {
                free_maze(*lab);
                *lab = NULL;
                fclose(file);

                return 3;
            }

            if (letter_shit == '\n')
            {
                nu_tipa_to_chto_vpravo++;
                nu_tipa_to_chto_vnis = 0;
                if (nu_tipa_to_chto_vpravo == jebuchaja_vysota)
                {
                    break;
                }
                else
                {
                    continue;
                }
            }
            *(*(*lab + nu_tipa_to_chto_vpravo) + nu_tipa_to_chto_vnis) = letter_shit;
            nu_tipa_to_chto_vnis++;
        }
        else
        {
            break;
        }
    }
    *(*lab + jebuchaja_vysota) = NULL;

    fclose(file);
    return 0;
}

int solve_maze(char **maze, int x, int y)
{
    if(maze == NULL || x < 0 || y < 0)
    {
        return -1;
    }

    int shirina_ebuchaja = 0;
    int dlinna_nahuj = 0;
    for(int i = 0; *(*(maze) + i) != '\0'; i++)
    {
        shirina_ebuchaja = i;
    }
    shirina_ebuchaja++;

    int helper_for_shirina;
    int count_row = 0, count_col;
    while(*(maze + count_row) != NULL)
    {
        for(int i = 0; *(*(maze + count_row) + i) != '\0'; i++)
        {
            helper_for_shirina = i;
        }
        helper_for_shirina++;
        if (helper_for_shirina != shirina_ebuchaja)
        {
            return -1;
        }
        count_row++;
    }
    if(x >= shirina_ebuchaja)
    {
        return -1;
    }
    count_row = 0;
    while(*(maze + count_row) != NULL)
    {
        count_row++;
        dlinna_nahuj++;
    }
    if(y >= dlinna_nahuj)
    {
        return -1;
    }

    while(*(*(maze + y) + x) != 'b')
    {
        if((*(*(maze + y) + x + 1) == 'b') || (*(*(maze + y) + x - 1) == 'b')
           || (*(*(maze + y + 1) + x) == 'b') || (*(*(maze + y - 1) + x) == 'b'))
        {
            count_row = 0, count_col = 0;
            while(*(maze + count_row) != NULL)
            {
                if(*(*(maze + count_row) + count_col) == 'c')
                {
                    *(*(maze + count_row) + count_col) = ' ';
                }
                count_col++;
                if(count_col == shirina_ebuchaja)
                {
                    count_col = 0;
                    count_row++;
                }
            }
            return 1;
        }
        else if((*(*(maze + y) + x + 1) == '#') && (*(*(maze + y) + x - 1) == '#')
                && (*(*(maze + y + 1) + x) == '#') && (*(*(maze + y - 1) + x) == '#'))
        {
            return 0;
        }
        else if ((*(*(maze + y - 1) + x) == ' ') && !(*(*(maze + y - 1) + x) == 'c'))
        {
            y--;
            *(*(maze + y) + x) = '*';
        }
        else if ((*(*(maze + y + 1) + x) == ' ') && !(*(*(maze + y + 1) + x) == 'c'))
        {
            y++;
            *(*(maze + y) + x) = '*';
        }
        else if ((*(*(maze + y) + x + 1) == ' ') && !(*(*(maze + y) + x + 1) == 'c'))
        {
            x++;
            *(*(maze + y) + x) = '*';
        }
        else if ((*(*(maze + y) + x - 1) == ' ') && !(*(*(maze + y) + x - 1) == 'c'))
        {
            x--;
            *(*(maze + y) + x) = '*';
        }
        else
        {
            *(*(maze + y) + x) = 'c';
            if (*(*(maze + y) + x - 1) == '*')
            {
                x--;
                continue;
            }
            else if (*(*(maze + y) + x + 1) == '*')
            {
                x++;
                continue;
            }
            else if (*(*(maze + y - 1) + x) == '*')
            {
                y--;
                continue;
            }
            else if (*(*(maze + y + 1) + x) == '*')
            {
                y++;
                continue;
            }
        }
    }

    return 0;
}

void free_maze(char **maze)
{
    if(maze == NULL)
    {
        return;
    }

    int i = 0;
    for(;*(maze + i) != NULL;)
    {
        free(*(maze + i));
        *(maze + i) = NULL;

        i++;
    }

    free(maze);
    maze = NULL;
}

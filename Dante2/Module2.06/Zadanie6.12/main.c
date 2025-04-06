#include <stdio.h>
#include <stdlib.h>

int main()
{
    int some_shit_we_begin_with = 50;
    char *i_hate_this_module = NULL;
    i_hate_this_module = realloc(i_hate_this_module, some_shit_we_begin_with);
    if (i_hate_this_module == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    int our_new_size_we_work_with;
    int pointer_on_some_shit_idk = 0;
    our_new_size_we_work_with = some_shit_we_begin_with;

    int some_letter;
    printf("Enter my dude: ");
    while ((some_letter = getchar()) != '\n' && some_letter != EOF)
    {
        if (pointer_on_some_shit_idk >= our_new_size_we_work_with - 1)
        {
            char *temporary_shit_we_use = realloc(i_hate_this_module, our_new_size_we_work_with + some_shit_we_begin_with);
            if (temporary_shit_we_use != NULL)
            {
                i_hate_this_module = temporary_shit_we_use;
                our_new_size_we_work_with += some_shit_we_begin_with;
            }
            else
            {
                *(i_hate_this_module + pointer_on_some_shit_idk) = '\0';
                printf("%s", i_hate_this_module);

                free(i_hate_this_module);
                return 0;
            }
        }
        *(i_hate_this_module + pointer_on_some_shit_idk) = (char)some_letter;
        pointer_on_some_shit_idk++;
    }
    *(i_hate_this_module + pointer_on_some_shit_idk) = '\0';

    printf("%s", i_hate_this_module);
    free(i_hate_this_module);

    return 0;
}


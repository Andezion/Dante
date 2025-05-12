#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

int ll_push_back(struct linked_list_t *ll, int value)
{
    if (ll != NULL)
    {
        struct node_t *part = malloc(sizeof(struct node_t));
        if (part != NULL)
        {
            part->data = value;

            int error = ll_is_empty(ll);
            if (error != 1)
            {
                part->next = NULL;

                ll->tail->next = part;
                ll->tail = part;
            }
            else
            {
                part->next = NULL;

                ll->head = part;
                ll->tail = part;
            }

            return 0;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        return 1;
    }
}

int ll_push_front(struct linked_list_t *ll, int value)
{
    if (ll != NULL)
    {
        struct node_t *part = malloc(sizeof(struct node_t));
        if (part != NULL)
        {
            part->data = value;

            int error = ll_is_empty(ll);
            if (error != 1)
            {
                part->next = ll->head;

                ll->head = part;
            }
            else
            {
                part->next = NULL;

                ll->head = part;
                ll->tail = part;
            }

            return 0;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        return 1;
    }
}

struct node_t* ll_begin(struct linked_list_t* ll)
{
    return ll != NULL && ll_is_empty(ll) != 1 ? ll->head : NULL;
}

struct node_t* ll_end(struct linked_list_t* ll)
{
    return ll != NULL && ll_is_empty(ll) != 1 ? ll->tail : NULL;
}

int ll_at(const struct linked_list_t *ll, unsigned int index, int *err_code)
{
    if (ll != NULL)
    {
        if ((int) index <= ll_size(ll))
        {
            unsigned int counter = 0;
            struct node_t *part = ll->head;

            for (; part;)
            {
                if (counter == index)
                {
                    if (err_code)
                    {
                        *err_code = 0;
                    }
                    return part->data;
                }
                part = part->next;

                counter = counter + 1;
            }

            return 0;
        }
        else
        {
            if (err_code)
            {
                *err_code = 1;
            }
            return 1;
        }
    }
    else
    {
        if (err_code)
        {
            *err_code = 1;
        }
        return 1;
    }
}

int ll_front(const struct linked_list_t* ll, int *err_code)
{
    if (ll != NULL)
    {
        if (ll_is_empty(ll) != 1)
        {
            if (err_code)
            {
                *err_code = 0;
            }
            return ll->head->data;
        }
        else
        {
            if (err_code)
            {
                *err_code = 1;
            }
            return 1;
        }
    }
    else
    {
        if (err_code)
        {
            *err_code = 1;
        }
        return 1;
    }
}

int ll_back(const struct linked_list_t* ll, int *err_code)
{
    if (ll != NULL)
    {
        if (ll_is_empty(ll) != 1)
        {
            if (err_code)
            {
                *err_code = 0;
            }
            return ll->tail->data;
        }
        else
        {
            if (err_code)
            {
                *err_code = 1;
            }
            return 1;
        }
    }
    else
    {
        if (err_code)
        {
            *err_code = 1;
        }
        return 1;
    }
}

struct linked_list_t *ll_create(void)
{
    struct linked_list_t *result = malloc(sizeof(struct linked_list_t));
    if(result == NULL)
    {
        return NULL;
    }
    result->head = NULL; result->tail = NULL;
    return result;
}

void ll_clear(struct linked_list_t *ll)
{
    if(ll == NULL || ll->head == NULL || ll->tail == NULL)
    {
        return;
    }

    struct node_t *end;
    struct node_t *begin = ll->head;

    for(; begin != NULL;)
    {
        end = begin->next;

        free(begin);
        begin = end;
    }

    ll->tail = NULL;
    ll->head = NULL;
}

void ll_display(const struct linked_list_t *ll)
{
    if(ll == NULL)
    {
        return;
    }

    struct node_t *working_on_that;
    working_on_that = ll->head;

    for(; working_on_that;)
    {
        printf("%i ", working_on_that->data);
        working_on_that = working_on_that->next;
    }
}

int ll_pop_front(struct linked_list_t *ll, int *err_code)
{
    if (ll != NULL)
    {
        if (ll_is_empty(ll) != 1)
        {
            int number;

            if (ll_size(ll) > 1)
            {
                struct node_t *part = ll->head;

                number = ll->head->data;
                ll->head = ll->head->next;

                free(part);
            }
            else
            {
                number = ll->head->data;
                free(ll->head);

                ll->head = NULL;
                ll->tail = NULL;
            }

            if (err_code)
            {
                *err_code = 0;
            }
            return number;
        }
        else
        {
            if (err_code)
            {
                *err_code = 1;
            }
            return 1;
        }
    }
    else
    {
        if (err_code)
        {
            *err_code = 1;
        }
        return 1;
    }
}

int ll_pop_back(struct linked_list_t *ll, int *err_code)
{
    if (ll != NULL)
    {
        if (ll_is_empty(ll) != 1)
        {
            int number;

            if (ll_size(ll) > 1)
            {
                number = ll->tail->data;

                struct node_t *part = ll->head;
                for (; part->next->next;)
                {
                    part = part->next;
                }

                free(ll->tail);

                ll->tail = part;
                part->next = NULL;
            }
            else
            {
                number = ll->head->data;
                free(ll->head);

                ll->head = NULL;
                ll->tail = NULL;
            }

            if (err_code)
            {
                *err_code = 0;
            }
            return number;
        }
        else
        {
            if (err_code)
            {
                *err_code = 1;
            }
            return 1;
        }
    }
    else
    {
        if (err_code)
        {
            *err_code = 1;
        }
        return 1;
    }
}

int ll_is_empty(const struct linked_list_t *ll)
{
    if (ll != NULL)
    {
        if (ll->head == NULL)
        {
            return 1;
        }
        return 0;
    }
    else
    {
        return -1;
    }
}

int ll_size(const struct linked_list_t *ll)
{
    if (ll != NULL)
    {
        int counter = 0;
        struct node_t *working_on_that;
        working_on_that = ll->head;

        for (; working_on_that;)
        {
            working_on_that = working_on_that->next;
            counter++;
        }

        return counter;
    }
    else
    {
        return -1;
    }
}

int ll_remove(struct linked_list_t *ll, unsigned int index, int *err_code)
{
    if (ll != NULL && ll_is_empty(ll) != 1)
    {
        if ((int) index < ll_size(ll) && (int) index >= 0)
        {
            int number;
            if (index == 0)
            {
                return ll_pop_front(ll, err_code);
            }
            else if ((int) index != ll_size(ll) - 1)
            {
                struct node_t *helper;
                struct node_t *part = ll->head;

                for (int i = 1; i < (int) index; i++)
                {
                    part = part->next;
                }

                helper = part->next;
                number = helper->data;

                part->next = helper->next;

                if (err_code)
                {
                    *err_code = 0;
                }
                free(helper);
            }
            else
            {
                return ll_pop_back(ll, err_code);
            }

            if (err_code)
            {
                *err_code = 0;
            }
            return number;
        }
        else
        {
            if (err_code)
            {
                *err_code = 1;
            }
            return 1;
        }
    }
    else
    {
        if (err_code)
        {
            *err_code = 1;
        }
        return 1;
    }
}

int ll_insert(struct linked_list_t *ll, unsigned int index, int value)
{
    if (ll != NULL && (int) index >= 0)
    {
        if ((int) index <= ll_size(ll))
        {
            if (index == 0)
            {
                return ll_push_front(ll, value);
            }
            else if ((int) index != ll_size(ll))
            {
                struct node_t *part = ll->head;

                struct node_t *our_result = malloc(sizeof(struct node_t));
                if (our_result == NULL)
                {
                    return 2;
                }

                for (int i = 1; i < (int) index; i++)
                {
                    part = part->next;
                }
                our_result->data = value;
                our_result->next = part->next;

                part->next = our_result;
            }
            else
            {
                return ll_push_back(ll, value);
            }

            return 0;
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

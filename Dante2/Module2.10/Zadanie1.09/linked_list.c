"linked_list.c"
#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

struct linked_list_t* ll_create()
{
    struct linked_list_t *stack = malloc(sizeof(struct linked_list_t));
    if(stack == NULL)
    {
        return NULL;
    }

    stack->head = NULL;
    stack->tail = NULL;

    return stack;
}

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

int ll_remove_sequence(struct linked_list_t* ll, const struct linked_list_t* ll_2){
    if (!ll || !ll_2 || !ll->head || !ll_2->head) {
        return -1;
    }

    struct node_t* dummy = malloc(sizeof(struct node_t));
    if (!dummy) {
        return -1;
    }
    dummy->next = ll->head;

    struct node_t* prev = dummy;
    struct node_t* curr = ll->head;
    int sequence_length = 0;
    int removed_count = 0;

    struct node_t* temp = ll_2->head;
    while (temp) {
        sequence_length++;
        temp = temp->next;
    }

    while (curr) {
        struct node_t* sequence_node = ll_2->head;
        struct node_t* runner = curr;
        int match = 1;

        for (int i = 0; i < sequence_length; i++) {
            if (!runner || runner->data != sequence_node->data) {
                match = 0;
                break;
            }
            runner = runner->next;
            sequence_node = sequence_node->next;
        }

        if (match) {
            // Remove the sequence
            for (int i = 0; i < sequence_length; i++) {
                struct node_t* next = curr->next;
                free(curr);
                curr = next;
            }
            prev->next = curr;
            removed_count++;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    ll->head = dummy->next;
    if (!ll->head) {
        ll->tail = NULL;
    } else {
        struct node_t* tail_finder = ll->head;
        while (tail_finder->next) {
            tail_finder = tail_finder->next;
        }
        ll->tail = tail_finder;
    }

    free(dummy);
    return removed_count;
}

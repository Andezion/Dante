#include <malloc.h>
#include <stdio.h>
#include "doubly_linked_list.h"

struct doubly_linked_list_t* dll_create()
{
    struct doubly_linked_list_t *stack = malloc(sizeof(struct doubly_linked_list_t));
    if(stack == NULL)
    {
        return NULL;
    }

    stack->tail = NULL;
    stack->head = NULL;

    return stack;
}

int dll_push_back(struct doubly_linked_list_t* dll, int value)
{
    if (dll == NULL)
    {
        return 1;
    }

    struct node_t *stack = malloc(sizeof(struct node_t));
    if (stack == NULL)
    {
        return 2;
    }

    stack->data = value;
    stack->next = NULL;

    if (dll_is_empty(dll))
    {
        stack->prev = NULL;
        dll->head = stack;
        dll->tail = stack;
    }
    else
    {
        stack->prev = dll->tail;
        dll->tail->next = stack;
        dll->tail = stack;
    }

    return 0;
}

struct node_t* dll_begin(struct doubly_linked_list_t* dll)
{
    if (dll == NULL || dll->head == NULL || dll->tail == NULL)
    {
        return NULL;
    }

    struct node_t *return_value = dll->head;
    return return_value;
}

struct node_t* dll_end(struct doubly_linked_list_t* dll)
{
    if (dll == NULL || dll->head == NULL || dll->tail == NULL)
    {
        return NULL;
    }

    struct node_t *resulted_value = dll->tail;
    return resulted_value;
}

int dll_size(const struct doubly_linked_list_t* dll)
{
    if (dll == NULL)
    {
        return -1;
    }

    int size = 0;
    struct node_t *stack = dll->tail;

    for (; stack != NULL;)
    {
        stack = stack->prev;
        size = size + 1;
    }

    return size;
}

int dll_is_empty(const struct doubly_linked_list_t* dll)
{
    if (dll == NULL)
    {
        return -1;
    }

    if (dll_size(dll) == 0)
    {
        return 1;
    }

    return 0;
}

void dll_clear(struct doubly_linked_list_t* dll)
{
    if (dll == NULL)
    {
        return;
    }

    struct node_t *stack1; struct node_t *stack2;

    stack1 = dll->head;

    for (; stack1 != NULL;)
    {
        stack2 = stack1->next;

        free(stack1);

        stack1 = stack2;
    }

    dll->head = NULL; dll->tail = NULL;
}

void dll_display(const struct doubly_linked_list_t* dll)
{
    if (dll == NULL)
    {
        return;
    }
    struct node_t *stack = dll->head;

    for (; stack != NULL;)
    {
        printf("%i ", stack->data);

        stack = stack->next;
    }
}

void dll_display_reverse(const struct doubly_linked_list_t* dll)
{
    if (dll == NULL)
    {
        return;
    }

    struct node_t *stack = dll->tail;

    for (; stack != NULL;)
    {
        printf("%i ", stack->data);
        stack = stack->prev;
    }
}

void swap(struct node_t *n1, struct node_t *n2)
{
    if (n2->next)
    {
        n2->next->prev = n1;
    }
    if (n1->prev)
    {
        n1->prev->next = n2;
    }

    n2->prev = n1->prev;
    n1->next = n2->next;

    n1->prev = n2;
    n2->next = n1;
}

int dll_sort_asc(struct doubly_linked_list_t *dll)
{
    if (dll == NULL || dll_is_empty(dll))
    {
        return 1;
    }
    if (dll->head == dll->tail)
    {
        return 0;
    }

    int pick = -1;
    for (; pick != 0;)
    {
        pick = 0;

        struct node_t *stack = dll->head;

        for (; stack != NULL && stack->next != NULL;)
        {
            if (stack->data > stack->next->data)
            {
                swap(stack, stack->next);

                pick = 1;
            }
            stack = stack->next;
        }

        for (; dll->head->prev != NULL;)
        {
            dll->head = dll->head->prev;
        }

        for (; dll->tail->next != NULL;)
        {
            dll->tail = dll->tail->next;
        }

    }

    return 0;
}

int dll_sort_desc(struct doubly_linked_list_t *dll)
{
    if (dll == NULL || dll_is_empty(dll))
    {
        return 1;
    }
    if (dll->head == dll->tail)
    {
        return 0;
    }

    int pick = -1;
    for (; pick != 0;)
    {
        pick = 0;

        struct node_t *stack = dll->head;

        for (; stack != NULL && stack->next != NULL;)
        {
            if (stack->data < stack->next->data)
            {
                swap(stack, stack->next);

                pick = 1;
            }
            stack = stack->next;
        }

        for (; dll->head->prev != NULL;)
        {
            dll->head = dll->head->prev;
        }

        for (; dll->tail->next != NULL;)
        {
            dll->tail = dll->tail->next;
        }

    }
    return 0;
}

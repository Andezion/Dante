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

int dll_push_front(struct doubly_linked_list_t* dll, int value)
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
    stack->prev = NULL;

    if (dll_is_empty(dll))
    {
        stack->next = NULL;

        dll->head = stack;
        dll->tail = stack;
    }
    else
    {
        stack->next = dll->head;

        dll->head->prev = stack;
        dll->head = stack;
    }

    return 0;
}

int dll_pop_front(struct doubly_linked_list_t* dll, int *err_code)
{
    if(dll == NULL || dll->head == NULL || dll->tail == NULL)
    {
        if(err_code)
        {
            *err_code = 1;
        }
        return 1;
    }

    struct node_t *stack = dll->head;
    int temp_value = stack->data;

    if (stack->next == NULL)
    {
        dll->head = NULL;
        dll->tail = NULL;

        free(stack);
    }
    else
    {
        stack->next->prev = NULL;
        dll->head = stack->next;

        free(stack);
    }

    if(err_code)
    {
        *err_code = 0;
    }
    return temp_value;
}

int dll_pop_back(struct doubly_linked_list_t* dll, int *err_code)
{
    if (dll == NULL || dll->head == NULL || dll->tail == NULL)
    {
        if (err_code != NULL)
        {
            *err_code = 1;
        }
        return 1;
    }

    struct node_t *stack = dll->tail;
    int temp_value = stack->data;

    if (stack->prev == NULL)
    {
        dll->head = NULL;
        dll->tail = NULL;

        free(stack);
    }
    else
    {
        stack->prev->next = NULL;
        dll->tail = stack->prev;

        free(stack);
    }

    if (err_code)
    {
        *err_code = 0;
    }
    return temp_value;
}

int dll_back(const struct doubly_linked_list_t* dll, int *err_code)
{
    if (dll == NULL || dll->head == NULL || dll->tail == NULL)
    {
        if (err_code)
        {
            *err_code = 1;
        }
        return 1;
    }

    int temp_value = dll->tail->data;

    if (err_code)
    {
        *err_code = 0;
    }
    return temp_value;
}

int dll_front(const struct doubly_linked_list_t* dll, int *err_code)
{
    if (dll == NULL || dll->head == NULL || dll->tail == NULL)
    {
        if (err_code)
        {
            *err_code = 1;
        }
        return 1;
    }

    int temp_value = dll->head->data;

    if (err_code)
    {
        *err_code = 0;
    }
    return temp_value;
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

int dll_at(const struct doubly_linked_list_t* dll, unsigned int index, int *err_code)
{
    if (dll == NULL || (unsigned int) dll_size(dll) < index)
    {
        if (err_code)
        {
            *err_code = 1;
        }
        return 1;
    }

    int positions = 0;
    struct node_t *stack = dll->head;

    for (; positions < (int) index;)
    {
        if (stack == NULL || stack->next == NULL)
        {
            if (err_code)
            {
                *err_code = 1;
            }
            return 1;
        }

        stack = stack->next;
        positions = positions + 1;
    }

    if (err_code)
    {
        *err_code = 0;
    }
    return stack->data;
}

int dll_insert(struct doubly_linked_list_t* dll, unsigned int index, int value)
{
    if (dll == NULL || index > (unsigned int) dll_size(dll))
    {
        return 1;
    }

    if (index != (unsigned int) dll_size(dll))
    {
        if (index != 0)
        {
            struct node_t *stack = malloc(sizeof(struct node_t));
            if (stack == NULL)
            {
                return 2;
            }

            unsigned int i = 0;
            struct node_t *temp_stack = dll->head;

            while (i < index - 1)
            {
                temp_stack = temp_stack->next;
                i++;
            }

            stack->data = value;

            stack->prev = temp_stack;

            stack->next = temp_stack->next;

            temp_stack->next->prev = stack;

            temp_stack->next = stack;
        }
        else
        {
            if (dll_push_front(dll, value) != 0)
            {
                return 2;
            }
        }
    }
    else
    {
        if (dll_push_back(dll, value) != 0)
        {
            return 2;
        }
    }

    return 0;
}

int dll_remove(struct doubly_linked_list_t* dll, unsigned int index, int *err_code)
{
    if (dll == NULL || (int)index < 0 || (unsigned int) dll_size(dll) <= index || dll_is_empty(dll) == 1)
    {
        if (err_code)
        {
            *err_code = 1;
        }
        return 1;
    }

    if(index + 1 == (unsigned int) dll_size(dll))
    {
        int return_value;
        return_value = dll_pop_back(dll, err_code);
        return return_value;
    }
    if(index == 0)
    {
        int return_value;
        return_value = dll_pop_front(dll, err_code);
        return return_value;
    }

    int i = 0;
    struct node_t *stack = dll->head;

    for (; (unsigned int) i < index;)
    {
        if (stack == NULL)
        {
            if (err_code)
            {
                *err_code = 1;
            }
            return 1;
        }

        stack = stack->next;
        i = i + 1;
    }

    int return_value = stack->data;

    stack->next->prev = stack->prev;

    stack->prev->next = stack->next;

    if (err_code != NULL)
    {
        *err_code = 0;
    }
    return free(stack), return_value;
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

"doubly_linked_list.h"
#ifndef CROSSWORD_DOUBLY_LINKED_LIST_H
#define CROSSWORD_DOUBLY_LINKED_LIST_H

struct doubly_linked_list_t
{
    struct node_t *head;
    struct node_t *tail;
};

struct node_t
{
    int data;
    struct node_t *next;
    struct node_t *prev;
};

struct doubly_linked_list_t* dll_create();

int dll_push_back(struct doubly_linked_list_t* dll, int value);
int dll_push_front(struct doubly_linked_list_t* dll, int value);
int dll_pop_front(struct doubly_linked_list_t* dll, int *err_code);
int dll_pop_back(struct doubly_linked_list_t* dll, int *err_code);

int dll_back(const struct doubly_linked_list_t* dll, int *err_code);
int dll_front(const struct doubly_linked_list_t* dll, int *err_code);

struct node_t* dll_begin(struct doubly_linked_list_t* dll);
struct node_t* dll_end(struct doubly_linked_list_t* dll);

int dll_size(const struct doubly_linked_list_t* dll);
int dll_is_empty(const struct doubly_linked_list_t* dll);

int dll_at(const struct doubly_linked_list_t* dll, unsigned int index, int *err_code);

int dll_insert(struct doubly_linked_list_t* dll, unsigned int index, int value);
int dll_remove(struct doubly_linked_list_t* dll, unsigned int index, int *err_code);

void dll_clear(struct doubly_linked_list_t* dll);

void dll_display(const struct doubly_linked_list_t* dll);
void dll_display_reverse(const struct doubly_linked_list_t* dll);

#endif //CROSSWORD_DOUBLY_LINKED_LIST_H


#ifndef CROSSWORD_LINKED_LIST_H
#define CROSSWORD_LINKED_LIST_H

struct linked_list_t
{
    struct node_t *head;
    struct node_t *tail;
};

struct node_t
{
    int data;
    struct node_t *next;
};

struct linked_list_t* ll_create();

int ll_pop_front(struct linked_list_t *ll, int *err_code);
int ll_pop_back(struct linked_list_t *ll, int *err_code);
int ll_at(const struct linked_list_t *ll, unsigned int index, int *err_code);

int ll_push_back(struct linked_list_t* ll, int value);
int ll_push_front(struct linked_list_t* ll, int value);

int ll_size(const struct linked_list_t* ll);
int ll_is_empty(const struct linked_list_t* ll);

void ll_clear(struct linked_list_t* ll);

void ll_display(const struct linked_list_t* ll);

int ll_remove_sequence(struct linked_list_t* ll, const struct linked_list_t* ll_2);

#endif //CROSSWORD_LINKED_LIST_H

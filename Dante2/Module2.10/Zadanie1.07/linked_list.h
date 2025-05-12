#ifndef SOMESHIT_LINKED_LIST_H
#define SOMESHIT_LINKED_LIST_H

struct node_t
{
    int data;
    struct node_t *next;
};

struct linked_list_t
{
    struct node_t *head;
    struct node_t *tail;
};

struct linked_list_t *ll_create(void);

int ll_push_back(struct linked_list_t *ll, int value);
int ll_push_front(struct linked_list_t *ll, int value);
int ll_pop_front(struct linked_list_t *ll, int *err_code);
int ll_pop_back(struct linked_list_t *ll, int *err_code);

int ll_back(const struct linked_list_t *ll, int *err_code);
int ll_front(const struct linked_list_t *ll, int *err_code);

struct node_t *ll_begin(struct linked_list_t *ll);
struct node_t *ll_end(struct linked_list_t *ll);

int ll_size(const struct linked_list_t *ll);
int ll_is_empty(const struct linked_list_t *ll);
int ll_at(const struct linked_list_t *ll, unsigned int index, int *err_code);

int ll_insert(struct linked_list_t *ll, unsigned int index, int value);
int ll_remove(struct linked_list_t *ll, unsigned int index, int *err_code);
void ll_clear(struct linked_list_t *ll);
void ll_display(const struct linked_list_t *ll);

#endif //SOMESHIT_LINKED_LIST_H

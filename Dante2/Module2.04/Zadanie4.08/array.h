#ifndef WINAPI_ARRAY_H
#define WINAPI_ARRAY_H

struct array_t
{
    int *ptr;
    int size;
    int capacity;
};

int array_create(struct array_t *a, int N);
int array_push_back(struct array_t *a, int value);
void array_display(const struct array_t *a);
void array_destroy(struct array_t *a);

int array_create_struct(struct array_t **a, int N);
void array_destroy_struct(struct array_t **a);
int array_remove_item(struct array_t *a, int value);

#endif //WINAPI_ARRAY_H

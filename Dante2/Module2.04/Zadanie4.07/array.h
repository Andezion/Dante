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
int array_copy(const struct array_t *src, struct array_t *dest);
int array_separate(const struct array_t *a, struct array_t *odd, struct array_t *even);

#endif //WINAPI_ARRAY_H

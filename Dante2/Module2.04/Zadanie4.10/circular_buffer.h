#ifndef MATRIX_CIRCULAR_BUFFER_H
#define MATRIX_CIRCULAR_BUFFER_H

struct circular_buffer_t
{
    int *ptr;
    int begin;
    int end;
    int capacity;
    unsigned char full: 1;
};

int circular_buffer_create(struct circular_buffer_t *a, int N);
int circular_buffer_create_struct(struct circular_buffer_t **cb, int N);

void circular_buffer_destroy(struct circular_buffer_t *a);
void circular_buffer_destroy_struct(struct circular_buffer_t **a);

int circular_buffer_push_back(struct circular_buffer_t *cb, int value);
int circular_buffer_pop_front(struct circular_buffer_t *a, int *err_code);
int circular_buffer_pop_back(struct circular_buffer_t *a, int *err_code);

int circular_buffer_empty(const struct circular_buffer_t *a);
int circular_buffer_full(const struct circular_buffer_t *a);

void circular_buffer_display(const struct circular_buffer_t *a);

#endif //MATRIX_CIRCULAR_BUFFER_H

#ifndef WINAPI_MATRIX_UTILS_H
#define WINAPI_MATRIX_UTILS_H

struct matrix_t
{
    int **ptr;
    int width;
    int height;
};

int matrix_create(struct matrix_t *m, int width, int height);
int matrix_read(struct matrix_t *m);
void matrix_display(const struct matrix_t *m);
void matrix_destroy(struct matrix_t *m);

struct matrix_t* matrix_create_struct(int width, int height);

void matrix_destroy_struct(struct matrix_t **m);

struct matrix_t* matrix_transpose(const struct matrix_t *m);

int matrix_save_b(const struct matrix_t *m, const char *filename);
int matrix_save_t(const struct matrix_t *m, const char *filename);

#endif //WINAPI_MATRIX_UTILS_H

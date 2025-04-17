#ifndef SOMESHIT_MATRIX_H
#define SOMESHIT_MATRIX_H

struct matrix_t
{
    int width;
    int height;

    double **data;

    struct matrix_t* (*add)(struct matrix_t*, const struct matrix_t*);
    struct matrix_t* (*subtract)(struct matrix_t*, const struct matrix_t*);

    void (*display)(const struct matrix_t*);
};

struct matrix_t* matrix_create(int, int, int*);
void matrix_free(struct matrix_t *m);

struct matrix_t* matrix_add(struct matrix_t* m1, const struct matrix_t* m2);
struct matrix_t* matrix_subtract(struct matrix_t* m1, const struct matrix_t* m2);
void matrix_display(const struct matrix_t* m);

#endif //SOMESHIT_MATRIX_H

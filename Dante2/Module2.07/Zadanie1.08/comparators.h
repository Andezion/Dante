#ifndef CROSSWORD_COMPARATORS_H
#define CROSSWORD_COMPARATORS_H

typedef int (*func) (const void *, const void *);

struct point_t
{
    double x;
    double y;
};

int sort(void *tab, int size, int type_of_element, func helper);

int comp_int(const void *ptr1, const void *ptr2);
int comp_double(const void *ptr1, const void *ptr2);
int comp_point(const void *ptr1, const void *ptr2);

#endif //CROSSWORD_COMPARATORS_H

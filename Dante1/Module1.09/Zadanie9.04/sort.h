#ifndef INC_9_MODUL_SORT_H
#define INC_9_MODUL_SORT_H

enum direction1 {ASCENDING = 1, DESCENDING = 2};

int insertion_sort_asc(int tab[], int size);
int insertion_sort_desc(int tab[], int size);
int insertion_sort(int tab[], int size, enum direction1 dir);

#endif //INC_9_MODUL_SORT_H

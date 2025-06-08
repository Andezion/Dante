#ifndef INC_9_MODUL_SORT_H
#define INC_9_MODUL_SORT_H

enum direction1 {ASCENDING = 1, DESCENDING = 2};

int selection_sort_asc(int tab[], int size);
int selection_sort_desc(int tab[], int size);
int selection_sort(int tab[], int size, enum direction1 dir);

#endif //INC_9_MODUL_SORT_H

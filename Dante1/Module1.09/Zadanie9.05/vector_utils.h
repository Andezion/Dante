#ifndef INC_9_MODUL_TYPES_UTILS_H
#define INC_9_MODUL_TYPES_UTILS_H

enum algorithm {BUBBLE_SORT = 1, SELECTION_SORT = 2, INSERTION_SORT = 3};
enum direction {ASCENDING = 1, DESCENDING = 2};
int sort(int tab[], int size, enum direction dir, enum algorithm alg);

#endif //INC_9_MODUL_TYPES_UTILS_H

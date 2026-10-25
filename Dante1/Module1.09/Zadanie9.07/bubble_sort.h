#pragma once 

#include <stdio.h>
#include "types_utils.h"
#include "vector_utils.h"

int bubble_sort_asc_rec(int tab[], int size);
int bubble_sort_desc_rec(int tab[], int size);
int bubble_sort_rec(int tab[], int size, enum direction dir);
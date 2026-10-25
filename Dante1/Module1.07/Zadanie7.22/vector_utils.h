#pragma once

#include <stdio.h>

int read_vector(int vec[], int size, int stop_value);
void display_vector(const int vec[], int size);

int concat_begin(const int first[], int size, const int second[], int size2, int dest[], int size3);
int concat_end(const int first[], int size, const int second[], int size2, int dest[], int size3);
int concat_zip(const int first[], int size, const int second[], int size2, int dest[], int size3);


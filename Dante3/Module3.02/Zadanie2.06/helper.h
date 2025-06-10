#ifndef SO2_HELPER_H
#define SO2_HELPER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/stat.h>
#include <errno.h>

#define SERVER_SEM_NAME "/server_sem_for_one_client"
#define INTERFACE_SHM_NAME "/server_interface"

typedef struct
{
    size_t little_size;
    char request[8];
    sem_t start_of_client;
    sem_t server_finished;
    int32_t final_result;
} interface;
size_t we_take_integers_from_file(const char *filename, int32_t **array, int *err_code);
int32_t min_value(const int32_t *array, size_t size);
int32_t max_value(const int32_t *array, size_t size);

#endif //SO2_HELPER_H

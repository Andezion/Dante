#ifndef SERVER_H
#define SERVER_H

#include "big_storage.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <spawn.h>
#include <signal.h>
#include <pthread.h>
#include <sys/mman.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdatomic.h>
#include <semaphore.h>

typedef enum log_level
{
    min_log = 0,
    standart_log = 10,
    max_log = 100
}
levels;

typedef struct
{
    atomic_bool on_of_off;
    atomic_int levels;
}
log_level;

typedef struct
{
    struct
    {
        char name_of_log[512];

        char location_of_logs_tab[512];

        int sig_number[3];
    }
    meta;

    struct
    {
        pthread_mutex_t log_file;
    }
    mutex;

    struct
    {
        sem_t sem;
        pthread_t tid;
    }
    trash;

    log_level log_level;

    struct
    {
        struct sigaction handle[3];
    }
    before;

    void ( * dump_function) (FILE *);
}
log_of_signal;

void setter_of_log(const char *, const char *, int, const char *, int);

void setter_of_library(const char *, const char *, int, int, int);
void setter_of_trash_funk(void (*)(FILE *));
void destroyer_of_library();

#define log(name, value, importance) setter_of_log(name, value, importance, __FILE_NAME__, __LINE__)

#define SAVED_SIZE 256
#define LIST_MAX_SIZE 256 * (256 + 5) + 1

typedef enum
{
    none = 0,
    timer_on = 1,
    timer_on_cycle = 2,
    cancelled = 3
}
status_of_action;

typedef struct
{
    timer_t timer;
    char program[256];
    int status_of_application;
}
save_t;

void starting_server();

#endif //SERVER_H

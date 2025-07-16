#ifndef SIGNAL_LOG_H
#define SIGNAL_LOG_H

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>
#include <time.h>
#include <stdatomic.h>
#include <semaphore.h>

typedef enum
{
    MIN_LOG = 0,
    STANDARD_LOG = 10,
    MAX_LOG = 100
} log_level_t;

typedef struct
{
    atomic_bool enabled;
    atomic_int level;
} log_settings_t;

typedef struct
{
    char log_name[512];
    char log_path[512];
    int signals[3];
} log_metadata_t;

typedef struct
{
    pthread_mutex_t log_mutex;
} log_mutex_t;

typedef struct
{
    sem_t sem;
    pthread_t thread;
} dump_control_t;

typedef struct
{
    struct sigaction handlers[3];
} signal_backup_t;

typedef struct
{
    log_metadata_t metadata;
    log_settings_t settings;
    log_mutex_t mutex;
    dump_control_t dump;
    signal_backup_t prev_handlers;
    void (*dump_callback)(FILE *);
} signal_log_t;

void init_logger(const char *name, const char *path, int s1, int s2, int s3);
void shutdown_logger();
void set_dump_callback(void (*callback)(FILE *));
void log_message(const char *tag, const char *message, int level, const char *file, int line);

#define log(tag, msg, level) log_message(tag, msg, level, __FILE__, __LINE__)

#endif // SIGNAL_LOG_H

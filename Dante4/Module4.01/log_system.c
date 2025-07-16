#include "signal_log.h"

static signal_log_t *logger = NULL;

void *handle_dump_thread(void *arg)
{
    signal_log_t *log = (signal_log_t *)arg;

    while (1)
    {
        sem_wait(&log->dump.sem);

        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        if (!t)
        {
            perror("Failed to get local time");
            continue;
        }

        char filename[1024];
        snprintf(filename, sizeof(filename), "%s/dump_%04d-%02d-%02d_%02d:%02d:%02d.log",
                 log->metadata.log_path, t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
                 t->tm_hour, t->tm_min, t->tm_sec);

        FILE *file = fopen(filename, "w");
        if (!file)
        {
            perror("Failed to open dump file");
            continue;
        }

        if (log->dump_callback)
        {
            log->dump_callback(file);
        }
        else
        {
            fprintf(file, "Default dump log.\n");
        }

        fclose(file);
    }

    return NULL;
}

void log_message(const char *tag, const char *message, int level, const char *file, int line)
{
    if (!logger->settings.enabled || level < logger->settings.level)
    {
        return;
    }

    char filename[1024];
    snprintf(filename, sizeof(filename), "%s/%s", logger->metadata.log_path, logger->metadata.log_name);

    pthread_mutex_lock(&logger->mutex.log_mutex);
    FILE *logfile = fopen(filename, "a");
    if (!logfile)
    {
        perror("Failed to open log file");
        pthread_mutex_unlock(&logger->mutex.log_mutex);
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    if (t)
    {
        fprintf(logfile, "[%04d-%02d-%02d %02d:%02d:%02d] %s (%s:%d): %s\n",
                t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
                t->tm_hour, t->tm_min, t->tm_sec,
                tag, file, line, message);
    }

    fclose(logfile);
    pthread_mutex_unlock(&logger->mutex.log_mutex);
}

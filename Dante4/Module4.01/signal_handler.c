#include "signal_log.h"

static signal_log_t logger;

static void handle_log_level(int signal, siginfo_t *information, void *whats_inside)
{
    atomic_store(&logger.settings.level, information->si_value.sival_int);
}

static void handle_log_toggle(int signal, siginfo_t *information, void *whats_inside)
{
    int value = information->si_value.sival_int;
    if (value == 0 || value == 1)
    {
        atomic_store(&logger.settings.enabled, value);
    }
}

static void handle_dump(int signal, siginfo_t *information, void *whats_inside)
{
    sem_post(&logger.dump.sem);
}

static struct sigaction set_signal_handler(int signal, void (*handler)(int, siginfo_t *, void *))
{
    struct sigaction action = { 0 }, old_action;

    action.sa_sigaction = handler;
    action.sa_flags = SA_SIGINFO;

    sigemptyset(&action.sa_mask);
    sigaction(signal, &action, &old_action);

    return old_action;
}

void init_logger(const char *name, const char *path, int s1, int s2, int s3)
{
    static int initialized = 0;
    if (initialized)
    {
        return;
    }
    initialized = 1;

    strncpy(logger.metadata.log_name, name, sizeof(logger.metadata.log_name) - 1);
    strncpy(logger.metadata.log_path, path, sizeof(logger.metadata.log_path) - 1);

    logger.metadata.signals[0] = s1;
    logger.metadata.signals[1] = s2;
    logger.metadata.signals[2] = s3;

    logger.prev_handlers.handlers[0] = set_signal_handler(s1, handle_log_level);
    logger.prev_handlers.handlers[1] = set_signal_handler(s2, handle_log_toggle);
    logger.prev_handlers.handlers[2] = set_signal_handler(s3, handle_dump);

    pthread_mutex_init(&logger.mutex.log_mutex, NULL);
    sem_init(&logger.dump.sem, 0, 0);

    logger.settings.enabled = true;
    logger.settings.level = MIN_LOG;

    pthread_create(&logger.dump.thread, NULL, (void *(*)(void *))handle_dump_thread, &logger);
    pthread_detach(logger.dump.thread);
}

void shutdown_logger()
{
    static int initialized = 1;
    if (!initialized)
    {
        return;
    }
    initialized = 0;

    sigaction(logger.metadata.signals[0], &logger.prev_handlers.handlers[0], NULL);
    sigaction(logger.metadata.signals[1], &logger.prev_handlers.handlers[1], NULL);
    sigaction(logger.metadata.signals[2], &logger.prev_handlers.handlers[2], NULL);

    pthread_mutex_destroy(&logger.mutex.log_mutex);
    pthread_cancel(logger.dump.thread);
    sem_destroy(&logger.dump.sem);
}

void set_dump_callback(void (*callback)(FILE *))
{
    logger.dump_callback = callback;
}

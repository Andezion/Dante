#include "server.h"

static log_of_signal signal_log;

void handler_of_levels(int signal, siginfo_t * information, void * info_to_pass)
{
    atomic_store(&signal_log.log_level.levels, information->si_value.sival_int);
}

void on_and_off_handler(int signal, siginfo_t * information, void * info_to_pass)
{
    if (information->si_value.sival_int == true || information->si_value.sival_int == false)
    {
        atomic_store(&signal_log.log_level.on_of_off, information->si_value.sival_int);
    }
}

void trash_handler(int signal, siginfo_t * information, void * info_to_pass)
{
    sem_post(&signal_log.trash.sem);
}

struct sigaction set_up_handler(int signal, void ( * handler)(int sig, siginfo_t * information, void * info_to_pass))
{
    struct sigaction was_before;
    struct sigaction what_to_do;

    what_to_do.sa_sigaction = handler;
    sigemptyset(&what_to_do.sa_mask);

    what_to_do.sa_flags = SA_SIGINFO;
    sigaction(signal, &what_to_do, &was_before);

    return was_before;
}

void *trash(void * args)
{
    while (true)
    {
        sem_wait(&signal_log.trash.sem);

        time_t our_time = time(NULL);
        struct tm *temporary = localtime(&our_time);

        if (temporary == NULL)
        {
            perror("Failed to get time"); return NULL;
        }

        char trash_file[1024];

        sprintf(trash_file, "%s/memory_dump_%04d-%02d-%02d_%02d:%02d:%02d.dump",
            signal_log.meta.location_of_logs_tab, temporary->tm_year + 1900, temporary->tm_mon + 1,
            temporary->tm_mday, temporary->tm_hour, temporary->tm_min, temporary->tm_sec);

        FILE *file = fopen(trash_file, "w");
        if (file == NULL)
        {
            perror("Failed to open file");
            return NULL;
        }

        signal_log.dump_function(file);

        fclose(file);
    }
}

void trash_example(FILE *fp)
{
    fprintf(fp, "This is an example dump content.");
}

void setter_of_log(const char * where_to_write, const char * our_number, int level_of_log,
    const char * write_from, const int what_line)
{
    if (!signal_log.log_level.on_of_off || level_of_log < signal_log.log_level.levels)
    {
        return;
    }

    char file_logger[1024];
    sprintf(file_logger, "%s/%s", signal_log.meta.location_of_logs_tab, signal_log.meta.name_of_log);

    pthread_mutex_lock(&signal_log.mutex.log_file);

    FILE *file = fopen(file_logger, "a");
    if (file == NULL)
    {
        perror("Failed to open file");
        pthread_mutex_unlock(&signal_log.mutex.log_file); return;
    }

    time_t our_time = time(NULL);
    struct tm *temporary = localtime(&our_time);
    if (temporary == NULL)
    {
        perror("Failed to get time"); fclose(file);
        pthread_mutex_unlock(&signal_log.mutex.log_file); return;
    }

    fprintf(file, "from %s:%d at %04d-%02d-%02d %02d:%02d:%02d ",
        write_from, what_line, temporary->tm_year + 1900, temporary->tm_mon + 1,
        temporary->tm_mday, temporary->tm_hour, temporary->tm_min, temporary->tm_sec);

    fprintf(file, "%s: ", where_to_write);
    fprintf(file, "%s\n", our_number);

    fclose(file);
    pthread_mutex_unlock(&signal_log.mutex.log_file);
}

static int pointer_on_lib = 0;

void setter_of_library(const char * log_name, const char * logs_location,
    int signal_1, int signal_2, int signal_3)
{
    if (pointer_on_lib == 1)
    {
        printf("Library already initialized!");
        return;
    }
    pointer_on_lib = 1;

    strncpy(signal_log.meta.name_of_log, log_name, 512 - 1);

    strncpy(signal_log.meta.location_of_logs_tab, logs_location, 512 - 1);

    signal_log.before.handle[0] = set_up_handler(signal_1, handler_of_levels);

    signal_log.before.handle[1] = set_up_handler(signal_2, on_and_off_handler);

    signal_log.before.handle[2] = set_up_handler(signal_3, trash_handler);

    signal_log.meta.sig_number[0] = signal_1;

    signal_log.meta.sig_number[1] = signal_2;

    signal_log.meta.sig_number[2] = signal_3;

    pthread_mutex_init(&signal_log.mutex.log_file, NULL);

    sem_init(&signal_log.trash.sem, 0, 1);

    signal_log.dump_function = trash_example;

    signal_log.log_level.on_of_off = true;

    signal_log.log_level.levels = min_log;

    pthread_create(&signal_log.trash.tid, NULL, trash, NULL);

    pthread_detach(signal_log.trash.tid);
}

void setter_of_trash_funk(void (*dump_function)(FILE *))
{
    signal_log.dump_function = dump_function;
}

void destroyer_of_library()
{
    if (pointer_on_lib == 0)
    {
        printf("Library not yet initialized!");
        return;
    }
    pointer_on_lib = 0;

    sigaction(signal_log.meta.sig_number[0], &signal_log.before.handle[0], NULL);

    sigaction(signal_log.meta.sig_number[1], &signal_log.before.handle[1], NULL);

    sigaction(signal_log.meta.sig_number[2], &signal_log.before.handle[2], NULL);

    pthread_mutex_destroy(&signal_log.mutex.log_file);

    pthread_kill(signal_log.trash.tid, 0);

    sem_destroy(&signal_log.trash.sem);
}

static save_t saved_timers[SAVED_SIZE] = { 0 };

static pthread_mutex_t mutex_saved = PTHREAD_MUTEX_INITIALIZER;

void date_handler(const client_datetime_t * datetime, struct tm * time)
{
    time->tm_year = datetime->date.our_year - 1900;

    time->tm_mon = datetime->date.our_month - 1;

    time->tm_mday = datetime->date.our_day;

    time->tm_hour = datetime->time.our_hour;

    time->tm_min = datetime->time.our_min;

    time->tm_sec = datetime->time.our_sec;
}

timer_t our_timer(const when_action_t when)
{
    timer_t timer_id;

    int tv_sec;

    if (when.first.datetime.date.our_year || when.first.datetime.date.our_month  || when.first.datetime.date.our_day)
    {
        struct tm timev = { 0 };

        date_handler(&when.first.datetime, &timev);

        time_t future_time = mktime(&timev);

        time_t current_time = time(NULL);

        tv_sec = (int) difftime(future_time, current_time);

        if (tv_sec < 0)
        {
            printf("Error: Specified time is in the past!\n");
        }
    }
    else
    {
        tv_sec = when.first.datetime.time.our_hour * 3600 + when.first.datetime.time.our_min * 60 + when.first.datetime.time.our_sec;
    }

    struct itimerspec value;

    value.it_value.tv_sec = tv_sec;

    value.it_value.tv_nsec = 0;

    if (when.repeat.time.our_hour || when.repeat.time.our_min || when.repeat.time.our_sec)
    {
        value.it_interval.tv_sec = when.repeat.time.our_hour * 3600 + when.repeat.time.our_min * 60 + when.repeat.time.our_sec;
    }
    else
    {
        value.it_interval.tv_sec = 0;
    }
    value.it_interval.tv_nsec = 0;

    timer_settime(timer_id, 0, &value, NULL);

    return timer_id;
}

void thread_and_timer(union sigval argument)
{
    pthread_mutex_lock(&mutex_saved);

    int some_value = argument.sival_int;

    if (saved_timers->status_of_application == cancelled)
    {
        pthread_mutex_unlock(&mutex_saved); return;
    }

    pid_t child_index;

    posix_spawn(&child_index, saved_timers[some_value].program, NULL, NULL, NULL, NULL);

    log("Start", "Lets go", max_log);

    if (saved_timers[some_value].status_of_application == timer_on)
    {
        timer_delete(saved_timers[some_value].timer);
        saved_timers->status_of_application = none;
    }

    pthread_mutex_unlock(&mutex_saved);
}

void send_response(query query, const char * response_message)
{
    server_response_t response;

    sprintf(response.name_of_shm, "%s_shm", query.reply_from);

    response.size_of_shm = strlen(response_message) + 1;

    int our_id = shm_open(response.name_of_shm, O_RDWR | O_CREAT, 0777);
    if (our_id == -1)
    {
        perror("Shared memory error: "); response.response_status = -1;
    }
    else
    {
        ftruncate(our_id, response.size_of_shm * sizeof(char));
        char * some_message = (char *) mmap(0, response.size_of_shm * sizeof(char),
            PROT_READ | PROT_WRITE, MAP_SHARED, our_id, 0);

        strcpy(some_message, response_message);

        munmap(some_message, response.size_of_shm * sizeof(char));
        close(our_id);

        response.response_status = 0;
    }

    mqd_t what_client_see = mq_open(query.reply_from, O_WRONLY);
    if (what_client_see == -1)
    {
        perror("Save me please");
        return;
    }

    mq_send(what_client_see, (const char * ) &response, sizeof(server_response_t), 0);
    mq_close(what_client_see);
}

void handle_what_client_want(query query)
{
    if(query.command == ADDING)
    {
        pthread_mutex_lock(&mutex_saved);

        int some_value = 0;

        while (some_value < SAVED_SIZE)
        {
            if (saved_timers[some_value].status_of_application == none)
            {
                break;
            }
        }

        pthread_mutex_unlock(&mutex_saved);

        if (some_value == SAVED_SIZE)
        {
            send_response(query, "That's all");
        }

        struct sigevent timer_event;

        timer_event.sigev_notify = SIGEV_THREAD;

        timer_event.sigev_notify_function = thread_and_timer;

        timer_event.sigev_value.sival_int = some_value;

        timer_event.sigev_notify_attributes = NULL;

        timer_t timer_id = our_timer(query.adding.when);

        timer_create(CLOCK_REALTIME, &timer_event, &timer_id);

        pthread_mutex_lock(&mutex_saved);

        saved_timers[some_value].timer = timer_id;

        if (!query.adding.when.repeat.time.our_hour && !query.adding.when.repeat.time.our_min && !query.adding.when.repeat.time.our_sec)
        {
            saved_timers[some_value].status_of_application = timer_on;
        }
        else
        {
            saved_timers[some_value].status_of_application = timer_on_cycle;
        }

        log("Start", "Lets go", max_log);

        strcpy(saved_timers[some_value].program, query.adding.program);

        pthread_mutex_unlock(&mutex_saved);

        send_response(query, "Task added.");
    }
    else if(query.command == REMOVING)
    {
        char * response = NULL;

        pthread_mutex_lock(&mutex_saved);

        if (saved_timers[query.removing.what].status_of_application == timer_on ||
            saved_timers[query.removing.what].status_of_application == timer_on_cycle)
        {
            timer_delete(saved_timers[query.removing.what].timer);
            saved_timers[query.removing.what].status_of_application = cancelled;

            log("Start", "Deleted process", max_log);

            response = "Task removed.";
        }
        else
        {
            response = "No such task.";
        }
        pthread_mutex_unlock(&mutex_saved);

        send_response(query, response);
    }
    else if(query.command == INFO)
    {
        char storage[LIST_MAX_SIZE] = {0};
        char * looking_forward = storage;

        pthread_mutex_lock(&mutex_saved);

        for (int i = 0; i < SAVED_SIZE; ++i)
        {
            if (saved_timers[i].status_of_application == timer_on ||
                saved_timers[i].status_of_application == timer_on_cycle)
            {
                looking_forward = looking_forward + sprintf(looking_forward, "%d.%s\n", i, saved_timers[i].program);
            }
        }
        pthread_mutex_unlock(&mutex_saved);

        send_response(query, looking_forward);
    }
    else if(query.command == CLOSING)
    {
        pthread_mutex_lock(&mutex_saved);
        for (int i = 0; i < SAVED_SIZE; ++i)
        {
            if (saved_timers[i].status_of_application == timer_on || saved_timers[i].status_of_application == timer_on_cycle)
            {
                timer_delete(saved_timers[query.removing.what].timer);
            }
        }
        pthread_mutex_unlock(&mutex_saved);
    }
}

void starting_server()
{
    struct mq_attr attribute;

    attribute.mq_maxmsg = 10;
    attribute.mq_msgsize = sizeof(query);

    mqd_t mq_queries_from_clients = mq_open(QUERY_TO_SERVER, O_CREAT | O_EXCL | O_RDONLY, 0444, &attribute);

    if (mq_queries_from_clients == -1)
    {
        return;
    }

    setter_of_library("logs", "logs", SIGUSR1, SIGUSR2, SIGINT);

    for (;;)
    {
        query query;

        int number_to_check = mq_receive(mq_queries_from_clients, (char *) &query, sizeof(query), NULL);
        if (number_to_check == -1)
        {
            perror("Error query");
            continue;
        }

        handle_what_client_want(query);

        if (query.command == CLOSING)
        {
            mq_unlink(QUERY_TO_SERVER);

            destroyer_of_library();

            break;
        }
    }
}

#ifndef BIG_STORAGE_H
#define BIG_STORAGE_H

#define QUERY_TO_SERVER "/mq_queries_queue"
#include <stdlib.h>

struct our_date_t
{
    int our_year;
    int our_month;
    int our_day;
};

struct our_time_t
{
    int our_hour;
    int our_min;
    int our_sec;
};

typedef struct
{
    struct our_date_t date;
    struct our_time_t time;
}
client_datetime_t;

typedef struct
{
    struct
    {
        client_datetime_t datetime;
    }
    first;
    struct
    {
        struct our_time_t time;
    }
    repeat;
}
when_action_t;

typedef struct
{
    char name_of_shm[260];
    unsigned long long size_of_shm;

    int response_status;
}
server_response_t;

typedef enum
{
    ADDING,
    REMOVING,
    INFO,
    CLOSING
}
commands;

typedef struct
{
    char reply_from[256];

    commands command;
    union
    {
        struct
        {
            char program[256];

            when_action_t when;
        }
        adding;
        struct
        {
            int what;
        }
        removing;
    };
}
query;

#endif //BIG_STORAGE_H

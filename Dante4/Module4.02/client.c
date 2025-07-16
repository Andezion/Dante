#include "client.h"

void handle_date(query *query, int *i, char **argv)
{
    (*i)++;

    query->adding.when.first.datetime.date.our_year = atoi(argv[*i]);

    (*i)++;

    query->adding.when.first.datetime.date.our_month = atoi(argv[*i]);

    (*i)++;

    query->adding.when.first.datetime.date.our_day = atoi(argv[*i]);
}

void handle_time(query *query, int *i, char **argv)
{
    (*i)++;

    query->adding.when.first.datetime.time.our_hour = atoi(argv[*i]);

    (*i)++;

    query->adding.when.first.datetime.time.our_min = atoi(argv[*i]);

    (*i)++;

    query->adding.when.first.datetime.time.our_sec = atoi(argv[*i]);
}

void handle_cycle(query *query, int *i, char **argv)
{
    (*i)++;

    query->adding.when.repeat.time.our_hour = atoi(argv[*i]);

    (*i)++;

    query->adding.when.repeat.time.our_min = atoi(argv[*i]);

    (*i)++;
    
    query->adding.when.repeat.time.our_sec = atoi(argv[*i]);
}

void what_client_want(int argc, char** argv)
{
    query query;

    for (int i = 1 ; i < argc; i++)
    {
        if (strcmp(argv[i],"-d") != 0)
        {
            if (strcmp(argv[i], "-t") != 0)
            {
                if (strcmp(argv[i], "-c") != 0)
                {
                    if (strcmp(argv[i], "-a") != 0)
                    {
                        if (strcmp(argv[i], "-r") != 0)
                        {
                            if (strcmp(argv[i], "-l") != 0)
                            {
                                if (strcmp(argv[i], "--close") == 0)
                                {
                                    query.command = CLOSING;
                                }
                            }
                            else
                            {
                                query.command = INFO;
                            }
                        }
                        else
                        {
                            query.command = REMOVING;
                            i++;
                            query.removing.what = atoi(argv[i]);
                        }
                    }
                    else
                    {
                        i++;
                        query.command = ADDING;
                        strncpy(query.adding.program, argv[i], 255);
                    }
                }
                else
                {
                    handle_cycle(&query, &i, argv);
                }
            }
            else
            {
                handle_time(&query, &i, argv);
            }
        }
        else
        {
            handle_date(&query, &i, argv);
        }
    }
    sprintf(query.reply_from, "/mq_reply_queue_%d", getpid());

    mqd_t mq_queries_to_server;
    do
    {
        mq_queries_to_server = mq_open(QUERY_TO_SERVER, O_WRONLY);
        sleep(1);
    }
    while (mq_queries_to_server == -1);

    if (mq_send(mq_queries_to_server, (const char*)&query, sizeof(query), 0) == -1)
    {
        perror("Could not send query");
        mq_close(mq_queries_to_server); return;
    }

    mq_close(mq_queries_to_server);

    if (query.command == CLOSING)
    {
        return;
    }

    struct mq_attr attribute;

    attribute.mq_maxmsg = 10;
    attribute.mq_msgsize = sizeof(server_response_t);

    mqd_t our_reply_from_server = mq_open(query.reply_from, O_CREAT | O_RDONLY, 0644, &attribute);
    if (our_reply_from_server == -1)
    {
        perror("Client query could not be opened"); return;
    }

    server_response_t our_response;

    if (mq_receive(our_reply_from_server, (char * ) &our_response, sizeof(server_response_t), NULL) == -1)
    {
        perror("Server error");

        mq_close(our_reply_from_server);
        mq_unlink(query.reply_from);

        return;
    }

    mq_close(our_reply_from_server);
    mq_unlink(query.reply_from);

    if (our_response.response_status != 0)
    {
        printf("Server error");
    }
    else
    {
        int our_id_to_handle = shm_open(our_response.name_of_shm, O_RDONLY, 0777);

        char * response_message = (char *) mmap(0, our_response.size_of_shm * sizeof(char), PROT_READ, MAP_SHARED,our_id_to_handle, 0);

        printf("%s", response_message);

        munmap(response_message, our_response.size_of_shm * sizeof(char));

        close(our_id_to_handle);

        shm_unlink(our_response.name_of_shm);
    }
}

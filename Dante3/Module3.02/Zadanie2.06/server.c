#include "helper.h"

static pthread_mutex_t terminator_mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t i_love_mutex = PTHREAD_MUTEX_INITIALIZER;

static size_t minimal = 0;
static size_t maximal = 0;

static int terminate = 0;

int32_t min_value(const int32_t *array, size_t size)
{
    if (size == 0)
    {
        return 0;
    }

    int32_t min_value = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] < min_value)
        {
            min_value = array[i];
        }
    }

    return min_value;
}
int32_t max_value(const int32_t *array, size_t size)
{
    if (size == 0)
    {
        return 0;
    }

    int32_t max_value = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max_value)
        {
            max_value = array[i];
        }
    }

    return max_value;
}

void *handle_client(void *argument)
{
    interface *to_client = (interface *) argument;
    while (1)
    {
        sem_wait(&to_client->start_of_client);
        pthread_mutex_lock(&terminator_mutex);
        int can_i_terminate = terminate;
        pthread_mutex_unlock(&terminator_mutex);
        if (can_i_terminate)
        {
            sem_post(&to_client->server_finished);
            break;
        }
        size_t length = to_client->little_size;
        int data_fd = shm_open("/cl_data", O_RDWR, 0666);
        if (-1 == data_fd)
        {
            perror("server error");
            to_client->final_result = 0;
            sem_post(&to_client->server_finished);
            continue;
        }
        size_t array_size = length * sizeof(int32_t);
        int32_t *array_ptr = mmap(NULL, array_size, PROT_READ, MAP_SHARED, data_fd, 0);
        if (MAP_FAILED == array_ptr)
        {
            perror("mmap array error");
            close(data_fd);
            sem_post(&to_client->server_finished);
            continue;
        }
        int32_t result_val = 0;
        if (0 == strcmp(to_client->request, "min"))
        {
            result_val = min_value(array_ptr, length);
            pthread_mutex_lock(&i_love_mutex);
            minimal++;
            pthread_mutex_unlock(&i_love_mutex);
        }
        else if (0 == strcmp(to_client->request, "max"))
        {
            result_val = max_value(array_ptr, length);
            pthread_mutex_lock(&i_love_mutex);
            maximal++;
            pthread_mutex_unlock(&i_love_mutex);
        }
        else { fprintf(stderr, "unknown request type '%s'\n", to_client->request); }
        to_client->final_result = result_val;
        munmap(array_ptr, array_size);
        close(data_fd);
        sem_post(&to_client->server_finished);
    }
    return NULL;
}


void *handle_what_client_write(void *arg)
{
    interface *our_interface_of_client;
    our_interface_of_client = (interface *) arg;
    for (;;)
    {
        char storage[32];
        if (EOF == scanf("%31s", storage))
        {
            pthread_mutex_lock(&terminator_mutex); terminate = 1;
            pthread_mutex_unlock(&terminator_mutex); sem_post(&our_interface_of_client->start_of_client);
            break;
        }
        if (0 == strcmp(storage, "q")) // quit
        {
            pthread_mutex_lock(&terminator_mutex); terminate = 1;
            pthread_mutex_unlock(&terminator_mutex); sem_post(&our_interface_of_client->start_of_client);
            break;
        }
        if (0 == strcmp(storage, "s")) // statistic
        {
            pthread_mutex_lock(&i_love_mutex);
            printf("Number: %zu, max: %zu\n", minimal, maximal);
            pthread_mutex_unlock(&i_love_mutex);
        }
        if (0 == strcmp(storage, "r")) // reset
        {
            pthread_mutex_lock(&i_love_mutex);
            minimal = 0;
            maximal = 0;
            pthread_mutex_unlock(&i_love_mutex);
            printf("statistic is zero.\n");
        }
        else { printf("new command: %s\n", storage); }
    }
    return NULL;
}

int main(void)
{
    printf("Vladislav Doronchenkov\n");
    printf("Zadanie na ocene 3\n");
    shm_unlink(INTERFACE_SHM_NAME);
    sem_unlink(SERVER_SEM_NAME);
    int our_feed = shm_open(INTERFACE_SHM_NAME, O_CREAT | O_EXCL | O_RDWR, 0666);
    if (our_feed < 0) { perror("server shm_open error"); return 1; }
    ftruncate(our_feed, sizeof(interface));
    interface *our_interface = mmap(NULL, sizeof(interface), PROT_READ | PROT_WRITE, MAP_SHARED, our_feed, 0);
    if (our_interface == MAP_FAILED)
    {
        perror("server mmap error"); close(our_feed);
        shm_unlink(INTERFACE_SHM_NAME); return 1;
    }
    sem_init(&our_interface->start_of_client, 1, 0);
    sem_init(&our_interface->server_finished, 1, 0);
    sem_t *server_opening = sem_open(SERVER_SEM_NAME, O_CREAT | O_EXCL, 0666, 1);
    if (server_opening == SEM_FAILED)
    {
        perror("server sem_open error"); munmap(our_interface, sizeof(interface));
        close(our_feed); shm_unlink(INTERFACE_SHM_NAME);
        return 1;
    }
    pthread_t thread_one;
    pthread_t thread_two;
    pthread_create(&thread_one, NULL, handle_client, our_interface);
    pthread_create(&thread_two, NULL, handle_what_client_write, our_interface);
    pthread_join(thread_two, NULL); pthread_join(thread_one, NULL);
    sem_destroy(&our_interface->start_of_client); sem_destroy(&our_interface->server_finished);
    munmap(our_interface, sizeof(interface)); close(our_feed);
    shm_unlink(INTERFACE_SHM_NAME); sem_close(server_opening); sem_unlink(SERVER_SEM_NAME);
    return 0;
}

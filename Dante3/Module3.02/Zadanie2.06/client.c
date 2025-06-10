#include "helper.h"

size_t we_take_integers_from_file(const char *filename, int32_t **array, int *err_code)
{
    *err_code = 0;

    FILE *f;
    f = fopen(filename, "r");

    if (!f)
    {
        *err_code = 1; return 0;
    }

    size_t counter = 0;
    int32_t temporary;
    for (; fscanf(f, "%i", &temporary) == 1;)
    {
        counter++;
    }
    if (counter == 0)
    {
        fclose(f); return 0;
    }
    rewind(f);

    *array = (int32_t *) malloc(counter * sizeof(int32_t));
    if (*array == NULL)
    {
        fclose(f); *err_code = 2;
        return 0;
    }

    size_t iterator = 0;
    for (; iterator < counter && fscanf(f, "%i", &(*array)[iterator]) == 1; ) { iterator++; }
    fclose(f);

    return counter;
}
int main(int argc, char* argv[])
{
    if (argc < 3){ fprintf(stderr, "min or max\n"); return 1; }
    const char *name_of_file = argv[1];
    const char *our_request = argv[2];
    if (strcmp(our_request, "min") != 0 && strcmp(our_request, "max") != 0)
    {
        fprintf(stderr, "This is not min or max"); return 1;
    }
    sem_t *name_of_our_server = sem_open(SERVER_SEM_NAME, 0);
    if (name_of_our_server == SEM_FAILED)
    {
        fprintf(stderr, "Server does NOT work"); return 2;
    }
    if (sem_trywait(name_of_our_server) == -1)
    {
        fprintf(stderr, "Server is currently used");
        sem_close(name_of_our_server); return 3;
    }
    int our_error = 0;
    int32_t *storage = NULL;
    size_t our_size_of_file = we_take_integers_from_file(name_of_file, &storage, &our_error);
    if (our_error != 0 || our_size_of_file == 0)
    {
        fprintf(stderr, "Hehehe, your file is broken!"); free(storage);
        sem_post(name_of_our_server); sem_close(name_of_our_server);
        return 4;
    }
    int feed = shm_open(INTERFACE_SHM_NAME, O_RDWR, 0666);
    if (feed < 0)
    {
        fprintf(stderr, "no server"); free(storage);
        sem_post(name_of_our_server); sem_close(name_of_our_server);
        return 5;
    }
    interface *instruction = mmap(NULL, sizeof(interface), PROT_READ | PROT_WRITE, MAP_SHARED, feed, 0);
    if (instruction == MAP_FAILED)
    {
        perror("client mmap error"); close(feed); free(storage);
        sem_post(name_of_our_server); sem_close(name_of_our_server);
        return 6;
    }
    shm_unlink("/cl_data");
    int var_for_data_feed = shm_open("/cl_data", O_CREAT | O_EXCL | O_RDWR, 0666);
    if (var_for_data_feed < 0)
    {
        perror("client shm_open /cl_data error"); munmap(instruction, sizeof(interface));
        close(feed); free(storage);
        sem_post(name_of_our_server); sem_close(name_of_our_server);
        return 7;
    }
    size_t size_of_array = our_size_of_file * sizeof(int32_t);
    ftruncate(var_for_data_feed, (off_t)size_of_array);
    int32_t *pointer_on_our_data = mmap(NULL, size_of_array, PROT_READ | PROT_WRITE, MAP_SHARED, var_for_data_feed, 0);
    if (pointer_on_our_data == MAP_FAILED)
    {
        perror("client mmap data_ptr error"); close(var_for_data_feed);
        shm_unlink("/cl_data"); munmap(instruction, sizeof(interface));
        close(feed); free(storage);
        sem_post(name_of_our_server); sem_close(name_of_our_server);
        return 8;
    }
    memcpy(pointer_on_our_data, storage, size_of_array);
    instruction->little_size = our_size_of_file;
    strncpy(instruction->request, our_request, sizeof(instruction->request) - 1);
    instruction->request[sizeof(instruction->request) - 1] = '\0';
    sem_post(&instruction->start_of_client);
    sem_wait(&instruction->server_finished);
    int32_t what_number_to_show = instruction->final_result;
    printf("server output on %s = %i\n", our_request, what_number_to_show);
    munmap(pointer_on_our_data, size_of_array); close(var_for_data_feed);
    shm_unlink("/cl_data"); munmap(instruction, sizeof(interface));
    close(feed); sem_post(name_of_our_server); sem_close(name_of_our_server);
    free(storage); return 0;
}

#include "server.h"
#include "client.h"

int main(int argc, char **argv)
{
    if (fork() != 0)
    {
        starting_server();
    }
    else
    {
        what_client_want(argc, argv);
    }
    return 0;
}

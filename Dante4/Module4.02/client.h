#ifndef CLIENT_H
#define CLIENT_H

#include "big_storage.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <mqueue.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <time.h>
#include <stdlib.h>

void what_client_want(int, char**);

#endif //CLIENT_H

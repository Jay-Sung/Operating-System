#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>

int main()
{
const int SIZE = 4096; // the size of shared memory
const char *name = "OS"; // the name of shared memory
const char *message_0 = "Hello, ";
const char *message_1 = "Shared Memory!\n";

int shm_fd; // the file descriptor of shared memory
char *ptr; // pointer to shared memory

/* create the shared memory object */
shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

/* configure the size of the shared memory */
ftruncate(shm_fd, SIZE);

/* map the shared memory object */
ptr = (char *)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

/* write to the shared memory */
sprintf(ptr, "%s", message_0);
ptr += strlen(message_0);
sprintf(ptr, "%s", message_1);
ptr += strlen(message_1);
return 0;
}

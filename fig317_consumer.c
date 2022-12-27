#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>
# ifndef STRLEN
#  define STRLEN	__strlen_avx2
# endif


int main()
{
const int SIZE = 4096; // the size of shared memory
const char *name = "OS"; // the name of shared memory
int shm_fd; // the file descriptor of shared memory
char *ptr; // pointer to shared memory

/* create the shared memory object */
shm_fd = shm_open(name, O_RDONLY, 0666);

/* map the shared memory object */
//ptr = (char *)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
ptr = (char *)mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
/* read from the shared memory object */
printf("%s\n", (char *) ptr);

/* remove the shared memory */
shm_unlink(name);

return 0;

}

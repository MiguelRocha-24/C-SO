#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <utime.h>
#include <sys/stat.h>


int main(int argc, char* argv[]) {
    if (access(argv[1], F_OK) == 0) {
        /* file exists - insert code to change last access date */
        int a = utime(argv[1], NULL);
        struct stat o;
        stat(argv[1], &o);
        if (a == -1) {
            printf("Error opening file");
        }
        struct timespec d = o.st_mtim;
        char* data =  ctime(&d.tv_sec);
        printf("Date: %s", data);

    } else {
        /* file does not exist - create it with given access permissions */
        mode_t perms = S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH;
        int fd = open(argv[1], O_CREAT|O_WRONLY, perms);
        close(fd);
    }
    exit(EXIT_SUCCESS);
}
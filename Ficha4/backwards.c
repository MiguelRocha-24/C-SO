#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 1024
int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("usage: cat filename\n");
        exit(EXIT_FAILURE);
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        printf("error: cannot open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }



    off_t pos = lseek(fd, 0, SEEK_END);  // get file size
    char c;

    while (pos > 0) {
        pos--;                                    // move back one byte
        lseek(fd, pos, SEEK_SET);                 // set file offset
        read(fd, &c, 1);                          // read 1 byte
        write(STDOUT_FILENO, &c, 1);              // print it
    }

    close(fd);
    return 0;
}
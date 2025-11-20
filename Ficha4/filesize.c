#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
    struct stat info;
    if (argc < 2) {
        fprintf(stderr, "usage: %s files\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int total_bytes = 0, total_disks = 0;
    for (int i = 1; i < argc; i++){
        int retv = stat(argv[i], &info);
        if (retv == -1) {
            fprintf(stderr, "%s: Can’t stat %s\n", argv[0], argv[1]);
            exit(EXIT_FAILURE);
        }
        total_bytes+= (int)info.st_size;
        total_disks+= (int)info.st_blocks;
        struct timespec o = info.st_mtim;
        char * data = ctime(&o.tv_sec);
        int user = info.st_uid;
        printf("User_id: %i made the last change on: %s", user,data);
    }
    printf("Total Bytes = %i; Total Blocks = %i\n", total_bytes, total_disks);

    exit(EXIT_SUCCESS);
}

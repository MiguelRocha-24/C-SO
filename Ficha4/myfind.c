#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

void myfind(char* dir, char* tar) {
    DIR *q = opendir(dir);
    if (q == NULL) {
        fprintf (stderr, "cannot open directory: %s\n", dir);
        exit(EXIT_FAILURE);
    }


    struct dirent *p;
    while ((p = readdir(q)) != NULL) {
        if (strcmp(p->d_name, ".") == 0 || strcmp(p->d_name, "..") == 0)
            continue;
        char path[1024];
        strcpy(path, dir);
        strcat(path, "/");
        strcat(path, p->d_name);
        struct stat sb;
        stat(path, &sb);
        if ((sb.st_mode & S_IFMT) == S_IFDIR) {
            myfind(path, tar);
        }
        else {
            if (strcmp(p->d_name, tar) == 0) {
                printf("%s\n", path);
            }
        }
    }
    closedir(q);


}


int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s root file_to_search", argv[0]);
        exit(EXIT_FAILURE);
    }
    myfind(argv[1], argv[2]);




}

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>


void format_permissions(mode_t mode, char *out) {
    out[0] = S_ISDIR(mode) ? 'd' :
             S_ISLNK(mode) ? 'l' :
             S_ISCHR(mode) ? 'c' :
             S_ISBLK(mode) ? 'b' :
             S_ISFIFO(mode)? 'p' :
             S_ISSOCK(mode)? 's' : '-';

    out[1] = (mode & S_IRUSR) ? 'r' : '-';
    out[2] = (mode & S_IWUSR) ? 'w' : '-';
    out[3] = (mode & S_IXUSR) ? 'x' : '-';

    out[4] = (mode & S_IRGRP) ? 'r' : '-';
    out[5] = (mode & S_IWGRP) ? 'w' : '-';
    out[6] = (mode & S_IXGRP) ? 'x' : '-';

    out[7] = (mode & S_IROTH) ? 'r' : '-';
    out[8] = (mode & S_IWOTH) ? 'w' : '-';
    out[9] = (mode & S_IXOTH) ? 'x' : '-';

    out[10] = '\0';
}



int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf (stderr, "usage: %s dirname\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    struct stat sb;
    stat(argv[1], &sb);
    if ((sb.st_mode & S_IFMT) == S_IFDIR) {
        DIR *q = opendir(argv[1]);
        if (q == NULL) {
            fprintf (stderr, "cannot open directory: %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        printf ("%s/\n", argv[1]);
        struct dirent *p = readdir(q);
        // permissoes, typo, user id, grp id, bytes, modifies date, name
        while (p != NULL) {
            struct timespec a = sb.st_mtim;
            char* date = ctime(&a.tv_sec);
            size_t len = strlen(date);
            date[len-1] = '\0';
            char perms[11];
            format_permissions(sb.st_mode, perms);
            printf ("\t%s %u %u %ld %s %s\n", perms, sb.st_uid, sb.st_gid, sb.st_blocks, date, p->d_name);
            p = readdir(q);
        }
        closedir(q);
    }
    else {
        printf("%s/\n", argv[1]);
    }

    exit(EXIT_SUCCESS);
}
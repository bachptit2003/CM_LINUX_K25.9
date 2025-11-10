#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

void print_usage(const char *prog_name) {
    printf("Usage: %s <file_path>\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return 1;
    }

    const char *path = argv[1];
    struct stat file_stat;

    if (lstat(path, &file_stat) == -1) {
        perror("Error getting file info");
        return 1;
    }

    printf("File Path: %s\n", path);

    printf("File Type: ");
    if (S_ISREG(file_stat.st_mode))
        printf("Regular File\n");
    else if (S_ISDIR(file_stat.st_mode))
        printf("Directory\n");
    else if (S_ISLNK(file_stat.st_mode))
        printf("Symbolic Link\n");
    else
        printf("Other\n");

    printf("Size: %lld bytes\n", (long long)file_stat.st_size);

    char time_buf[100];
    struct tm *timeinfo = localtime(&file_stat.st_mtime);
    strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S", timeinfo);
    printf("Last Modified: %s\n", time_buf);

    return 0;
}

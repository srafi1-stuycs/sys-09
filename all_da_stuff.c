#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    DIR* here = opendir(".");
    int size = 0;

    struct dirent* current;
    printf("Directories: \n");
    while (current = readdir(here)) {
        if (current->d_type != DT_REG) {
            printf("%s/\n", current->d_name);
        }
    }
    closedir(here);
    here = opendir(".");
    printf("\nRegular files: \n");
    struct stat* info = malloc(sizeof(struct stat));
    while (current = readdir(here)) {
        if (current->d_type == DT_REG) {
            stat(current->d_name, info);
            printf("%s : %d bytes\n", current->d_name, info->st_size);
            size += info->st_size;
        }
    }
    free(info);
    printf("\nTotal directory size: %d Bytes\n", size);

    return 0;
}

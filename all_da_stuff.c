#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    DIR* here = opendir(".");
    struct dirent* current;
    printf("Directories: \n");
    while (current = readdir(here)) {
        if (current->d_type != DT_REG) {
            printf("%s\n", current->d_name);
        }
    }
    closedir(here);
    here = opendir(".");
    printf("Regular files: \n");
    while (current = readdir(here)) {
        if (current->d_type == DT_REG) {
            printf("%s\n", current->d_name);
        }
    }

    return 0;
}

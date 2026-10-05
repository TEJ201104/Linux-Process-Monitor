#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

int main() {
    DIR *dir;
    struct dirent *entry;
    FILE *file;
    char path[100];
    char name[100];
    char state;
    int pid, ppid;

    dir = opendir("/proc");

    if (dir == NULL) {
        printf("Unable to open /proc\n");
        return 1;
    }

    printf("%-8s %-25s %-8s %-8s\n", "PID", "Process Name", "State", "PPID");
    printf("----------------------------------------------------------\n");

    while ((entry = readdir(dir)) != NULL) {

        if (!isdigit(entry->d_name[0]))
            continue;

        pid = atoi(entry->d_name);

        sprintf(path, "/proc/%d/stat", pid);

        file = fopen(path, "r");

        if (file == NULL)
            continue;

        fscanf(file, "%d %99s %c %d", &pid, name, &state, &ppid);

        printf("%-8d %-25s %-8c %-8d\n",pid, name, state, ppid);

        fclose(file);
    }

    closedir(dir);

    return 0;
}

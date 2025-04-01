#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

#define TRASH_DIR "~/utrash/"

void create_trash_dir() {
    char command[256];
    snprintf(command, sizeof(command), "mkdir -p %s", TRASH_DIR);
    system(command);
}

void move_to_trash(const char *path) {
    char command[512];
    snprintf(command, sizeof(command), "mv '%s' %s", path, TRASH_DIR);
    system(command);
}

void list_trash() {
    char command[256];
    snprintf(command, sizeof(command), "ls -l %s", TRASH_DIR);
    system(command);
}

void recover_from_trash(const char *filename) {
    char command[512];
    snprintf(command, sizeof(command), "mv %s%s ./", TRASH_DIR, filename);
    system(command);
}

void secure_delete(const char *path) {
    char command[512];
    snprintf(command, sizeof(command), "shred -uz '%s'", path);
    system(command);
}

void empty_trash() {
    char command[512];
    printf("Are you sure you want to permanently delete all files in trash? [y/n]: ");
    char confirm;
    scanf(" %c", &confirm);
    if (confirm == 'y' || confirm == 'Y') {
        snprintf(command, sizeof(command), "rm -rf %s*", TRASH_DIR);
        system(command);
    } else {
        printf("Operation canceled.\n");
    }
}

int main(int argc, char *argv[]) {
    create_trash_dir();
    
    if (argc < 2) {
        printf("Usage: urm [option] [file/directory]\n");
        return 1;
    }
    
    if (strcmp(argv[1], "-trash") == 0) {
        list_trash();
    } else if (strcmp(argv[1], "-recover") == 0 && argc == 3) {
        recover_from_trash(argv[2]);
    } else if (strcmp(argv[1], "-etr") == 0) {
        empty_trash();
    } else if (strcmp(argv[1], "-d") == 0 && argc == 3) {
        move_to_trash(argv[2]);
    } else {
        move_to_trash(argv[1]);
    }
    
    return 0;
}

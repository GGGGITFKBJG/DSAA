//linux ls命令简单实现
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>

#define PATHLEN 1024

void list_dir(const char* pathname) {
    struct stat statbuf;
    struct dirent *dirp;
    DIR *dp;
    
    if(lstat(pathname, &statbuf) < 0) {
        perror("lstat");
        exit(0);
    }
    if(S_ISDIR(statbuf.st_mode) == 0) {
        printf("input a legal pathname\n");
        exit(0);
    }
    if( (dp = opendir(pathname)) == NULL) {
        perror("opendir");
        exit(0);
    }

    while( (dirp = readdir(dp)) != NULL) {
        if(strcmp(dirp->d_name, ".") == 0 ||
           strcmp(dirp->d_name, "..") == 0) continue;
        printf("%s  ", dirp->d_name);
    }

    printf("\n");
}

int main(int argc, char* argv[]) {
    char path[PATHLEN];
    if(argc == 1) {
      list_dir(".");
      exit(0);
    }
    
    if(strlen(argv[1]) > PATHLEN)
        perror("pathlen");

    strcpy(path, argv[1]);

    list_dir(path);
    
    return 0;
}

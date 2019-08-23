//linux pwd命令简单实现
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

int getino(char* pathname) {
    struct stat statbuf;
    
    if( (lstat(pathname, &statbuf)) < 0) {
        perror("lstat");
        exit(0);
    }
    return statbuf.st_ino;
}

void ino2str(int ino) {
    struct dirent *dirp;
    DIR *dp;

    if( (dp = opendir(".")) == NULL) {
        perror("opendir");
        exit(0);
    }

    while( (dirp = readdir(dp)) != NULL) {
        if(dirp->d_ino == ino) {
            printf("/%s", dirp->d_name);//打印完毕
            chdir(dirp->d_name);//重要！将工作目录改回子目录
            break;
        }
    }
}

void printcwd(int ino) {
    if(ino == getino("..")) return;
    chdir("..");//进入父目录
    printcwd(getino("."));//这里的.已经是父目录了，每执行一次，目录向上（根目录方向）移动一层
    ino2str(ino);//每执行一次，工作目录向下一层
}

int main() {
    
    printcwd(getino("."));
    putc('\n', stdout);    
    return 0;
}

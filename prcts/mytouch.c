//linux touch命令简单实现
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int fd;
    //struct timespec ts[2];
    //ts[0].tv_nsec = UTIME_NOW;//将访问时间改为当前时间
    //ts[1].tv_nsec = UTIME_OMIT;//修改时间保持不变

    if(argc != 2) {
        printf("usage: touch <path>\n");
        exit(0);
    }

    if((fd = open(argv[1], O_CREAT, 0777)) == -1) {//不存在就创建
        perror("open");
        exit(-1);
    }

    if(futimens(fd, NULL) == -1) {//指定为NULL，则将访问时间和修改时间都改为当前时间
        perror("utimes");
        exit(-1);
    }

    close(fd);

    return 0;
}

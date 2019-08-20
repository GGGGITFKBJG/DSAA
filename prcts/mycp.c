//c linux cp命令简单实现
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFSIZE 1024

int main(int argc, char* argv[]) {
    int fsrc, fdist;
    int readsize;
    char buf[BUFFSIZE];
    if(argc != 3) {
        printf("usage: mycp fsrc fdest\n");
        exit(0);
    }

    if( (fsrc = open(argv[1], O_RDONLY)) == -1) {
        perror("open error");
        exit(-1);
    }
    if( (fdist = open(argv[2], O_CREAT | O_EXCL | O_WRONLY, 0777)) == -1) {
        perror("creat error");
        exit(-1);
    }

    do {
        readsize = read(fsrc, buf, BUFFSIZE);
        write(fdist, buf, readsize);
    } while(readsize == BUFFSIZE);

    close(fsrc);
    close(fdist);
    return 0;
}

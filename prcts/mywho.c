//linux who命令简单实现
#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void showtime(time_t tvs) {//将时间格式化输出
    char buf[256];
    struct tm* ltm;
    int len;
    
    ltm = localtime(&tvs);
    len = strftime(buf, sizeof(buf), "%F %R", ltm);
    if(len < 256) buf[len] = '\0';
    else return;
    printf("%s   ", buf);
}

void print_utmp(struct utmp* putp) {//打印utp结构的信息
    if(putp->ut_type != USER_PROCESS) return;//如果不是用户进程就跳过

    printf("%s   ", putp->ut_name);//用户名
    printf("%s   ", putp->ut_line);//终端行
    showtime(putp->ut_time);//显示格式化后的时间
    printf(" (%s)", putp->ut_host);//主机名
    putc('\n', stdout);
}

int main() {
    struct utmp utp;
    int sz = sizeof(utp);
    int utmpfd;

    if((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1) {//打开记录文件/var/run/utmp
        perror("open");
        exit(0);
    }

    while(read(utmpfd, &utp, sz) == sz) {//反复读取，填充结构utp
        print_utmp(&utp);
    }

    close(utmpfd);

    return 0;
}

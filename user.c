#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>

#define NOD_NAME "/dev/ssafyFile"

struct Node{
    char n;
    char buf[30];
};

int main(){
    int fd = open(NOD_NAME, O_RDWR);
    if( fd<0 ){
        printf("ERROR\n");
        exit(1);
    }

    struct Node readData;
    struct Node writeData = {'S', "THIS IS SILVERLIGHT"};

    ioctl(fd, _IO(0,3), &readData);
    printf("from Kernel : %d %s\n", (int)readData.n, readData.buf);

    ioctl(fd, _IO(0,4), &writeData);
    printf("Send to Kernel\n");

    close(fd);
    return 0;
}

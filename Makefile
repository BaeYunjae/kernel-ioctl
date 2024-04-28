KERNEL_HEADERS=/lib/modules/$(shell uname -r)/build
CC = gcc

TARGET := user
obj-m += ssafy.o

PWD := $(CURDIR)

all: driver app

driver:
    make -C $(KERNEL_HEADERS) M=$(PWD) modules

app:
    $(CC) -o $(TARGET) user.c

clean:
    make -C $(KERNEL_HEADERS) M=$(PWD) clean
    rm -f *.o $(TARGET)

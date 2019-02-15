#CC:=arm-linux-gcc
CC:=gcc
LDFLAGS=

all : main.o dataManageDll

main.o : main.c
    $(CC) -c main.c $(LDFLAGS)
dataManageDll : 
    $(CC) -o dataManageDll main.o
clean :
    rm *.o dataManageDll

#CC:=arm-linux-gcc
CC:=gcc
LDFLAGS=

all: main.o dataManageBst

main.o: main.c
	$(CC) -c main.c $(LDFLAGS)
dataManageBst:
	$(CC) -o dataManageBst main.o
clean:
	rm *.o dataManageBst

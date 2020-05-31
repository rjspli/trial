#CC:=arm-linux-gcc
CC:=gcc
LDFLAGS=-lpthread

all: dataControl.o initAndTerm.o main.o dataManageBst

dataControl.o: dataControl.c
	$(CC) -c dataControl.c $(LDFLAGS)
initAndTerm.o: initAndTerm.c
	$(CC) -c initAndTerm.c
main.o: main.c
	$(CC) -c main.c $(LDFLAGS)
dataManageBst:
	$(CC) -o dataManageBst main.o initAndTerm.o dataControl.o $(LDFLAGS)
clean:
	rm *.o dataManageBst

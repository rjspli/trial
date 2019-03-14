#CC:=arm-linux-gcc
CC:=gcc
LDFLAGS=

all: dataControl.o initAndTerm.o main.o dataManageBst

dataControl.o: dataControl.c
	$(CC) -c dataControl.c $(LDFLAGS)
initAndTerm.o: initAndTerm.c
	$(CC) -c initAndTerm.c $(LDFLAGS)
main.o: main.c
	$(CC) -c main.c $(LDFLAGS)
dataManageBst:
	$(CC) -o dataManageBst main.o initAndTerm.o dataControl.o
clean:
	rm *.o dataManageBst

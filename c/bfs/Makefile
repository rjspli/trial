#CC:=arm-linux-gcc
CC:=gcc
LDFLAGS=

all: dataControl.o initAndTerm.o main.o manageBfs

dataControl.o: dataControl.c
	$(CC) -c dataControl.c $(LDFLAGS)
initAndTerm.o: initAndTerm.c
	$(CC) -c initAndTerm.c $(LDFLAGS)
main.o: main.c
	$(CC) -c main.c $(LDFLAGS)
manageBfs:
	$(CC) -o manageBfs main.o initAndTerm.o dataControl.o
clean:
	rm *.o manageBfs

#CC:=arm-linux-gcc
CC:=gcc
LDFLAGS=

all: initAndTerm.o dataControl.o main.o dataManageDll

initAndTerm.o:  initAndTerm.c
	$(CC) -c initAndTerm.c $(LDFLAGS)
dataControl.o: dataControl.c
	$(CC) -c dataControl.c $(LDFLAGS)
main.o: main.c
	$(CC) -c main.c $(LDFLAGS)
dataManageDll:
	$(CC) -o dataManageDll initAndTerm.o dataControl.o main.o
clean:
	rm *.o dataManageDll

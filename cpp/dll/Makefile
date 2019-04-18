#CC:=arm-linux-gcc
CC:=g++
LDFLAGS=

all: Format.o InitAndTerm.o DataControl.o DllMain.o manageDLL

Format.o: Format.cpp
	$(CC) -c Format.cpp $(LDFLAGS)
InitAndTerm.o: InitAndTerm.cpp
	$(CC) -c InitAndTerm.cpp $(LDFLAGS)
DataControl.o: DataControl.cpp
	$(CC) -c DataControl.cpp $(LDFLAGS)
DllMain.o: DllMain.cpp
	$(CC) -c DllMain.cpp $(LDFLAGS)
manageDLL:
	$(CC) -o manageDLL Format.o InitAndTerm.o DataControl.o DllMain.o
clean:
	rm *.o manageDLL

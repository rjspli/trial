OBJS =
CC ?= gcc
AR ?= ar
CFLAGS = -O -Wall
TARGET = dataManageDll
LIB_NAME = DLLframe
LIB_TARGET = lib$(LIB_NAME).a
LIB_DIR = .
LDFLAGS =

all: fileLoadWrite.o initAndTerm.o dataControl.o main.o $(LIB_TARGET) $(TARGET)

fileLoadWrite.o: fileLoadWrite.c fileLoadWrite.h
	$(CC) -c fileLoadWrite.c $(CFLAGS) $(LDFLAGS)
initAndTerm.o:  initAndTerm.c initAndTerm.h
	$(CC) -c initAndTerm.c $(CFLAGS) $(LDFLAGS)
dataControl.o: dataControl.c dataControl.h
	$(CC) -c dataControl.c $(CFLAGS) $(LDFLAGS)
main.o: main.c fileLoadWrite.h initAndTerm.h dataControl.h
	$(CC) -c main.c $(CFLAGS) $(LDFLAGS)
$(LIB_TARGET): fileLoadWrite.o initAndTerm.o dataControl.o
	$(AR) rc $(LIB_TARGET) fileLoadWrite.o initAndTerm.o dataControl.o
$(TARGET):
	$(CC) -o $(TARGET) main.o -L$(LIB_DIR) -l$(LIB_NAME)
clean:
	rm *.o $(LIB_TARGET) $(TARGET)

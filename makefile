.PHONY = doc clean

CC = g++

OPTIONS = -g -Wall

DEBUG = #-D DEBUG

LIBDIR = lib

INCLUDEDIR = include

_OBJ= tcomplejo.o tlistacom.o tavlcom.o ta234com.o

OBJ = $(patsubst %,$(LIBDIR)/%,$(_OBJ))

all: tad

tad: ./src/tad.cpp $(OBJ)
	$(CC) $(OPTIONS) $(DEBUG) -I$(INCLUDEDIR) ./src/tad.cpp $(OBJ) -o tad

$(LIBDIR)/%.o : $(LIBDIR)/%.cpp $(INCLUDEDIR)/%.h
	$(CC) $(OPTIONS) $(DEBUG) -c -I$(INCLUDEDIR) -o $@ $<

doc:
	doxygen DOXYFILE

clean:
	rm -f $(OBJ) 
	rm -f tad

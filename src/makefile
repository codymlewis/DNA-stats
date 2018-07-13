CC=g++
CFLAGS=-c -g -Wall
LDFLAGS=
SOURCES=Codon.cpp Strand.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=DNA_sim

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core

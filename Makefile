CC=g++
CFLAGS=-c -g -Wall -std=c++14
LDFLAGS=-lm
SOURCES=Test.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Test

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) obj/$(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o obj/$@

clean:
	-rm -f obj/*.o
	-rm -f $(EXECUTABLE)

CC = g++
CFLAGS = -Wall -O6
SRC = ../src

.PHONY: clean

test: $(patsubst %.cpp,%.out,$(wildcard example*.cpp))

%.out: %.cpp $(SRC)/*.cpp
	$(CC) $(CFLAGS) $? -o $@ -I $(SRC)

clean:
	rm -f *.o *.out
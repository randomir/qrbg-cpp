CC = g++
CFLAGS = -Wall -O6
LIB = qrbgcpp
SRCDIR = ../src
OUT = $(patsubst %.cpp,%.out,$(wildcard example*.cpp))

.PHONY: clean

linked: QRBG = $(SRCDIR)/*.cpp
linked: INC = -I $(SRCDIR)
linked: clean $(OUT)

shared: QRBG = -l $(LIB)
shared: INC =
shared: clean $(OUT)

%.out: %.cpp
	$(CC) $(CFLAGS) $? $(QRBG) $(INC) -o $@

clean:
	rm -f *.o *.out

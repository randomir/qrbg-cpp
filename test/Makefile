CC = g++
CFLAGS = -Wall -O6
LIB = qrbgcpp
SRCDIR = ../src
OUT = $(patsubst %.cpp,%.out,$(wildcard example*.cpp))

.PHONY: clean

linked: QRBG = $(SRCDIR)/*.cpp
linked: INC = -I $(SRCDIR)
linked: $(OUT)

shared: QRBG = -l $(LIB)
shared: INC =
shared: $(OUT)

%.out: %.cpp
	$(CC) $(CFLAGS) $? $(QRBG) $(INC) -o $@

clean:
	rm -f *.o *.out

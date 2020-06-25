CC=clang++
CXX=clang++
CXXFLAGS=-Wall -Wextra -Werror -std=c++17

EXECUTABLES=name-age name-age-class vector-sort write-read-file

all: $(EXECUTABLES)

name-age-class: name-age-class-main.o name-age-class.o

clean:
	@rm -f *.o
	@rm -f $(EXECUTABLES)

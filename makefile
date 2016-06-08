#CC    = g++
CC = clang++-3.6
FILES = $(wildcard AdventureTime2/*.cpp)
OBJ_FILES = $(subst .cpp,.o,$(FILES))
FLAGS = -std=c++11 -stdlib=libc++


run: $(OBJ_FILES)
	$(CC) $(FLAGS) $(FILES) -o run $(OBJ_FILES)
clean:
	rm -f *.o *.out
CC = gcc
CFLAGS = -Iinclude -Wall -fPIC
SRC = src/strutils.c
OBJ = build/strutils.o

STATIC_LIB = build/libstrutils.a
SHARED_LIB = build/libstrutils.so

all: static shared main_static main_shared

static: $(OBJ)
	ar rcs $(STATIC_LIB) $(OBJ)

shared: $(OBJ)
	$(CC) -shared -o $(SHARED_LIB) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

main_static: examples/main.c $(STATIC_LIB)
	$(CC) examples/main.c -Iinclude -Lbuild -lstrutils -o build/main_static

main_shared: examples/main.c $(SHARED_LIB)
	$(CC) examples/main.c -Iinclude -Lbuild -lstrutils -o build/main_shared

clean:
	rm -rf build/*.o build/*.a build/*.so build/main_*

.PHONY: all static shared clean

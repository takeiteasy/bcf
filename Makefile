OUT=build/
LIB=$(OUT)cf
SRC=src/cf.c
EXE=$(OUT)test
CC=clang

all: $(EXE)

lib: $(LIB).dylib

$(EXE): $(EXE).o $(LIB).dylib
	$(CC) $^ -o $@

$(EXE).o: tests/test.c $(LIB).dylib
	$(CC) -c $< -o $@

$(LIB).dylib: $(LIB).o
	$(CC) -shared -fpic -o $@ $^

$(LIB).o: src/cf.c $(OUT)
	$(CC) -c -o $@ $<

$(OUT):
	mkdir $@

.PHONY: all clean
clean:
	rm -rf $(OUT)

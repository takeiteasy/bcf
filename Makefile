OUT=build/
LIB=$(OUT)bcf
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

$(LIB).o: src/bcf.c $(OUT)
	$(CC) -c -o $@ $<

$(OUT):
	mkdir $@

.PHONY: all clean
clean:
	rm -rf $(OUT)

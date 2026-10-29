CC ?= cc
CFLAGS ?= -std=c99 -Wall -Wextra -Werror -pedantic
CPPFLAGS += -Isrc

APP = hello
TEST = test_hello

.PHONY: all test clean

all: $(APP)

$(APP): src/main.c src/hello.c src/hello.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ src/main.c src/hello.c

$(TEST): tests/test_hello.c src/hello.c src/hello.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ tests/test_hello.c src/hello.c

test: $(TEST)
	./$(TEST)

clean:
	rm -f $(APP) $(TEST)

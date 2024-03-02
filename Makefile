
CC ?= gcc
CFLAGS ?= -O2 -pedantic -Wall -Werror -DPRINT_LIB_COLOR

OUT = test_print_lib
SRC = print.c print_lib.c
OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

.PHONY: clean
clean:
	rm -rf $(OUT) $(OBJ)

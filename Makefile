
CC ?= gcc

CDEFS += -DPRINT_LIB_COLOR
CDEFS += -DPRINT_DISABLE_SYSLOG
CDEFS += -DPRINT_MSG_BUF_SZ=1024

CFLAGS ?= -O2 -pedantic -Wall -Werror
CFLAGS += $(CDEFS)

OUT = test_print_lib
SRC = print.c print_lib.c
OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(OUT) libprintlib.a

libprintlib.a: $(OBJ)
	ar -cr $@ $(OBJ)

$(OUT): libprintlib.a
	$(CC) $(CFLAGS) -L. -o $@ print.c -lprintlib

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

.PHONY: clean
clean:
	rm -rf $(OUT) $(OBJ)

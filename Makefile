
CC ?= gcc

CDEFS += -DPRINT_LIB_COLOR
CDEFS += -DPRINT_DISABLE_SYSLOG
CDEFS += -DPRINT_MSG_BUF_SZ=1024
CDEFS += -DPRINT_LOG_LEVEL=5

CFLAGS ?= -O2 -pedantic -Wall -Werror -flto
CFLAGS += $(CDEFS)

OUT = test_print_lib
SRC = print.c print_lib.c
OBJ = $(patsubst %.c, %.o, $(SRC))
LIB = libprintlib.a

all: $(OUT) $(LIB)

$(LIB): $(OBJ)
	ar -cr $@ $(OBJ)

$(OUT): $(LIB)
	$(CC) $(CFLAGS) -L. -o $@ print.c -lprintlib

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

.PHONY: clean
clean:
	rm -rf $(OUT) $(OBJ) $(LIB)

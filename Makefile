
CC ?= gcc

CDEFS += -DCLOG_LIB_COLOR
CDEFS += -DCLOG_DISABLE_SYSLOG
CDEFS += -DCLOG_MSG_BUF_SZ=1024
CDEFS += -DCLOG_LOG_LEVEL=5

CFLAGS ?= -O2 -pedantic -Wall -Werror -flto
CFLAGS += $(CDEFS)

OUT = test_clog_lib
SRC = clog.c clog_lib.c
OBJ = $(patsubst %.c, %.o, $(SRC))
LIB = libcloglib.a

all: $(OUT) $(LIB)

$(LIB): $(OBJ)
	ar -cr $@ $(OBJ)

$(OUT): $(LIB)
	$(CC) $(CFLAGS) -L. -o $@ clog.c -lcloglib

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

.PHONY: clean
clean:
	rm -rf $(OUT) $(OBJ) $(LIB)

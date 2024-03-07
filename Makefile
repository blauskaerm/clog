
CC ?= gcc

ifeq ($(CLOG_LOG_COLOR),y)
CDEFS += -DCLOG_LOG_COLOR
endif

ifdef ($(CLOG_DISABLE_SYSLOG),y)
CDEFS += -DCLOG_DISABLE_SYSLOG
endif

ifdef CLOG_MSG_BUF_SZ
CDEFS += -DCLOG_MSG_BUF_SZ=$(CLOG_MSG_BUF_SZ)
endif

ifdef CLOG_LOG_LEVEL
CDEFS += -DCLOG_LOG_LEVEL=$(CLOG_LOG_LEVEL)
endif

CFLAGS ?= -O2 -pedantic -Wall -Werror -flto
CFLAGS += $(CDEFS)

SRC = clog.c
OBJ = $(patsubst %.c, %.o, $(SRC))
LIB = libclog.a

all: $(LIB)

$(LIB): $(OBJ)
	ar -cr $@ $(OBJ)

demo: $(LIB)
	$(CC) $(CFLAGS) -L. -o $@ demo.c -lclog

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

.PHONY: clean
clean:
	rm -rf demo $(OBJ) $(LIB)

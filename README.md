# CLog

Clog is a simple logging library written in C. The build procedure produces a
library that your project can link against. Features that are included in the
library can be controlled by setting environment variables from your top make
file. The table below describes implemented variables.

| Environment variable | Description                                     | Value   | Default |
|----------------------|-------------------------------------------------|---------|---------|
| CLOG_LOG_COLOR       | Enable fancy colors                             | y/n     | n       |
| CLOG_DISABLE_SYSLOG  | Disable syslog integration                      | y/n     | n       |
| CLOG_MSG_BUF_SZ      | Adjust print buffer size, set to 1kB by default | Integer | 1024    |
| CLOG_LOG_LEVEL       | Control log level                               | 0 to 5  | 5       |

# Log level

Clog implements five log levels, which can be enabled by defining the
environment variable `CLOG_LOG_LEVEL` during compile time. See table below.

| Log level           | CLOG_LOG_LEVEL |
|---------------------|----------------|
| Disable all logging | 0              |
| Error               | 1              |
| Warning             | 2              |
| Info                | 3              |
| Notice              | 4              |
| Debug               | 5              |

# Embedded applications

It's possible to use clog in embedded applications. The library depends on
`snprintf()` so newlib or similar library is required.

Disable syslog integration by setting environment variable `CLOG_DISABLE_SYSLOG`
to "y".

Two buffers are allocated on the stack when formatting the output string and are
set to 1kB per default. Their sizes can be adjusted during compile time by the
environment variable `CLOG_MSG_BUF_SZ`.

Clog prints to the console by calling function

```c
void clog_put(const char *buf, size_t buf_sz)
```

This function could be overridden during linking with a custom function, such as
printing to a connected UART.

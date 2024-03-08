#ifndef _CLOG_
#define _CLOG_

void clog_debug(const char *, ...)
  __attribute__((format(printf, 1, 2)));

void clog_notice(const char *, ...)
  __attribute__((format(printf, 1, 2)));

void clog_info(const char *, ...)
  __attribute__((format(printf, 1, 2)));

void clog_warning(const char *, ...)
  __attribute__((format(printf, 1, 2)));

void clog_error(const char *, ...)
  __attribute__((format(printf, 1, 2)));

void clog_print(const char *, ...)
  __attribute__((format(printf, 1, 2)));

void clog_put(const char *, size_t)
  __attribute__((weak));

void clog_open(const char *);
void clog_close(void);

#endif

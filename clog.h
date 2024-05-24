#ifndef _CLOG_
#define _CLOG_

#ifdef CLOG_LOG_LEVEL
#define _CLOG_LOG_LEVEL CLOG_LOG_LEVEL
#else
#define _CLOG_LOG_LEVEL 5
#endif

enum clog_severity {
  CLOG_WARNING,
  CLOG_NOTICE,
  CLOG_INFO,
  CLOG_DEBUG,
  CLOG_ERROR,
  CLOG_NONE,
};

void clog_msg(const enum clog_severity, const char *, ...)
  __attribute__((format(printf, 2, 3)));

#if _CLOG_LOG_LEVEL >= 5
#define clog_debug(...) clog_msg(CLOG_DEBUG, __VA_ARGS__)
#else
#define clog_debug(...)
#endif

#if _CLOG_LOG_LEVEL >= 4
#define clog_notice(...) clog_msg(CLOG_NOTICE, __VA_ARGS__)
#else
#define clog_notice(...)
#endif

#if _CLOG_LOG_LEVEL >= 3
#define clog_info(...) clog_msg(CLOG_INFO, __VA_ARGS__)
#else
#define clog_info(...)
#endif

#if _CLOG_LOG_LEVEL >= 2
#define clog_warning(...) clog_msg(CLOG_WARNING, __VA_ARGS__)
#else
#define clog_warning(...)
#endif

#if _CLOG_LOG_LEVEL >= 1
#define clog_error(...) clog_msg(CLOG_ERROR, __VA_ARGS__)
#else
#define clog_error(...)
#endif

#if _CLOG_LOG_LEVEL > 0
#define clog_print(...) clog_msg(CLOG_NONE, __VA_ARGS__)
#else
#define clog_print(...)
#endif

void clog_put(const char *, size_t)
  __attribute__((weak));

void clog_open(const char *);
void clog_close(void);

#endif

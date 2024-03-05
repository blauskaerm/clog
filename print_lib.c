#include <stdio.h>
#include <stdarg.h>
#include "print_lib.h"

#include <syslog.h>

#define COLOR_YELLOW "\033[93m"
#define COLOR_GREEN  "\033[92m"
#define COLOR_BLUE   "\033[94m"
#define COLOR_WHITE  "\033[93m"
#define COLOR_RED    "\033[91m"
#define COLOR_RESET  "\033[0m"

#define MSG_WARNING "WARNING"
#define MSG_NOTICE  " NOTICE"
#define MSG_INFO    "   INFO"
#define MSG_DEBUG   "  DEBUG"
#define MSG_ERROR   "  ERROR"

#ifdef PRINT_LIB_COLOR
#define SEVERITY_WARNING COLOR_YELLOW MSG_WARNING COLOR_RESET
#define SEVERITY_NOTICE  COLOR_GREEN  MSG_NOTICE  COLOR_RESET
#define SEVERITY_INFO    COLOR_BLUE   MSG_INFO    COLOR_RESET
#define SEVERITY_DEBUG   COLOR_WHITE  MSG_DEBUG   COLOR_RESET
#define SEVERITY_ERROR   COLOR_RED    MSG_ERROR   COLOR_RESET
#else
#define SEVERITY_WARNING MSG_WARNING
#define SEVERITY_NOTICE  MSG_NOTICE
#define SEVERITY_INFO    MSG_INFO
#define SEVERITY_DEBUG   MSG_DEBUG
#define SEVERITY_ERROR   MSG_ERROR
#endif

enum print_severity {
  PRINT_WARNING,
  PRINT_NOTICE,
  PRINT_INFO,
  PRINT_DEBUG,
  PRINT_ERROR
};

#define MSG_BUF_SZ 1024

static void print_vmsg(const enum print_severity severity,
                       const char *fmt,
                       va_list list) {

  ssize_t res;
  char out_buf[MSG_BUF_SZ];
  char msg_buf[MSG_BUF_SZ];
  const char *severity_str;
  int syslog_priority;

  switch(severity) {
  case PRINT_WARNING:
    severity_str = SEVERITY_WARNING;
    syslog_priority = LOG_WARNING;
    break;
  case PRINT_NOTICE:
    severity_str = SEVERITY_NOTICE;
    syslog_priority = LOG_NOTICE;
    break;
  case PRINT_INFO:
    severity_str = SEVERITY_INFO;
    syslog_priority = LOG_INFO;
    break;
  case PRINT_DEBUG:
    severity_str = SEVERITY_DEBUG;
    syslog_priority = LOG_DEBUG;
    break;
  case PRINT_ERROR:
    severity_str = SEVERITY_ERROR;
    syslog_priority = LOG_ERR;
    break;
  }

  res = vsnprintf(msg_buf, sizeof(msg_buf), fmt, list);
  if (res <= 0 || (size_t) res >= sizeof(msg_buf)) {
    (void)snprintf(msg_buf, sizeof(msg_buf), "PRINT OVERFLOW\n");
  }
  res = snprintf(out_buf, sizeof(out_buf), "%s: %s", severity_str, msg_buf);
  if (res <= 0 || (size_t) res >= sizeof(out_buf)) {
    (void)snprintf(out_buf, sizeof(out_buf), "FMT OVERFLOW\n");
  }

  syslog(syslog_priority, "%s", msg_buf);

  print_put(out_buf, res);
}

void print_open(const char *ident) {
  openlog(ident, LOG_PID, LOG_USER);
}

void print_close(void) {
  closelog();
}

void print_debug(const char *fmt, ...) {

  va_list list;

  va_start(list, fmt);
  print_vmsg(PRINT_DEBUG, fmt, list);
  va_end(list);
}

void print_info(const char *fmt, ...) {

  va_list list;

  va_start(list, fmt);
  print_vmsg(PRINT_INFO, fmt, list);
  va_end(list);
}

void print_warning(const char *fmt, ...) {

  va_list list;

  va_start(list, fmt);
  print_vmsg(PRINT_WARNING, fmt, list);
  va_end(list);
}

void print_error(const char *fmt, ...) {

  va_list list;

  va_start(list, fmt);
  print_vmsg(PRINT_ERROR, fmt, list);
  va_end(list);
}

void print_notice(const char *fmt, ...) {

  va_list list;

  va_start(list, fmt);
  print_vmsg(PRINT_NOTICE, fmt, list);
  va_end(list);
}

void print_put(const char *buf, size_t buf_sz) {
  printf("%s", buf);
  (void)buf_sz;
}

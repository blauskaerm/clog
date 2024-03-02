#include <stdio.h>
#include <stdarg.h>

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

static void print_status(const char *severity, const char *fmt, va_list list) {

  ssize_t res;
  char fmt_buf[64];
  char print_buf[200];

  res = snprintf(fmt_buf, sizeof(fmt_buf), "%s: %s", severity, fmt);
  if (res <= 0 || (size_t) res >= sizeof(fmt_buf)) {
    (void)snprintf(fmt_buf, sizeof(fmt_buf), "FMT OVERFLOW\n");
  }
  res = vsnprintf(print_buf, sizeof(print_buf), fmt_buf, list);
  if (res <= 0 || (size_t) res >= sizeof(print_buf)) {
    (void)snprintf(print_buf, sizeof(print_buf), "PRINT OVERFLOW\n");
  }

  printf("%s", print_buf);
}

void print_debug(const char *fmt, ...) {

  va_list list;

  va_start(list, fmt);
  print_status(SEVERITY_DEBUG, fmt, list);
  va_end(list);
}

void print_info(const char *fmt, ...) {

  va_list list;

  va_start(list, fmt);
  print_status(SEVERITY_INFO, fmt, list);
  va_end(list);
}

void print_warning(const char *fmt, ...) {

  va_list list;

  va_start(list, fmt);
  print_status(SEVERITY_WARNING, fmt, list);
  va_end(list);
}

void print_error(const char *fmt, ...) {

  va_list list;

  va_start(list, fmt);
  print_status(SEVERITY_ERROR, fmt, list);
  va_end(list);
}

void print_notice(const char *fmt, ...) {

  va_list list;

  va_start(list, fmt);
  print_status(SEVERITY_NOTICE, fmt, list);
  va_end(list);
}

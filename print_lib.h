
void print_notice(const char *, ...)
  __attribute__((format(printf, 1, 2)));

void print_error(const char *, ...)
  __attribute__((format(printf, 1, 2)));

void print_warning(const char *, ...)
  __attribute__((format(printf, 1, 2)));

void print_info(const char *, ...)
  __attribute__((format(printf, 1, 2)));

void print_debug(const char *, ...)
  __attribute__((format(printf, 1, 2)));
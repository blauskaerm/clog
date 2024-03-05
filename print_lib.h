
void print_put(const char *, size_t)
  __attribute__((weak));

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

void print_open(const char *);
void print_close(void);

#include <stddef.h>
#include "clog.h"

int main(void) {

  clog_open(NULL);

  clog_debug("Hello world\n");
  clog_info("Hello world\n");
  clog_notice("Hello world\n");
  clog_warning("Hello world\n");
  clog_error("Hello world\n");
  clog_print("  Print: Hello world\n");

  clog_close();
}

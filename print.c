#include <stddef.h>
#include "print_lib.h"

int main(void) {

  print_open(NULL);

  print_debug("Hello world\n");
  print_info("Hello world\n");
  print_notice("Hello world\n");
  print_warning("Hello world\n");
  print_error("Hello world\n");

  print_close();
}

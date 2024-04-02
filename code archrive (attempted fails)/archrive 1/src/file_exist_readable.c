#include "headers/main.h"

unsigned int verify_files_exist_and_readable(int argc, char **argv) {
  /* Returns 0 if all files exists
   * and readable. Otherwise returns
   * number of bad arguments.
   * Also prints an error message.
   */
  unsigned int number_of_invalid_files = 0;
  for (int i = 1; i < argc; ++i) {
    if (access(argv[i], F_OK) != 0) {
      number_of_invalid_files++;
      printf("%s does not exist.\n", argv[i]);
    } else if (access(argv[i], R_OK) != 0) {
      number_of_invalid_files++;
      printf("%s exists, but you do not have read access.\n", argv[i]);
    }
  }
  return number_of_invalid_files;
}

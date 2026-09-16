/* Drives the memory-corruption fixtures one at a time under ASan/UBSan.
 * Each probe is expected to abort; a clean exit means the tool missed it. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/tigergate.h"

int main(int argc, char **argv) {
  const char *which = argc > 1 ? argv[1] : "uaf";
  printf("probe: %s\n", which);
  if (strcmp(which, "uaf") == 0)      { char *p = dup_and_free("x"); printf("%c\n", p[0]); }
  if (strcmp(which, "dfree") == 0)    { double_release(32); }
  if (strcmp(which, "overflow") == 0) { copy_fixed("this string is far longer than sixteen bytes"); }
  if (strcmp(which, "oob") == 0)      { int a[4] = {1,2,3,4}; printf("%d\n", sum_array(a, 4)); }
  if (strcmp(which, "intwrap") == 0)  { char *p = alloc_records(0x10000, 0x10000); free(p); }
  puts("probe returned normally");
  return 0;
}

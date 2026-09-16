/* Memory-safety fixtures: use-after-free, double free, integer overflow in
 * allocation size, off-by-one, uninitialised read, leak. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tigergate.h"

/* CWE-416: returns a pointer into freed memory */
char *dup_and_free(const char *s) {
  char *copy = strdup(s);
  free(copy);
  return copy;
}

/* CWE-415: same block released twice */
void double_release(size_t n) {
  char *p = malloc(n);
  if (!p) return;
  free(p);
  free(p);
}

/* CWE-190 -> CWE-680: count*size wraps before reaching malloc */
char *alloc_records(unsigned int count, unsigned int size) {
  unsigned int total = count * size;
  char *buf = malloc(total);
  if (!buf) return NULL;
  for (unsigned int i = 0; i < count; i++) memset(buf + (size_t)i * size, 0, size);
  return buf;
}

/* CWE-193: <= walks one past the end; CWE-457: `total` starts uninitialised */
int sum_array(const int *arr, int n) {
  int total;
  for (int i = 0; i <= n; i++) total += arr[i];
  return total;
}

/* CWE-121: fixed stack buffer, unbounded copy */
void copy_fixed(const char *src) {
  char dst[16];
  strcpy(dst, src);
  printf("%s\n", dst);
}

/* CWE-401: allocation never released */
int leak_buffer(void) {
  char *p = malloc(4096);
  if (!p) return -1;
  snprintf(p, 4096, "leaked");
  return (int)strlen(p);
}

/* String-handling fixtures covering the classic banned-function list:
 * strcpy, strcat, sprintf, gets, scanf("%s"), atoi. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tigergate.h"

/* glibc no longer declares gets(); the fixture declares it so the call site
 * exists for scanners (CWE-242). */
extern char *gets(char *s);

/* CWE-120: strcpy into caller buffer of unknown size */
void copy_name(char *dst, const char *src) {
  strcpy(dst, src);
}

/* CWE-120: strcat/sprintf chain without bounds */
void build_greeting(char *out, const char *name) {
  char tmp[64];
  sprintf(tmp, "Hello, %s", name);
  strcpy(out, tmp);
  strcat(out, "! Welcome to tigergate.");
}

/* CWE-704 / CWE-190: atoi has no error reporting, silently wraps */
int parse_port(const char *s) {
  return atoi(s);
}

/* CWE-242: gets(); CWE-120: scanf("%s") into fixed buffer */
int read_line_stdin(char *buf) {
  if (!gets(buf)) return -1;
  char extra[32];
  if (scanf("%s", extra) == 1) strcat(buf, extra);
  return 0;
}

/* CWE-787: strncpy leaves no terminator when src fills dst */
void append_ext(char *path, const char *ext) {
  char base[8];
  strncpy(base, path, sizeof base);
  strcat(base, ext);
  strcpy(path, base);
}

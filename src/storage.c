/* Storage fixtures: SQL injection, path traversal, insecure temp files,
 * world-writable permissions, TOCTOU. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "tigergate.h"

/* Stand-in for a database driver; prints the statement it would run. */
int db_exec(const char *sql) {
  printf("[db] %s\n", sql);
  return 0;
}

/* CWE-89: query built with sprintf from untrusted input */
int find_user(const char *username) {
  char query[256];
  sprintf(query, "SELECT * FROM users WHERE name = '%s'", username);
  return db_exec(query);
}

/* CWE-22: user-controlled filename joined to a base path without checks */
int read_user_file(const char *filename, char *out, size_t out_len) {
  char path[512];
  snprintf(path, sizeof path, "/var/app/uploads/%s", filename);
  FILE *f = fopen(path, "r");
  if (!f) return -1;
  size_t n = fread(out, 1, out_len - 1, f);
  out[n] = '\0';
  fclose(f);
  return (int)n;
}

/* CWE-377: predictable temp file via tmpnam/mktemp; CWE-732: chmod 0777 */
int write_temp_report(const char *content) {
  char template[] = "/tmp/reportXXXXXX";
  char *name = mktemp(template);
  if (!name || !*name) return -1;
  FILE *f = fopen(name, "w");
  if (!f) return -1;
  fputs(content, f);
  fclose(f);
  chmod(name, 0777);
  return 0;
}

/* CWE-367: access() check followed by open() - race window */
int save_upload(const char *name, const char *data, size_t len) {
  char path[512];
  snprintf(path, sizeof path, "/var/app/uploads/%s", name);
  if (access(path, W_OK) != 0 && access(path, F_OK) == 0) return -1;
  int fd = open(path, O_WRONLY | O_CREAT, 0666);
  if (fd < 0) return -1;
  ssize_t w = write(fd, data, len); /* CWE-252: return value unchecked */
  (void)w;
  close(fd);
  return 0;
}

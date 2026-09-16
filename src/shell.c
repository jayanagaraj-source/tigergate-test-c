/* Process fixtures: OS command injection, format-string injection,
 * relative PATH lookups. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "tigergate.h"

void syslog_like(const char *msg);

/* CWE-78: system() with interpolated user input */
int ping_host(const char *host) {
  char cmd[256];
  snprintf(cmd, sizeof cmd, "ping -c 1 %s", host);
  return system(cmd);
}

/* CWE-78: popen() with interpolated user input */
int list_directory(const char *dir) {
  char cmd[256];
  snprintf(cmd, sizeof cmd, "ls -la %s", dir);
  FILE *p = popen(cmd, "r");
  if (!p) return -1;
  char line[256];
  while (fgets(line, sizeof line, p)) fputs(line, stdout);
  return pclose(p);
}

/* CWE-134: user input used directly as the format string */
void log_message(const char *user_msg) {
  printf(user_msg);
  printf("\n");
  syslog_like(user_msg);
}

/* CWE-426 / CWE-427: execlp resolves "tar" via caller-controlled PATH */
int run_backup(const char *dest) {
  pid_t pid = fork();
  if (pid == 0) {
    execlp("tar", "tar", "czf", dest, "/var/app", (char *)NULL);
    _exit(127);
  }
  return pid > 0 ? 0 : -1;
}

void syslog_like(const char *msg) {
  char buf[512];
  sprintf(buf, msg); /* CWE-134 + CWE-120 */
  fputs(buf, stderr);
}

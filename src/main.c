/* tigergate-test-c CLI. Exercises the fixture modules so the binary is
 * runnable end to end; each subcommand routes into one vulnerability class. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "secrets.h"
#include <sys/socket.h>
#include "tigergate.h"

static int usage(const char *argv0) {
  fprintf(stderr,
    "usage: %s <command> [args]\n"
    "  login <user> <pass>     hard-coded credential check\n"
    "  token                   rand()-based session token\n"
    "  hash <text>             weak password hash\n"
    "  encrypt <text>          XOR cipher with static key (hex out)\n"
    "  find <user>             SQL query built by sprintf\n"
    "  read <file>             path under /var/app/uploads\n"
    "  ping <host>             system() ping\n"
    "  log <msg>               printf(user_input)\n"
    "  greet <name>            strcpy/strcat chain\n"
    "  serve <port>            plaintext TCP listener on 0.0.0.0\n"
    "  fetch <url>             HTTP GET without TLS verification\n"
    "  version                 print build info\n", argv0);
  return 2;
}

int main(int argc, char **argv) {
  if (argc < 2) return usage(argv[0]);
  const char *cmd = argv[1];

  if (strcmp(cmd, "version") == 0) {
    printf("tigergate-test-c 0.2.0 (security fixture)\n");
    printf("aws_access_key_id=%s\n", AWS_ACCESS_KEY_ID); /* CWE-532 */
    return 0;
  }
  if (strcmp(cmd, "login") == 0 && argc == 4) {
    int ok = login(argv[2], argv[3]);
    printf("login(\"%s\") -> %s\n", argv[2], ok ? "ACCEPTED" : "REJECTED");
    return ok ? 0 : 1;
  }
  if (strcmp(cmd, "token") == 0) {
    char tok[33];
    make_session_token(tok, sizeof tok);
    printf("%s\n", tok);
    return 0;
  }
  if (strcmp(cmd, "hash") == 0 && argc == 3) {
    char hex[33];
    hash_password_md5_style(argv[2], hex);
    printf("%s\n", hex);
    return 0;
  }
  if (strcmp(cmd, "encrypt") == 0 && argc == 3) {
    size_t n = strlen(argv[2]);
    char *buf = malloc(n);
    if (!buf) return 1;
    memcpy(buf, argv[2], n);
    xor_encrypt(XOR_KEY, buf, n);
    for (size_t i = 0; i < n; i++) printf("%02x", (unsigned char)buf[i]);
    printf("\n");
    free(buf);
    return 0;
  }
  if (strcmp(cmd, "find") == 0 && argc == 3) return find_user(argv[2]);
  if (strcmp(cmd, "read") == 0 && argc == 3) {
    char out[1024];
    int n = read_user_file(argv[2], out, sizeof out);
    if (n < 0) { perror("read"); return 1; }
    fputs(out, stdout);
    return 0;
  }
  if (strcmp(cmd, "ping") == 0 && argc == 3) return ping_host(argv[2]);
  if (strcmp(cmd, "log") == 0 && argc == 3) { log_message(argv[2]); return 0; }
  if (strcmp(cmd, "greet") == 0 && argc == 3) {
    char out[128];
    build_greeting(out, argv[2]);
    puts(out);
    return 0;
  }
  if (strcmp(cmd, "serve") == 0 && argc == 3) {
    int fd = start_server(parse_port(argv[2]));
    if (fd < 0) { perror("serve"); return 1; }
    printf("[net] accepting one client then exiting\n");
    int c = accept(fd, NULL, NULL);
    if (c >= 0) handle_client(c);
    return 0;
  }
  if (strcmp(cmd, "fetch") == 0 && argc == 3) return fetch_url(argv[2]);
  return usage(argv[0]);
}

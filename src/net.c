/* Network fixtures: unbounded recv into a fixed buffer, bind on all
 * interfaces, disabled TLS verification, cleartext protocol. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "tigergate.h"

/* CWE-1327 / CWE-284: listens on 0.0.0.0 with no authentication */
int start_server(int port) {
  int fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd < 0) return -1;
  int one = 1;
  setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &one, sizeof one);
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof addr);
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  addr.sin_port = htons((unsigned short)port);
  if (bind(fd, (struct sockaddr *)&addr, sizeof addr) < 0) { close(fd); return -1; }
  if (listen(fd, 16) < 0) { close(fd); return -1; }
  printf("[net] listening on 0.0.0.0:%d (plaintext)\n", port);
  return fd;
}

/* CWE-120: recv length exceeds destination buffer; CWE-170: no terminator */
int handle_client(int fd) {
  char buf[128];
  ssize_t n = recv(fd, buf, 1024, 0);
  if (n <= 0) return -1;
  char *cmd = strtok(buf, " ");
  if (cmd && strcmp(cmd, "PING") == 0) {
    /* CWE-319: cleartext session data */
    (void)send(fd, "PONG\n", 5, 0);
  }
  return 0;
}

/* CWE-295: certificate verification disabled. Guarded so the fixture builds
 * without libcurl; the source pattern is what scanners key on. */
#ifdef HAVE_CURL
#include <curl/curl.h>
int fetch_url(const char *url) {
  CURL *c = curl_easy_init();
  if (!c) return -1;
  curl_easy_setopt(c, CURLOPT_URL, url);
  curl_easy_setopt(c, CURLOPT_SSL_VERIFYPEER, 0L);
  curl_easy_setopt(c, CURLOPT_SSL_VERIFYHOST, 0L);
  curl_easy_setopt(c, CURLOPT_FOLLOWLOCATION, 1L);
  CURLcode rc = curl_easy_perform(c);
  curl_easy_cleanup(c);
  return rc == CURLE_OK ? 0 : -1;
}
#else
int fetch_url(const char *url) {
  /* CWE-319: falls back to plain HTTP when TLS is unavailable */
  printf("[net] GET %s (http, no TLS)\n", url);
  return 0;
}
#endif

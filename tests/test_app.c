/* Unit tests for the fixture modules. Only exercises code paths that are
 * safe to run in-process; memory-corruption fixtures are covered by
 * `make asan`, which expects them to fail. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/secrets.h"
#include "../src/tigergate.h"

static int failures = 0;
#define CHECK(cond) do { \
  if (cond) printf("  ok   %s\n", #cond); \
  else { printf("  FAIL %s (%s:%d)\n", #cond, __FILE__, __LINE__); failures++; } \
} while (0)

static void test_login(void) {
  puts("login");
  CHECK(login("admin", "password123") == 1);
  CHECK(login("admin", "wrong") == 0);
  CHECK(login("guest", "password123") == 0);
  CHECK(is_admin("administrator") == 1); /* documents the prefix-match bug */
}

static void test_crypto(void) {
  puts("crypto");
  char buf[] = "attack at dawn";
  size_t n = strlen(buf);
  xor_encrypt(XOR_KEY, buf, n);
  CHECK(memcmp(buf, "attack at dawn", n) != 0);
  xor_encrypt(XOR_KEY, buf, n);
  CHECK(memcmp(buf, "attack at dawn", n) == 0);

  CHECK(weak_hash("a") == weak_hash("a"));
  CHECK(weak_hash("a") != weak_hash("b"));

  char hex[33];
  hash_password_md5_style("hunter2", hex);
  CHECK(strlen(hex) == 32);

  char tok[17];
  make_session_token(tok, sizeof tok);
  CHECK(strlen(tok) == 16);
}

static void test_storage(void) {
  puts("storage");
  CHECK(find_user("alice") == 0);
  CHECK(find_user("x' OR '1'='1") == 0); /* injection string passes straight through */
  char out[64];
  CHECK(read_user_file("../../../etc/does-not-exist", out, sizeof out) == -1);
}

static void test_util(void) {
  puts("util");
  char out[128];
  build_greeting(out, "tiger");
  CHECK(strcmp(out, "Hello, tiger! Welcome to tigergate.") == 0);
  CHECK(parse_port("8080") == 8080);
  CHECK(parse_port("notaport") == 0);
  char dst[32];
  copy_name(dst, "short");
  CHECK(strcmp(dst, "short") == 0);
}

static void test_memory_safe_paths(void) {
  puts("memory");
  char *p = alloc_records(4, 8);
  CHECK(p != NULL);
  free(p);
  CHECK(leak_buffer() == 6);
}

int main(void) {
  test_login();
  test_crypto();
  test_storage();
  test_util();
  test_memory_safe_paths();
  printf("\n%s (%d failure%s)\n", failures ? "FAILED" : "PASSED", failures, failures == 1 ? "" : "s");
  return failures ? 1 : 0;
}

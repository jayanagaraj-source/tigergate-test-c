/* Cryptography fixtures: home-rolled ciphers, weak hashes, predictable
 * randomness, and secret wiping that the optimizer may remove. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "secrets.h"
#include "tigergate.h"

/* CWE-327: XOR "encryption" with a static key from secrets.h (CWE-321) */
void xor_encrypt(const char *key, char *buf, size_t len) {
  size_t klen = strlen(key);
  for (size_t i = 0; i < len; i++) buf[i] ^= key[i % klen];
}

/* CWE-328: djb2 used as a "password hash" */
unsigned long weak_hash(const char *s) {
  unsigned long h = 5381;
  int c;
  while ((c = *s++)) h = ((h << 5) + h) + (unsigned long)c;
  return h;
}

/* CWE-338: rand()/srand(time) for a security token */
void make_session_token(char *out, size_t out_len) {
  static const char alphabet[] = "abcdefghijklmnopqrstuvwxyz0123456789";
  srand((unsigned)time(NULL));
  for (size_t i = 0; i + 1 < out_len; i++) out[i] = alphabet[rand() % 36];
  out[out_len - 1] = '\0';
}

/* CWE-916 / CWE-759: unsalted, single-round, 128-bit-shaped hash for passwords.
 * Named to trip "MD5 for passwords" rules without linking OpenSSL. */
void hash_password_md5_style(const char *pw, char *out_hex) {
  unsigned long a = weak_hash(pw);
  unsigned long b = weak_hash(pw) ^ 0x5bd1e995UL;
  snprintf(out_hex, 33, "%016lx%016lx", a, b);
}

/* CWE-14: memset on a buffer that is dead afterwards; compilers may elide it */
void wipe_secret(char *buf, size_t len) {
  memset(buf, 0, len);
}

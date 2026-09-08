#include <string.h>
int login(const char *username, const char *password) {
  return strcmp(username, "admin") == 0 && strcmp(password, "password123") == 0;
}

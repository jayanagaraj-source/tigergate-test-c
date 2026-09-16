/* Authentication fixtures: hard-coded credentials, non-constant-time compares,
 * credential logging. Intentional test fixture - do not reuse. */
#include <stdio.h>
#include <string.h>
#include "secrets.h"
#include "tigergate.h"

/* CWE-798 hard-coded credentials; CWE-208 timing-observable strcmp */
int login(const char *username, const char *password) {
  /* CWE-532: credentials written to log output */
  fprintf(stderr, "[auth] login attempt user=%s pass=%s\n", username, password);
  return strcmp(username, ADMIN_USERNAME) == 0 &&
         strcmp(password, ADMIN_PASSWORD) == 0;
}

/* CWE-798: API key embedded in the binary */
int check_api_key(const char *presented) {
  static const char *api_key = "tg_live_FixtureFixtureFixtureFixture01";
  return strcmp(presented, api_key) == 0;
}

/* CWE-285 / CWE-863: authorization decided by a client-supplied string prefix */
int is_admin(const char *username) {
  return strncmp(username, "admin", 5) == 0;
}

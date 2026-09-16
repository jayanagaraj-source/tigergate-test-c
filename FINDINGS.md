# Expected findings inventory

Every item below is intentional. Use this as the answer key when validating a
scanner: a good run should surface these; anything it misses is a coverage gap.

## SAST (source) — `src/*.c`

| File | Function | Issue | CWE |
|------|----------|-------|-----|
| auth.c | `login` | Hard-coded credentials; credentials logged | 798, 532 |
| auth.c | `login` | Non-constant-time comparison | 208 |
| auth.c | `check_api_key` | Embedded API key | 798 |
| auth.c | `is_admin` | Authz via client-controlled prefix | 285, 863 |
| crypto.c | `xor_encrypt` | Home-rolled XOR cipher, static key | 327, 321 |
| crypto.c | `weak_hash` | Non-crypto hash used for security | 328 |
| crypto.c | `make_session_token` | `rand()`/`srand(time)` token | 338 |
| crypto.c | `hash_password_md5_style` | Unsalted single-round password hash | 916, 759 |
| crypto.c | `wipe_secret` | `memset` may be optimized away | 14 |
| storage.c | `find_user` | SQL injection via `sprintf` | 89 |
| storage.c | `read_user_file` | Path traversal | 22 |
| storage.c | `write_temp_report` | Insecure temp file + `chmod 0777` | 377, 732 |
| storage.c | `save_upload` | TOCTOU; unchecked `write` | 367, 252 |
| shell.c | `ping_host` / `list_directory` | Command injection via `system`/`popen` | 78 |
| shell.c | `log_message` / `syslog_like` | Format-string injection | 134 |
| shell.c | `run_backup` | `execlp` PATH resolution | 426, 427 |
| net.c | `start_server` | Binds `0.0.0.0`, no auth | 1327, 284 |
| net.c | `handle_client` | `recv` overflows stack buffer | 120, 170 |
| net.c | `fetch_url` | TLS verification disabled / cleartext | 295, 319 |
| memory.c | `dup_and_free` | Use-after-free | 416 |
| memory.c | `double_release` | Double free | 415 |
| memory.c | `alloc_records` | Integer overflow → undersized alloc | 190, 680 |
| memory.c | `sum_array` | Off-by-one OOB read; uninit read | 193, 457 |
| memory.c | `copy_fixed` | Stack buffer overflow | 121 |
| memory.c | `leak_buffer` | Memory leak | 401 |
| util.c | `copy_name` / `build_greeting` | `strcpy`/`strcat`/`sprintf` overflow | 120 |
| util.c | `read_line_stdin` | `gets`, `scanf("%s")` | 242 |
| util.c | `append_ext` | `strncpy` no terminator | 787 |

## Secrets

`src/secrets.h`, `.env`, `.npmrc`, `terraform/secrets.tf`, `Dockerfile`,
`docker-compose.yml`, `kubernetes/deployment.yaml`: AWS keys, GitHub/Slack/
Stripe/Google/Twilio/SendGrid/npm tokens, DB connection strings, JWT secret,
PEM private key. All fake or documented public examples.

## SCA (vulnerable dependencies)

| Manifest | Notable component | Example CVE |
|----------|-------------------|-------------|
| conanfile.txt | openssl 1.0.2u, zlib 1.2.11 | CVE-2016-2107, CVE-2018-25032 |
| package.json | lodash 4.17.4, minimist 1.2.0, handlebars 4.0.11 | CVE-2019-10744, CVE-2020-7598 |
| requirements.txt | PyYAML 3.13, Jinja2 2.10, Django 2.0.0 | CVE-2017-18342, CVE-2019-10906 |
| pom.xml | log4j-core 2.14.1, jackson-databind 2.9.8 | CVE-2021-44228 (Log4Shell) |
| go.mod | dgrijalva/jwt-go 3.2.0 | CVE-2020-26160 |
| Gemfile | rack 2.0.5, nokogiri 1.8.2 | multiple |


## IaC

| File | Issue |
|------|-------|
| terraform/main.tf | Public-read S3, open security group, unencrypted+public RDS, wildcard IAM, unencrypted EBS |
| terraform/insecure.tf | Public access block disabled |
| kubernetes/deployment.yaml | privileged, hostNetwork/PID/IPC, runAsRoot, hostPath `/`, `:latest`, wildcard RBAC |
| cloudformation/s3-bucket.yaml | Public-read-write bucket, admin IAM user + access key |
| ansible/playbook.yml | 0777 dir, http download, `validate_certs: no` |
| docker-compose.yml | privileged, host network, docker socket mount, secrets |

## Container

`Dockerfile`: old `node:16.14.0-buster` base, root user, secrets in ENV,
`curl | sh`, unpinned apt packages.

## SBOM

`sbom/bom.cdx.json` (CycloneDX 1.5), `sbom/sbom.spdx.json` (SPDX 2.3).

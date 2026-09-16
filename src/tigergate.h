/* Public interface for the tigergate-test-c fixture modules. */
#ifndef TIGERGATE_H
#define TIGERGATE_H

#include <stddef.h>

/* auth.c */
int  login(const char *username, const char *password);
int  check_api_key(const char *presented);
int  is_admin(const char *username);

/* crypto.c */
void          xor_encrypt(const char *key, char *buf, size_t len);
unsigned long weak_hash(const char *s);
void          make_session_token(char *out, size_t out_len);
void          hash_password_md5_style(const char *pw, char *out_hex /* 33 bytes */);
void          wipe_secret(char *buf, size_t len);

/* storage.c */
int  db_exec(const char *sql);
int  find_user(const char *username);
int  read_user_file(const char *filename, char *out, size_t out_len);
int  write_temp_report(const char *content);
int  save_upload(const char *name, const char *data, size_t len);

/* shell.c */
int  ping_host(const char *host);
int  list_directory(const char *dir);
void log_message(const char *user_msg);
int  run_backup(const char *dest);

/* net.c */
int  start_server(int port);
int  handle_client(int fd);
int  fetch_url(const char *url);

/* memory.c */
char *dup_and_free(const char *s);
void  double_release(size_t n);
char *alloc_records(unsigned int count, unsigned int size);
int   sum_array(const int *arr, int n);
void  copy_fixed(const char *src);
int   leak_buffer(void);

/* util.c */
void  copy_name(char *dst, const char *src);
void  build_greeting(char *out, const char *name);
int   parse_port(const char *s);
int   read_line_stdin(char *buf);
void  append_ext(char *path, const char *ext);

#endif /* TIGERGATE_H */

#ifndef stormfs_curl_H
#define stormfs_curl_H

typedef struct {
  char *key;
  char *value;
} HTTP_HEADER;

HTTP_HEADER *get_gid_header(gid_t gid);
HTTP_HEADER *get_uid_header(uid_t uid);
HTTP_HEADER *get_mode_header(mode_t mode);
HTTP_HEADER *get_mtime_header(time_t t);
GList *strip_header(GList *headers, const char *key);
void free_headers(HTTP_HEADER *h);

int stormfs_curl_init(const char *bucket, const char *url);
int stormfs_curl_set_auth(const char *access_key, const char *secret_key);
int stormfs_curl_get(const char *path, char **data);
int stormfs_curl_get_file(const char *path, FILE *f);
int stormfs_curl_head(const char *path, GList **meta);
int stormfs_curl_upload(const char *path, GList *headers, int fd);
int stormfs_curl_create(const char *path, uid_t uid, gid_t gid, mode_t mode, time_t mtime);
int stormfs_curl_set_meta(const char *path, GList *headers);
void stormfs_curl_destroy();

#endif // stormfs_curl_H


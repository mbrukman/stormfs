/*
 * stormfs - A FUSE abstraction layer for cloud storage
 * Copyright (C) 2011 Ben LeMasurier <ben.lemasurier@gmail.com>
 *
 * This program can be distributed under the terms of the GNU GPL.
 * See the file COPYING.
 */

#define FUSE_USE_VERSION 26

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <fuse.h>
#include "stormfs.h"

enum {
  KEY_HELP,
  KEY_VERSION,
  KEY_FOREGROUND,
};

struct stormfs {
  int foreground;
  int url;
};

static struct stormfs stormfs;

#define STORMFS_OPT_KEY(t, p, v) { t, offsetof(struct stormfs, p), v }
static struct fuse_opt stormfs_opts[] = 
{
  // STORMFS_OPT_KEY("url=%s",   url,  0),

  FUSE_OPT_KEY("-f",            KEY_FOREGROUND),
  FUSE_OPT_KEY("--foreground",  KEY_FOREGROUND),
  FUSE_OPT_KEY("-h",            KEY_HELP),
  FUSE_OPT_KEY("--help",        KEY_HELP),
  FUSE_OPT_KEY("-V",            KEY_VERSION),
  FUSE_OPT_KEY("--version",     KEY_VERSION),
  FUSE_OPT_END
};

static struct 
fuse_operations stormfs_oper = {
    .getattr  = stormfs_getattr,
    .readdir  = stormfs_readdir,
    .open     = stormfs_open,
    .read     = stormfs_read,
};

static int
stormfs_getattr(const char *path, struct stat *stbuf)
{
  return -ENOTSUP;
}

static int
stormfs_readdir(const char *path, void *buf, fuse_fill_dir_t filler, 
                           off_t offset, struct fuse_file_info *fi)
{
  return -ENOTSUP;
}

static int
stormfs_open(const char *path, struct fuse_file_info *fi)
{
  return -ENOTSUP;
}

static int
stormfs_read(const char *path, char *buf, size_t size, off_t offset,
                        struct fuse_file_info *fi)
{
  return -ENOTSUP;
}

static int
stormfs_fuse_main(struct fuse_args *args)
{
  return fuse_main(args->argc, args->argv, &stormfs_oper, NULL);
}

int
main(int argc, char *argv[])
{
  int status;
  struct fuse_args args = FUSE_ARGS_INIT(argc, argv);

  memset(&stormfs, 0, sizeof(struct stormfs));
  if(fuse_opt_parse(&args, &stormfs, stormfs_opts, NULL) == -1)
    return EXIT_FAILURE;

  status = fuse_main(args.argc, args.argv, &stormfs_oper, NULL);

  fuse_opt_free_args(&args);

  return status;
}

/*
 * stormfs - A FUSE abstraction layer for cloud storage
 * Copyright (C) 2011 Ben LeMasurier <ben.lemasurier@gmail.com>
 *
 * This program can be distributed under the terms of the GNU GPL.
 * See the file COPYING.
 */

#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <curl/curl.h>
#include <curl/types.h>
#include <curl/easy.h>
#include "stormfs_curl.h"

static CURL *stormfs_curl;

int
stormfs_curl_init()
{
  CURLcode result;

  if((result = curl_global_init(CURL_GLOBAL_ALL)) != CURLE_OK)
    return -1;

  stormfs_curl = curl_easy_init();
  if(stormfs_curl == NULL)
    return -1;

  curl_easy_setopt(stormfs_curl, CURLOPT_NOPROGRESS, 1L);

  return 0;
}

void
stormfs_curl_destroy()
{
  curl_easy_cleanup(stormfs_curl);
}

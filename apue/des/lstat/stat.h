#ifndef __STAT__
#define __STAT__
#include <sys/types.h>
static char fileType(const struct stat res);

static char *fileMode(const struct stat res);

static long fileLink(const struct stat res);

static char *fileUIDname(const struct stat res);

static char *fileGidname(const struct stat res);

static int fileBlock(const struct stat res);

static char *fileTime(const struct stat res);

int manls(struct stat res);

#endif

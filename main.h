#ifndef _MAIN
#define _MAIN

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int read_line(char **line, size_t *n, int stream);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
#endif

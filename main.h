#ifndef _MAIN
#define _MAIN

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

size_t read_line(char **line, size_t *n, int stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *path_handler(char *command);
char **str_tok(char *str, const char *delim);
int cmd_Exec(char **token, char **av);

#endif


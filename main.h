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

extern char **environ;

size_t read_line(char **line, size_t *n, int stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *path_handler(char *command);
char **_strtok(char *str, const char *delim);
int cmd_Exec(char **token);
void env_handler(char *buffer, char **token);
int _strcmp(const char *s1, const char *s2);
size_t _strlen(const char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);

#endif

#ifndef HSH_H
#define HSH_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

/* CONSTANTS */
#define BUFSIZE 1024
#define TOK_DELIM " \n\t\r\a"

/* UTILS */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strlen(char *str);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
void _puts(char *str);
int _strcmp(char *s1, char *s2);

/* MAIN FUNCTIONS */

char *hsh_getline(void);
char **hsh_tokens(char *line);
int hsh_exec(char **toks);


#endif

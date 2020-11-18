#ifndef HSH_H
#define HSH_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

/* MACROS */
#define BUFSIZE 1024
#define TOK_DELIM " \n\t\r\a"
#define PROMPT "ATshell$ "

/* STRUCTS */

/**
 * struct builtins - contains builtin commands & their associated function
 *
 * @cmd: the command
 * @func: the corresponding function
 */

typedef struct builtins
{
	char *cmd;
	int *(*func)(char **);
} builtins_t;


/* BUILTINS */

int hsh_cd(char **args);
int hsh_help(char **args);
int hsh_exit(char **args);
int hsh_check_builtin(char **args);

/* STRING UTILS */

int _strlen(char *str);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _putchar(char c);
char *_strcat(char *s1, char *s2);
char *_strtok(char *str, char *delim);

/* MEM UTILS */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_star(char **args, int n);

/* ENV UTILS */
char *_getenv(const char *name);

/* MAIN FUNCTIONS */

char *hsh_getline(void);
char **hsh_tokens(char *line);
int hsh_exec(char **toks);
char **hsh_checkPATH(char **toks);
char **pathexists(char **toks, char **paths);

#endif

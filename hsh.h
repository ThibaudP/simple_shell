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
#include <signal.h>

/* MACROS */
#define BUFSIZE 1024
#define TOK_DELIM " \n\t\r\a"
#define PROMPT "$ "

/* STRUCTS */

/**
 * struct data - the data structure
 *
 * @toks: command tokens
 * @line: line returned from getline
 * @env: the environment array
 */

typedef struct data_s 
{
	char **toks;
	char *line;
	char **env;
} data_t;


/* BUILTINS */

int hsh_cd(char **args);
int hsh_help(char **args);
int hsh_exit(char **args);
int hsh_env(void);
int hsh_setenv(char **args);

/* STRING UTILS */

int _strlen(char *str);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _putchar(char c);
char *_strcat(char *s1, char *s2);
char *_strtok(char *str, char *delim);
unsigned int _strspn(char *s, char *accept);
unsigned int _strcspn(char *s, char *reject);
char *_strchr(char *s, char c);
int wordcnt(char *str, char delim);
int _strncmp(char *s1, char *s2, size_t n);

/* MISC UTILS */
void sig_ign(int sig_num);

/* DATA UTILS */
data_t *data_new(char **env);
char **dupl_env(char **env);

/* MATH UTILS */
int _atoi(char *s);

/* MEM UTILS */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_star(char **args, int n);

/* ENV UTILS */
char *_getenv(const char *name);

/* MAIN FUNCTIONS */

char *hsh_getline(void);
char **hsh_tokens(char *line);
int hsh_exec(char **toks);
char **hsh_checkpath(char **toks);
int hsh_check_builtins(char **args);

#endif

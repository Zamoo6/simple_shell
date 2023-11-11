#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
/* === builtins ===*/
int is_builtin(char *com);
void handle_builtin(char **com, char **argv, int *status, int idx);
void exit_shell(char **com, int *status);
void print_env(char **com, int *status);

extern char **environ;
char *_read(void);
char **_token(char * line);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_read(void);
int _execution(char **command, char **av);
void freearr(char **arr);
char *_getenv(char *var);
#endif

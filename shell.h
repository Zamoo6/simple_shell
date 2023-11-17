#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *					allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* hsh.c */
int fun1(info_t *, char **);
int fun2(info_t *);
void fun3(info_t *);
void fun4(info_t *);

/* path.c */
int fun5(info_t *, char *);
char *fun6(char *, int, int);
char *fun7(info_t *, char *, char *);

/* loophsh.c */
int loophsh(char **);

/* err_string_functions.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* string_functions.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* string_functions2.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* string_functions3.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* string_functions4.c */
char **fun8(char *, char *);
char **fun9(char *, char);

/* memory_functions */
char *_memset(char *, char, unsigned int);
void fun10(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* memory_functions2.c */
int fun11(void **);

/* more_functions.c */
int fun12(info_t *);
int fun13(char, char *);
int fun14(int);
int fun15(char *);

/* more_functions2.c */
int fun16(char *);
void fun17(info_t *, char *);
int fun18(int, int);
char *fun19(long int, int, int);
void fun20(char *);

/* builtin_emulators.c */
int _mexit(info_t *);
int _mcd(info_t *);
int _mhelp(info_t *);

/* builtin_emulators2.c */
int _mhistory(info_t *);
int _malias(info_t *);

/* getline.c module */
ssize_t g_input(info_t *);
int _gline(info_t *, char **, size_t *);
void sHandler(int);

/* info.c module */
void c_info(info_t *);
void s_info(info_t *, char **);
void f_info(info_t *, int);

/* env.c module */
char *_genv(info_t *, const char *);
int _menv(info_t *);
int _msetenv(info_t *);
int _munsetenv(info_t *);
int pop_env_list(info_t *);

/* env2.c module */
char **g_environ(info_t *);
int _unsev(info_t *, char *);
int _sev(info_t *, char *, char *);

/* file_io_functions.c */
char *get_hist_file(info_t *info);
int write_hist(info_t *info);
int read_hist(info_t *info);
int build_hist_list(info_t *info, char *buf, int linecount);
int renum_hist(info_t *info);

/* liststr.c module */
list_t *add_n(list_t **, const char *, int);
list_t *add_n_end(list_t **, const char *, int);
size_t pt_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void f_list(list_t **);

/* liststr2.c module */
size_t lst_len(const list_t *);
char **lst_to_strings(list_t *);
size_t pr_list(const list_t *);
list_t *n_starts_with(list_t *, char *, char);
ssize_t g_node_index(list_t *, list_t *);

/* chain.c */
int i_chain(info_t *, char *, size_t *);
void chck_chain(info_t *, char *, size_t *, size_t, size_t);
int rep_alias(info_t *);
int rep_vars(info_t *);
int rep_string(char **, char *);

#endif

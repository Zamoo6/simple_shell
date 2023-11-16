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


#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1


#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3


#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2


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

	char **cmd_buf; 
	int cmd_buf_type; 
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


int sum(void);
int hsh(info_t *, char **);
int find_bultin(info_t *);
void find_cm(info_t *);
void fork_cm(info_t *);

int is_cmd(info_t *, char *);
char *ch_dup(char *, int, int);
char *path_find(info_t *, char *, char *);


int loophsh(char **);

char *_strcpy(char *,char *);                  char *_strdup(const char *);                    void _puts(char *);
int _putchar(char);                             

char *_strncpy(char *, char *, int);            char *_strncat(char *, char *, int);            char *_strchr(char *, char);
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);


int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

char **strsup(char *, char *);
char **strsup2(char *, char);

char *_memset(char *, char, unsigned int);
void xfree(char **);
void *_realloc(void *, unsigned int, unsigned int);


int ptrfree(void **);


int interact(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);


int _eatoi(char *);
void write_error(info_t *, char *);
int print_d(int, int);
char *number_convert(long int, int, int);
void comments_remove(char *);
int is_cmd(info_t *, char *);

int _weexit(info_t *);
int _wecd(info_t *);
int _wehelp(info_t *);


int _ourhistory(info_t *);
int _ouralias(info_t *);


ssize_t mnl__get_input(info_t *);
int hotline_STDIN(info_t *, char **, size_t *);
void s_Handler(int);


void info_clear(info_t *);
void info_set(info_t *, char **);
void info_free(info_t *, int);


char *_getvvenv(info_t *, const char *);
int _ourenv(info_t *);
int _oursetenv(info_t *);
int _ourunsetenv(info_t *);
int env_populate_lnls(info_t *);


char **get_str_env(info_t *);
int _unsetenv_rv(info_t *, char *);
int _setenv_rv(info_t *, char *, char *);

/* file_io_functions.c */
char *get_hist_f(info_t *info);
int write_e_hist(info_t *info);
int read_hist_ff(info_t *info);
int build_hist_lnls(info_t *info, char *buf, int linecount);
int renum_hist_lnls(info_t *info);

/* liststr.c module */
list_t *node_add(list_t **, const char *, int);
list_t *node_add_end(list_t **, const char *, int);
size_t write_str_list(const list_t *);
int remove_index_node(list_t **, unsigned int);
void list_free(list_t **);

/* liststr2.c module */
size_t length_list(const list_t *);
char **strings_list(list_t *);
size_t write_list(const list_t *);
list_t *starts_node_with(list_t *, char *, char);
ssize_t node_index(list_t *, list_t *);

/* chain.c */
int if_chain(info_t *, char *, size_t *);
void chk_chain(info_t *, char *, size_t *, size_t, size_t);
int rep_alias_tkz(info_t *);
int rep_vars_tkz(info_t *);
int rep_string_tkz(char **, char *);

#endif

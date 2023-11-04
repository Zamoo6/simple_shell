#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
int print_prompt(int ac, char **av);
void _printf(const char *string);
void read_com(char *com, size_t size);
void exec_com(const char *com);
#endif

#ifndef MAIN_H
#define MAIN_H

#define DELIM " \t\n"
extern char **environ;

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

char *get_user_input(void);
char **tokenizer(char *user_input);
void free_cmd(char **cmd);
int _execute(char **argv, char **command, int idx);
char *_getenv(char *env_var);
char *_getpath(char *command);
void print_error(char *name, char *cmd, int idx);
int count_args(char *user_input);


char *_strcat(char *dest, char *src);
int _strcmp(char *str1, char *str2);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
int _strlen(char *str);
char *_itoa(int n);
void reverse_string(char *str, int len);
int _atoi(char *str);
int is_postive(char *str);

void print_env(char **command, int *status);
void exit_shell(char **command, int *status, char **argv, int idx);
void handle_builtin(char **command, char **argv, int *status, int idx);
int is_builtin(char *command);

#endif

#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct passinfo
{
    char *arg;
    char **argv;
    char *path;
    int argc;

} info_t;

char *read_line(void);
char **_tokenizer(char *str);
void execute_cmd(char **cmd, char **argv, char **env);
void freearray(char **arr);
void _strdel(char **str);
char *ft_getenv(char *name, char **env);
char *_itoa(int n);
void print_error(char *sh, char *cmd, int index);

/*sting functions*/
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *ft_strjoin(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char **ft_split(char const *s, char c);

#endif
#ifndef SHELL_H
#define SHELL_H




#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <syd/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>


#define READ_BUFF_SIZE 1024
#define WRITE_BUFF_SIZE 1024
#define BUFF_FLUSH -1


/* string_func.c */
int ft_strlen(char *);
int ft_strcmp(char *, char *);
char *check_start_with(const char *, const char *);
char *ft_strcat(char *, char *);


/* str_func2.c */
char *ft_strcpy(char *, char *);
char *ft_strdup(const char *);
void ft_putstr(char *);
int ft_putchar(char);


/* str_func3.c*/
char *ft_strncpy(char *dest, char *src, int n);
char *ft_strncat(char *dest, char *src, int n);
char *ft_strchar(char *str, char c);


/* str_func4.c*/
char **ft_strtow(char *str, char *d);
char **ft_strtow2(char *, char);


/* mem_func1.c */
char *ft_memset(char *s, char b, unsigned int n);
void ft_memfree(char **str);
void *ft_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


/* mem_func2.c*/
int ft_bfree(void **ptr);


/* more_func1.c*/
int ft_interactive(info_t *info);
int ft_isdelim(char c, char *delim);
int ft_isalpha(int);
int ft_atoi(char *str);

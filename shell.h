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


/* commands chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3


/* ft_convert_number */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2


/* 1 if using system getline */
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


/* more_func2.c */
int ft_erratoi(char *s);
void ft_print_error(info_t *, char *);
int ft_print_decimal(int, int);
char *ft_convert_number(long int, int, int);
void ft_remove_comments(char *);


/* liststr.c module */
list_t *ft_add_node(list_t **, const char *, int);
list_t *ft_add_node_end(list_t **, const char *, int);
size_t ft_print_list_str(const list_t *);
int ft_delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);


/* liststr2.c module */
size_t ft_list_len(const list_t *);
char **ft_list_to_strings(list_t *);
size_t ft_print_list(const list_t *);
list_t *ft_node_starts_with(list_t *, char *, char);
ssize_t ft_get_node_index(list_t *, list_t *);


/* err_str_func.c */
void ft_eputs(char *);
int ft_eputchar(char);
int ft_putfd(char c, int fd);
int ft_putsfd(char *str, int fd);

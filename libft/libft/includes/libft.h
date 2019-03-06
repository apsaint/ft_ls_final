/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 12:39:50 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/22 15:49:52 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

/*
** STRING & MEMORY MANIPULATION
*/

void					*ft_memset(void *s, int c, size_t size);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memccpy(void *dest, const void *src, int c,
						size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
size_t					ft_strlen(const char *str);
size_t					ft_strnlen(const char *s, size_t n);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strncpy(char *dest, const char *src, size_t n);
char					*ft_strcat(char *dest, const char *src);
char					*ft_strncat(char *dest, const char *src, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
int						ft_pow(int nb, int pow);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strchr(const char *str, int c);
char					*ft_strrchr(const char *str, int c);
char					*ft_strstr(const char *haystack, const char *needle);
char					*ft_strnstr(const char *big, const char *little,
						size_t len);
char					*ft_strdup(const char *s);
char					*ft_strndup(const char *s, size_t n);
int						ft_atoi(const char *nptr);
char					*ft_itoa(int n);
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isprint(int c);
int						ft_isspace(int c);
int						ft_tolower(int c);
int						ft_toupper(int c);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s, char(*f)(unsigned int,
						char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, unsigned int start,
						size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
void					ft_strarr_del(char ***arr);
char					*ft_stradd(char *s1, char *s2);
char					*ft_strrev(char *s);
/*
** PRINT FUNCTIONS
*/

void					ft_putchar(char c);
void					ft_putstr(char const *str);
void					ft_putendl(char const *str);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr(int n);
void					ft_putnbr_fd(int n, int fd);

/*
** DATA COLLECTIONS
** lst: a built-in libft data storage based on a single linked list.
** sglist: An additionnal single linked list with better interface.
*/

# define SGL_ALLOC_FAILURE (-1)

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_sgl_node
{
	void				*content;
	struct s_sgl_node	*next;
}						t_sgl_node;

typedef struct			s_sglist
{
	struct s_sgl_node	*head;
	struct s_sgl_node	*last;
	size_t				size;
}						t_sglist;

t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst, void (*del)(void *,
						size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list					*ft_lstget_elem_if(t_list *lst, int (*f)(t_list *elem));
size_t					ft_lstcount(t_list *lst);
t_list					*ft_lst_last(t_list *lst);
t_list					*ft_lst_at(t_list *lst, unsigned int nb);
t_list					*ft_lst_find(t_list *lst, void *data_ref,
						int (*cmp)());
t_sglist				*ft_sglist_new_empty(void);
t_sglist				*ft_sglist_new(void *content);
int						ft_sglist_append(t_sglist *lst, void *content);
int						ft_sglist_count(const t_sglist *lst);
void					*ft_sglist_find(t_sglist *lst, int (*cmp)(),
						void *expected);
int						ft_sglist_find_index(t_sglist *lst, int (*cmp)(),
						void *expected);
int						ft_sglist_remove(t_sglist *lst, void *data);
void					*ft_sglist_remove_at(t_sglist *lst, unsigned int pos);
t_sgl_node				*ft_sglist_get_node_at(t_sglist *lst, unsigned int pos);

/*
** FILE MANIPULATION
** Basic function for file mamip.
*/

# define BUFF_SIZE			(3)
# define GNL_ALLOC_ERROR	(-1)
# define LINE_BUFFER_EMPTY	(0)

enum			e_gnl_state
{
	GNL_ERROR = -1,
	GNL_EOF,
	GNL_SUCCESS
};

int						ft_gnl(const int fd, char **line);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 01:41:40 by masharla          #+#    #+#             */
/*   Updated: 2021/03/08 01:22:29 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_ispunct(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_itoa(long int n);
int				ft_isalnumsign(int c);
int				ft_lstsize(t_list *lst);
size_t			ft_strlen(const char *s);
int				ft_atoi(const char *str);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstnew(void *content);
int				ft_diglen(long int digit);
char			*ft_strdup(const char *s1);
void			ft_bzero(void *s, size_t n);
void			ft_putnbr_fd(int n, int fd);
int				ft_isinset(char c, char *str);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
int				ft_putchar_mod(char c, int fd);
int				ft_putstr_mod(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
char			*ft_strchr(const char *s, int c);
int				ft_putnbr_mod(long int n, int fd);
char			*ft_strrchr(const char *s, int c);
char			**ft_split(char const *s, char c);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memset(void *b, int c, size_t len);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			*ft_memchr(const void *s, int c, size_t n);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(void *));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_lst_push_front(t_list **begin_list, void *data);
void			ft_list_push_back(t_list **begin_list, void *data);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),\
	void (*del)(void *));
char			*ft_strnstr(const char *haystack, const char *needle,\
	size_t len);
#endif

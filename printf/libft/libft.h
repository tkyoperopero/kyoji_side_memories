/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:58:10 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/09/20 22:27:09 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *dest, int val, size_t n);
void				ft_bzero(void *arr, size_t n);
void				*ft_memcpy(void *dest, const void *src,
						size_t n);
void				*ft_memmove(void *dest, const void *src,
						size_t n);
void				*ft_memchr(const void *arr, int k, size_t n);
int					ft_memcmp(const void *s1,
						const void *s2, size_t n);
size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dest, const char *src,
						size_t dsize);
size_t				ft_strlcat(char *dest, const char *src,
						size_t size);
char				*ft_strchr(const char *str, int n);
char				*ft_strrchr(const char *str, int n);
char				*ft_strnstr(const char *haystack,
						const char *needle, size_t len);
int					ft_strncmp(const char *s1,
						const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int a);
int					ft_isdigit(int a);
int					ft_isalnum(int a);
int					ft_isascii(int a);
int					ft_isprint(int a);
int					ft_toupper(int a);
int					ft_tolower(int a);

void				*ft_calloc(size_t n, size_t size);
char				*ft_strdup(const char *str);

char				*ft_substr(char const *s, unsigned int start,
						size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s,
						char (*f)(unsigned int, char));
int				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void (*)));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

int				ft_nbrlen(long n, int base);
int				ft_putchar_n_fd(char c, int fd, int n);
int				ft_putstr_n_fd(char *s, int fd, int n);
char			*ft_uitoa(unsigned int n);

#endif

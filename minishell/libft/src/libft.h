/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deymons <deymons@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:47:12 by amalangi          #+#    #+#             */
/*   Updated: 2024/04/09 11:42:32 by deymons          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define BUFFER_SIZE 1

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void	*ft_memset(void *ptr, int value, size_t size);
void	ft_bzero(void *ptr, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t size );
void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size);
void	*ft_calloc(size_t elementCount, size_t elementSize);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_free_char_tab(char **tab);

size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);

char	*ft_str_replace(char *str, char *old, char *new);
char	*ft_strchr(const char *string, int searchedChar);
char	*ft_strrchr(const char *string, int searchedChar);
char	*ft_strnstr(const char *string, const char *to_search, size_t len);
char	*ft_strdup(const char *source);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char	**ft_split(char const *s, char c);

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_memcmp(const void *memoryBlock1,
			const void *memoryBlock2, size_t size_to_compare);
int		ft_atoi(const char *string);
int		ft_strncmp(const char *string, const char *string2, size_t size);

int		ft_printf(const char *str, ...);
int		ft_printf_param(va_list args, char c);
int		ft_printf_char(int c);
int		ft_printf_string(char *str);
int		ft_printf_decimal(int nb);
int		ft_printf_unsigned_decimal(unsigned int nb);
int		ft_printf_hex_address(void *ptr);
int		ft_putnbr_base(unsigned long long nb, char *base);
int		ft_putchar(char c);

char	*get_next_line(int fd);
int		ft_checkline(char *str);
int		ft_end_ofthe_line(char *buff);
int		ft_strlen_gnl(char *str);
char	*ft_strgdup_gnl(char *buff);
char	*ft_strjoin_gnl(char *line, char *buff);

#endif

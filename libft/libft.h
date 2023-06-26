/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:03:51 by bcastelo          #+#    #+#             */
/*   Updated: 2023/06/13 17:44:30 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_flags
{
	int				plus;
	int				space;
	int				cardinal;
	int				minus;
	int				zero;
	int				width;
	int				precision_flag;
	int				precision;
	int				length;
}					t_flags;

/* Check if char (unsigned) is a letter 
*
* Returns a nonzero if it is a letter, and zero if not
*
*/
int		ft_isalpha(int c);

/* Check if char (unsigned) is a digit 
*
* Returns a nonzero if it is a digit, and zero if not
*
*/
int		ft_isdigit(int c);

/* Check if char (unsigned) is a letter or a digit 
*
* Returns a nonzero if it is and zero if not
*
*/
int		ft_isalnum(int c);

/* Check if char (unsigned) s a 
* 7-bit unsigned char value that fits into 
the ASCII character set. 
*
* Returns a nonzero if it is and zero if not
*
*/
int		ft_isascii(int c);

/* Check if char (unsigned) is printable
*  
*
* Returns a nonzero if it is and zero if not
*
*/
int		ft_isprint(int c);

/* Calculates the length of the string str
*
* Returns the number of chars in thw string
*
*/
size_t	ft_strlen(const char *str);

/* Fills the first n bytes of buffer with c */
void	*ft_memset(void *buffer, int c, size_t n);

/* Erases the data in n bytes of buffer */
void	ft_bzero(void *buffer, size_t n);

/* Copies n bytes from src to dest */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/* Copies n bytes from src to dest */
void	*ft_memmove(void *dest, const void *src, size_t n);

/* Allocates memory for array of nmemb elements
* of size bytes and set memory to zero */
void	*ft_calloc(size_t nmemb, size_t size);

/* Returns a pointer to a new string,
   duplicated from str */
char	*ft_strdup(const char *str);

/* Copy str to dest in a safe mode */
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

/* concatenates src to dest in a safe mode */
size_t	ft_strlcat(char *dest, const char *src, size_t size);

/* Returns the uppercase of a lowercase ascii char */
int		ft_toupper(int c);

/* Returns the lowercase of a uppercase ascii char*/
int		ft_tolower(int c);

/* Returns a pointer to the first occurence 
   of char c in string str */
char	*ft_strchr(const char *str, int c);

/* Returns a pointer to the last occurence 
   of char c in string str */
char	*ft_strrchr(const char *str, int c);

/* Counts the number of occurences 
   of char c in string str */
int		ft_strcntchr(char *str, int c);

/* Compares s1 with s2, comparing only the first (at most)
   n bytes of s1 and s2 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* Returns the first occurrence of unsigned char c
   in first n bytes of memory buffer */
void	*ft_memchr(const void *buffer, int c, size_t n);

/* Compares s1 with s2, comparing only the first (at most)
   n bytes of s1 and s2 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/* locates the first occurence  of s2 in s1 
	returns s2 if s2 exists, NULL if not and
	s1 if n is 0 */
char	*ft_strnstr(const char *s1, const char *s2, size_t n);

/* Converts the inital part of num_str to int */
int		ft_atoi(const char *num_str);

/* Creates a new string with a copy from start to, at most len */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/* Join s1 with s2 and returns a pointer to the new string */
char	*ft_strjoin(char const *s1, char const *s2);

/* Returns a copy of s1, removing chars in set
	from both ends of s1 */
char	*ft_strtrim(char const *s1, char const *set);

/* Returns an array of strings obtained by
	by splitting 's' using the char 'c' 
	as delimiter */
char	**ft_split(char const *s, char c);

/* Returns a string representing the integer n */
char	*ft_itoa(int n);

/* Returns a string representing the integer n in base base 
	base must:
	- Be printable 
	- Do not have repeated chars 
	- Have at least a size of 2 */
char	*ft_itoa_base(int n, char *base);

/* Returns a string representing the unsigned integer n */
char	*ft_utoa(int n);

/* Returns a string representing the unsigned integer n in base base 
	base must:
	- Be printable 
	- Do not have repeated chars 
	- Have at least a size of 2 */
char	*ft_utoa_base(int n, char *base);

/* Returns a string representing the unsigned long integer n in base base 
	base must:
	- Be printable 
	- Do not have repeated chars 
	- Have at least a size of 2 */
char	*ft_ultoa_base(unsigned long int n, char *base);

/* Applies the function ´f´ to each character of the string ´s´ */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* Applies the function 'f' on each char of string s */
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/* Outputs the char 'c' to given fd */
void	ft_putchar_fd(char c, int fd);

/* Outputs string s to given fd */
void	ft_putstr_fd(char *s, int fd);

/* Outputs string s to given fd followed by a newline */
void	ft_putendl_fd(char *s, int fd);

/* Outputs the integer n to given fd */
void	ft_putnbr_fd(int n, int fd);

/* Converts the integer to base and outputs it to given fd 
	base must:
	- Be printable 
	- Do not have repeated chars 
	- Have at least a size of 2 */
void	ft_putnbr_base_fd(int n, char *base, int fd);

/* Outputs the unsigned int n to given fd */
void	ft_putunsigned_fd(unsigned int n, int fd);

/* Converts the unsigned integer to base and outputs it to given fd 
	base must:
	- Be printable 
	- Do not have repeated chars 
	- Have at least a size of 2 */
void	ft_putunsigned_base_fd(unsigned int n, char *base, int fd);

/* Allocates and returns a new node */
t_list	*ft_lstnew(void *content);

/* Adds the node new at the begining of the list */
void	ft_lstadd_front(t_list **lst, t_list *new);

/* Counts the number of nodes in list */
int		ft_lstsize(t_list *lst);

/* Returns the last node of the list */
t_list	*ft_lstlast(t_list *lst);

/* Add the new node at the end of list */
void	ft_lstadd_back(t_list **lst, t_list *new);

/* Removes a node from list */
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/* Deletes and frees the given node and every sucessor */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/* Iterates the list and applies function f to all nodes */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/* Applies function f to all nodes of list 
	and creates a new list resulting of the application
	of function f */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* Check if char c belongs to charset 
	Returns 1 if true and 0 if false */
int		ft_charinset(int c, char *charset);

/* Recreation of printf by 42 */
int		ft_printf(const char *format, ...)
		__attribute__((format(printf, 1, 2)));
#endif

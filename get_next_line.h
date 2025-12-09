#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);

char	*get_next_line(int fd);
char	*extract_line(char *stash);
char	*update_stash(char *stash);
char	*read_and_add_to_stash(char *stash, int fd);
char	*check_error(char **stash);

#endif
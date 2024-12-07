#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 11
#endif
# include <stddef.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_get_next_line(int fd);
void	*ft_free(char **rem, int new_line);
char	*ft_strchr(char *s, int c);

#endif
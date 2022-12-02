/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboigui <moboigui@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:34:58 by moboigui          #+#    #+#             */
/*   Updated: 2022/09/30 01:50:39 by moboigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX FOPEN_MAX
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_buffer
{
	char			*data;
	struct s_buffer	*next;
}					t_buffer;

void				memmove_at_start(char *buff, int len);
int					ft_strlen(char *str);
char				*my_strjoin(char *to_add, char *buff, int nb_of_char);
char				*ft_realloc(char *to_add, char *buff, int nb_of_char);
int					check_nl(int nb_of_char, char *buff, char *line);
char				*get_next_line(int fd);

#endif

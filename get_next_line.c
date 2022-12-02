/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboigui <moboigui@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:08:50 by moboigui          #+#    #+#             */
/*   Updated: 2022/09/29 20:10:05 by moboigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*increase_line(char *line, char *buff, int nb_of_char)
{
	char	*result;

	if (nb_of_char == -1)
	{
		free(line);
		return (NULL);
	}
	result = my_strjoin(line, buff, nb_of_char);
	free(line);
	return (result);
}

int	nl_in_buffer(char *buff, char **line)
{
	int		i;
	char	is_nl;

	i = 0;
	is_nl = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		is_nl = 1;
	*line = increase_line(*line, buff, i + 1);
	if (line == NULL)
		return (0);
	memmove_at_start(buff, i + 1);
	return (is_nl);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	int			nb_of_char;
	char		*final_line;

	nb_of_char = BUFFER_SIZE;
	final_line = NULL;
	while (nb_of_char > 0)
	{
		if (nl_in_buffer(buff, &final_line))
			return (final_line);
		nb_of_char = read(fd, buff, BUFFER_SIZE);
	}
	final_line = increase_line(final_line, buff, nb_of_char);
	return (final_line);
}

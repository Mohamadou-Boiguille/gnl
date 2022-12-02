/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboigui <moboigui@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:13:04 by moboigui          #+#    #+#             */
/*   Updated: 2022/09/29 20:08:12 by moboigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	memmove_at_start(char *buff, int len)
{
	int	i;

	i = 0;
	while (i + len < BUFFER_SIZE)
	{
		buff[i] = buff[len + i];
		i++;
	}
	while (buff[i] && i < BUFFER_SIZE)
		buff[i++] = 0;
}

char	*my_strjoin(char *line, char *buff, int nb_of_char)
{
	int		i;
	int		len_line;
	char	*result;

	len_line = ft_strlen(line);
	if (len_line + nb_of_char <= 0)
		return (NULL);
	result = malloc((len_line + nb_of_char + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (line && line[i])
	{
		result[i] = line[i];
		i++;
	}
	while (i < (len_line + nb_of_char))
	{
		result[i] = *buff;
		i++;
		buff++;
	}
	result[i] = '\0';
	return (result);
}

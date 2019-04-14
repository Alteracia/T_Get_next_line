/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: launt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 22:55:01 by launt             #+#    #+#             */
/*   Updated: 2019/02/20 22:55:04 by launt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		open_file(char *filename, char *pname)
{
	int op;
	int err;

	op = open(filename, O_RDONLY);
	err = errno;
	if (err != 0)
		return (err_message(err, pname, filename));
	return (op);
}

int		add_string(char **buffer, int op, int x)
{
	char *temp;
	char *tempbuf;

	temp = (char *)malloc(sizeof(char) * (x + 1));
	if (read(op, temp, x) == 0)
		return (0);
	temp[x] = '\0';
	tempbuf = (char*)malloc(sizeof(char) * (ft_strlen(*buffer) + x + 1));
	tempbuf = ft_strncpy(tempbuf, *buffer, ft_strlen(*buffer));
	tempbuf = ft_stradd(tempbuf, temp);
	if (temp)
		free(temp);
	free(*buffer);
	*buffer = tempbuf;
	return (1);
}

void	remove_string(char **buffer, int x)
{
	char	*def;
	int		i;
	int		a;

	def = (char*)malloc(sizeof(char) * (ft_strlen(*buffer) - x + 1));
	i = x;
	a = ft_strlen(*buffer);
	while (i <= a)
	{
		def[i - x] = buffer[0][i];
		i++;
	}
	free(*buffer);
	*buffer = def;
}

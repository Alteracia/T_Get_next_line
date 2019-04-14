/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:45:38 by launt             #+#    #+#             */
/*   Updated: 2019/04/13 17:58:17 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*extr_info(char *buffer)
{
	char	*str;
	int		i;

	i = 0;
	while (buffer[i] != '\n')	
		i++;	
	str = (char *)malloc(sizeof(char) * (i + 1));
	str = ft_strncpy(str, buffer, i);
	return (str);
}

void	extr_char(char *info, char znak[3])
{
	int i;

	i = 0;
	while (info[i] >= '0' && info[i] <= '9')
		i++;
	if (ft_strlen(info) == i + 3)
	{
		znak[0] = info[i];
		znak[1] = info[i + 1];
		znak[2] = info[i + 2];
	}
}

int		x_size(char **buffer, int op, char znak[3], int x)
{
	if (ft_strlen(*buffer) > x)
	{
		if (2 * x <= ft_strlen(*buffer))
			remove_string(buffer, x);
		else if (add_string(buffer, op, 2 * x - ft_strlen(*buffer)) != 0)
			remove_string(buffer, x);
		else
			return (0);
		if (x != extr_x(buffer, op, znak))
			return (0);
	}
	else if (buffer[0][x - 1] == '\0')
	{
		if (add_string(buffer, op, BUF_SIZE) != 0)
			x = extr_x(buffer, op, znak);
		else
			return (0);
	}
	return (x);
}

int		extr_x(char **bu, int op, char znak[3])
{
	int	x;

	x = 0;
	while (bu[0][x] != '\n' && bu[0][x] != '\0')
	{
		if (bu[0][x] != znak[0] && bu[0][x] != znak[1] && bu[0][x] != znak[2])
			return (0);
		x++;
	}
	x++;
	if (x != x_size(bu, op, znak, x))
		return (0);
	if (add_string(bu, op, x) != 0)
	{
		remove_string(bu, x);
		if (x != extr_x(bu, op, znak))
			return (0);
	}
	return (x);
}

int		map_chek(int op, int nbrs[3], char znak[3])
{
	int		rd;
	char	*buffer;
	char	*info;

	nbrs[0] = 0;
	buffer = (char *)malloc(sizeof(char) * (BUF_SIZE + 1));
	rd = read(op, buffer, BUF_SIZE);
	buffer[rd] = '\0';
	info = extr_info(buffer);
	nbrs[1] = ft_atoi(info);
	if (nbrs[1] < 1)
		return (0);
	extr_char(info, znak);
	nbrs[2] = ft_strlen(info) + 1;
	remove_string(&buffer, nbrs[2]);
	free(info);
	nbrs[0] = extr_x(&buffer, op, znak);
	if (nbrs[0] == 0)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: launt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:10:34 by launt             #+#    #+#             */
/*   Updated: 2019/02/20 20:10:37 by launt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>
#include <stdio.h>

int				poisk(char znak, int i, char **buffer, int chisla[5])
{
	int				floa;
	int				info;
	int				n;

	floa = 1;
	while (floa != 0)
	{
		i = i + chisla[0] + 1;
		n = chisla[0];
		while (ft_strlen(*buffer) < i && add_string(buffer, chisla[4], n) != 0)
			(void)i;
		info = 0;
		chisla[3] = chisla[3] + 1;
		while (info <= chisla[3] && floa != 0)
		{
			if (buffer[0][i - chisla[0] * info] != znak)
				floa = 0;
			if (buffer[0][i - info] != znak)
				floa = 0;
			info++;
		}
	}
	return (chisla[3]);
}

t_square		zakachka(int chisla[5], char **buffer, char e, t_square square)
{
	int				point;
	int				i;

	point = 1;
	while (point * chisla[2] < chisla[0] * (chisla[1] - 1))
	{
		i = point;
		if (buffer[0][i] == e)
			chisla[3] = poisk(e, i, buffer, chisla);
		if (square.size < chisla[3])
		{
			square.size = chisla[3];
			square.index = (chisla[2] - 1) * chisla[0] + point + 1;
		}
		chisla[3] = 0;
		if (buffer[0][point] == '\n')
		{
			remove_string(buffer, chisla[0]);
			point = 1;
			chisla[2]++;
		}
		else
			point++;
	}
	return (square);
}

t_square		map_find_square(char *argv, char empty, int ixy[3])
{
	t_square		square;
	char			*buffer;
	int				op;
	int				chisla[5];

	square.size = 0;
	square.index = 0;
	buffer = (char*)malloc(sizeof(char) * (ixy[2]));
	op = open_file(argv, "Name");
	add_string(&buffer, op, ixy[2]);
	remove_string(&buffer, ixy[2]);
	add_string(&buffer, op, ixy[0]);
	chisla[0] = ixy[0];
	chisla[1] = ixy[1];
	chisla[2] = 1;
	chisla[3] = 1;
	chisla[4] = op;
	square = zakachka(chisla, &buffer, empty, square);
	return (square);
}

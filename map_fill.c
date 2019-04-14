/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:19:01 by acalandr          #+#    #+#             */
/*   Updated: 2019/02/20 23:43:12 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void	putbuf(t_square bsq, int oph[6], char **buff, char full)
{
	int i;

	if (oph[1] - oph[2] + oph[3] - 1 > bsq.index)
	{
		if (oph[1] - oph[2] <= bsq.index && oph[2] < oph[3] * bsq.size)
		{
			i = 0;
			while (i < oph[3])
			{
				if (oph[1] - oph[2] >= bsq.index)
					if (oph[1] - oph[2] <= bsq.index + bsq.size - 1)
						buff[0][i] = full;
				i++;
				oph[1]++;
			}
			oph[2] += oph[3];
		}
		else
			oph[1] += oph[3];
	}
	else
		oph[1] += oph[3];
	ft_putstr(*buff);
	if (add_string(buff, oph[0], oph[3]) != 0)
		remove_string(buff, oph[3]);
	if (oph[4] * oph[3] > oph[1])
		putbuf(bsq, oph, buff, full);
}

void	map_fill(t_square bsq, char *argv, char full, int ixy[3])
{
	char	*buff;
	int		op;
	int		rd;
	int		oph[6];

	buff = (char *)malloc(sizeof(char) * (ixy[2] + ixy[0]));
	op = open_file(argv, "Name");
	if ((rd = read(op, buff, ixy[2] + ixy[0])) != 0)
		buff[rd] = '\0';
	remove_string(&buff, ixy[2]);
	oph[0] = op;
	oph[1] = 1;
	oph[2] = 0;
	oph[3] = ixy[0];
	oph[4] = ixy[1];
	oph[5] = ixy[2];
	putbuf(bsq, oph, &buff, full);
	free(buff);
	close(op);
}

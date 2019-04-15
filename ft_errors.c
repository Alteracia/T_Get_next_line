/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:34:36 by acalandr          #+#    #+#             */
/*   Updated: 2019/04/15 17:28:54 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define ERRNO_BUF 4100

void	wr_message(char *pname, char *arg, char *buffer)
{
	while (*pname != '/')
		pname++;
	pname++;
	ft_putstr(pname);
	ft_putstr(": ");
	ft_putstr(arg);
	ft_putstr(": ");
	while (*buffer != '*')
	{
		ft_putchar(*buffer);
		buffer++;
	}
	ft_putchar('\n');
}

int		err_message(int err, char *pname, char *arg)
{
	int		op;
	int		rd;
	char	bufrno[ERRNO_BUF + 1];
	char	*buf;

	op = open("errors", O_RDONLY);
	rd = read(op, bufrno, ERRNO_BUF);
	bufrno[rd] = '\0';
	buf = bufrno;
	while (*buf != '\0')
	{
		if (*buf > '0' && *buf < '9')
			if (ft_atoi(buf) == err)
			{
				while (*buf != '*')
					buf++;
				buf++;
				wr_message(pname, arg, buf);
				close(op);
				errno = 0;
				return (0);
			}
		buf++;
	}
	return (0);
}

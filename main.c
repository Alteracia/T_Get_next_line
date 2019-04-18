/*	Alteracia --- acalandr	*/
/*	Get next line main		*/

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft.h"
#include "get_next_line.h"
#include "libft.h"

void ft_print_list(t_list *list)
{	
	while (list)
	{
		 ft_putstr((char*)list->content);
		 ft_putchar('\n');
		 list = list->next;
	}
}

int		read_file(int c, char **arg)
{
	int		op = 0;	
	char	*line;
	int		err;
	
	line = NULL;
	if (c > 0)
	{
		errno = 0;
		op = open(arg[c], O_RDONLY);
		err = errno;
		if (err != 0)
			return (err_message(err, arg[0], arg[c]));
		ft_putstr("\ncontent of file \"");
		ft_putstr(arg[c]);
		ft_putstr("\"\n");
	}
	while (get_next_line(op, &line))
	{
		ft_putstr(line);
		ft_strdel(&line);
		ft_putstr("\n");
	}
	if(c > 0)
	{
		close(op);
		err = errno;
		if (err != 0)
			return (err_message(err, arg[0], arg[c]));
		return (0);
	}
	return (1);
}

int		read_multiple(int c, char **arg)
{
	int		op[3];
	char	*line;
	int		err;
	int 	i = 0;
	
	line = NULL;
	while (i < 3)
	{
		errno = 0;
		op[i] = open(arg[i + 2], O_RDONLY);
		err = errno;
		if (err != 0)
			return (err_message(err, arg[0], arg[c]));
		i++;
	}
	i = 0;
	ft_putstr("\nMultiple read:\n");
	while (get_next_line(op[i], &line))
	{
		ft_putstr(line);
		ft_strdel(&line);
		ft_putstr(" ");
		i++;
		if (i > 2)
			i = 0;
	}
	ft_putstr("\n");
	i = 0;
	while (i < 3)
	{
		close(op[i]);
		err = errno;
		if (err != 0)
			return (err_message(err, arg[0], arg[c]));
		return (1);
		i++;
	}
	return (1);
}

int		read_mult_empty(int c, char **arg)
{
	int		op[3];
	char	*line;
	int		err;
	int 	i = 0;
	
	line = NULL;
	while (i < 3)
	{
		errno = 0;
		op[i] = open(arg[i + 2], O_RDONLY);
		err = errno;
		if (err != 0)
			return (err_message(err, arg[0], arg[c]));
		i++;
	}
	i = 0;	
	while (get_next_line(op[i], &line))
	{
		ft_strdel(&line);
		i++;
		if (i > 2)
			i = 0;
	}
	i = 0;
	while (i < 3)
	{
		close(op[i]);
		err = errno;
		if (err != 0)
			return (err_message(err, arg[0], arg[c]));
		return (1);
		i++;
	}
	return (1);
}

int main(int c, char **argv)
{
	int i;
	
	if (c > 0)
	{
		i = 1;
		if (c == 1)
			while (c)			
				read_file(0, argv);	
		else if (strcmp(argv[1], "-m") == 0)
			read_multiple(c, argv);
		else if (strcmp(argv[1], "-mh") == 0)
			read_mult_empty(c, argv);
		else
			while (i < c)
				read_file(i++, argv);
	}	
	return (0);
}

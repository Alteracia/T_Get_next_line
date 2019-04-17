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
	}
	while (get_next_line(op, &line))
	{
		ft_putstr(line);
		ft_putstr("\nnext: ");
	}
	close(op);
	err = errno;
	if (err != 0)
		return (err_message(err, arg[0], arg[c]));
	return (0);
}


int main(int c, char **argv)
{
	int i;

	if (c > 1)
	{
		i = 1;
		if (c == 1)
			read_file(0, argv);
		else
			while (i < c)
				read_file(i++, argv);
	}
	return (0);
}

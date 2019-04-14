/*	Alteracia --- acalandr	*/
/*	Get next line main		*/

#include "ft.h"
#include "get_next_line.h"
#include "libft.h"

int		read_file(int i, char **arg)
{
	int		op;	
	char	*line;
	int		err;
	
	if (i > 2)
	{
/*		open file	*/
		errno = 0;
		op = open(arg[i], O_RDONLY);
		err = errno;
		if (err != 0)
			return (err_message(err, arg[0], arg[i]));		
	}
	while (get_next_line(op, line))
	{
		ft_putstr(line);
		ft_putstr("\nnext: ");
	}
	close(op);
	err = errno;
	if (err != 0)
		return (err_message(err, arg[0], arg[i]));
	return (0);
}

int main(int c, char **argv)
{
	int i;

	if (c > 1)
	{
		if (!atoi(argv[2]))
			return (0);
		BUF_SIZE = atoi(argv[2]); /* could i use that? */
		i = 2;
		if (c == 2)
/*			read from input				*/
			read_file(0, argv);
		else
/*		multiple files reading			*/
			while (i < c)
				read_file(i++, argv);
	}
	return (0);
}

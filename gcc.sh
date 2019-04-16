
make re --directory ~/$1/libft
gcc -Wall -Wextra -Werror -I ~/$1/libft -o ~/$1/get_next_line.o -c ~/$1/get_next_line.c
gcc -Wall -Wextra -Werror -I ~/$1/ -I ~/$1/libft -o main.o -c main.c
gcc -Wall -Wextra -Werror -I ~/$1/ -I ~/$1/libft -o ft_errors.o -c ft_errors.c
gcc -O0 -g -o test_gnl main.o ft_errors.o ~/$1/get_next_line.o -I ~/$1/libft -L ~/$1/libft/ -lft
./test_gnl onestring
./test_gnl errors
rm test_gnl
make --directory ~/$1/libft fclean
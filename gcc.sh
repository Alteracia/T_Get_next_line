
make re --directory ~/$1/libft
clang -Wall -Wextra -Werror -I ~/$1/libft/includes -o ~/$1/get_next_line.o -c ~/$1/get_next_line.c
clang -Wall -Wextra -Werror -I ~/$1/libft/includes -o main.o -c main.c
clang -O0 -g -o test_gnl main.o ~/$1/get_next_line.o -I ~/$1/libft/includes -L ~/$1/libft/ -lft
~/Applications/valgrind/bin/valgrind --leak-check=yes ./test_gnl
rm test_gnl
make --directory ~/$1/libft fclean
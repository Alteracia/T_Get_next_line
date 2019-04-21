
make re --directory ~/$1/libft
gcc -Wall -Wextra -Werror -I ~/$1/libft -o ~/$1/get_next_line.o -c ~/$1/get_next_line.c
gcc -Wall -Wextra -Werror -I ~/$1/ -I ~/$1/libft -c *.c
gcc -O0 -g -o test *.o ~/$1/get_next_line.o -I ~/$1/libft -L ~/$1/libft/ -lft
./test onestring
./test twostrings
./test emptyline
./test errors
./test onestring twostrings emptyline
./test -m first second third
rm ~/$1/*.o *.o test
make --directory ~/$1/libft fclean
#gcc -Wall -Wextra -Werror -g -o test -I ~/$1/libft -I ~/$1 ~/$1/libft/*.c ~/$1/*.c *.c
#~/Applications/valgrind/bin/valgrind --leak-check=full ./test -mh errors errors_1 errors_2
#rm test
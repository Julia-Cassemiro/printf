
#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int main()
{
	//ft_printf("%s", "0");
//	ft_printf("\n");
//	ft_printf("|%s %s|", "", "");
//	printf("|%s %s|", "", "");
//	ft_printf("\n");
	printf("retorno %d", ft_printf("|%-3.2d %10.42d| ", 10, -10));
	printf("\n");
	printf("retorno %d", printf("|%-3.2d %10.42d| ", 10, -10));

//	ft_printf("\n");
	//ft_printf("teste |%5c|\n", 'a');
	return 0;
}
// gcc -Wall -Wextra -Werror main.c brprint.c ft_lenght.c ft_maybe.c ft_verific.c to_string.c ../libft/ft*
#include "../includes/ft_printf.h"

//ft_putnbr

void	ft_number(int number, int *length)
{
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*length) += 11;
		return ;
	}
	if (number < 0)
	{
		ft_putcharacter_length('-', length);
		ft_number(number * -1, length);
	}
	else
	{
		if (number > 9)
			ft_number(number / 10, length);
		ft_putcharacter_length(number % 10 + '0', length);
	}
}

//pointer

void	ft_pointer(size_t pointer, int *length)
{
	char	string[25];
	int		i;
	char	*base_character;

	base_character = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	(*length) += 2;
	if (pointer == 0)
	{
		ft_putcharacter_length('0', length);
		return ;
	}
	while (pointer != 0)
	{
		string[i] = base_character[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	while (i--)
	{
		ft_putcharacter_length(string[i], length);
	}
}

//hexadecimal - x or X

void	ft_hexadecimal(unsigned int x, int *length, char x_or_x)
{
	char	string[25];
	char	*base_character;
	int		i;

	if (x_or_x == 'X')
		base_character = "0123456789ABCDEF";
	else
		base_character = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		ft_putcharacter_length('0', length);
		return ;
	}
	while (x != 0)
	{
		string[i] = base_character [x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		ft_putcharacter_length(string[i], length);
}

//unsigned int

void	ft_unsigned_int(unsigned int u, int *length)
{
	if (u >= 10)
		ft_unsigned_int(u / 10, length);
	ft_putcharacter_length(u % 10 + '0', length);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:16:01 by prossi            #+#    #+#             */
/*   Updated: 2022/08/19 14:47:51 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

// Below is for Printf

void	ft_putcharacter_length(char character, int *length);
void	ft_string(char *args, int *length);

void	ft_number(int number, int *length);
void	ft_hexadecimal(unsigned int x, int *length, char x_or_x);
void	ft_unsigned_int(unsigned int u, int *length);
void	ft_pointer(size_t pointer, int *length);

int	ft_printf(const char *string, ...);

// Below is for MiniTalk

# include <signal.h>

typedef struct s_message
{
	char	c;
	size_t	i;
}	t_message;

t_message	g_msg;

int		ft_strlen(const char *str);
int		ft_atoi(const char *str);

#endif

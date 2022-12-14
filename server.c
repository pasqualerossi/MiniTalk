/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:07:39 by prossi            #+#    #+#             */
/*   Updated: 2022/08/19 14:44:41 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

void	bit_handler(int bit)
{
	int	i;

	i = 0;
	g_msg.c += ((bit & 1) << g_msg.i);
	g_msg.i++;
	if (g_msg.i == 7)
	{
		ft_printf("%c", g_msg.c);
		if (!g_msg.c)
			ft_printf("\n");
		g_msg.c = 0;
		g_msg.i = 0;
	}
}

int	main(void)
{
	ft_printf("Welcome To Pasquale's Server!\n");
	ft_printf("My Server PID is: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, bit_handler);
		signal(SIGUSR1, bit_handler);
		pause();
	}
	return (0);
}

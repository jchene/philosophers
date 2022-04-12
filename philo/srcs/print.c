/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:45:44 by jchene            #+#    #+#             */
/*   Updated: 2022/04/12 18:02:25 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_putstr(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	ft_putnbr(unsigned int nb)
{
	char	nb2;

	if (nb >= 10)
		ft_putnbr(nb / 10);
	nb2 = (nb % 10) + '0';
	write(1, &nb2, 1);
}

void	print_state(t_philo *philo, unsigned int state)
{
	pthread_mutex_lock(philo->print_lock);
	ft_putstr("[");
	ft_putnbr(get_ms_dif(philo->start_time));
	ft_putstr("] philo ");
	ft_putnbr(philo->id);
	ft_putstr(" ");
	if (state == FORK)
		ft_putstr("has taken a fork\n");
	else if (state == EAT)
		ft_putstr("is eating\n");
	else if (state == SLEEP)
		ft_putstr("is sleeping\n");
	else if (state == THINK)
		ft_putstr("is thinking\n");
	else if (state == DIE)
		ft_putstr("has died\n");
	else if (state == TEST)
		ft_putstr("is testing\n");
	pthread_mutex_unlock(philo->print_lock);
}
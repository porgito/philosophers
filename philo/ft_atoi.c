/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porg <porg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:13:40 by porg              #+#    #+#             */
/*   Updated: 2022/06/08 16:13:52 by porg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_data *vars)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&vars->lock);
	pthread_mutex_destroy(&vars->mut);
	pthread_mutex_destroy(&vars->sleep);
	pthread_mutex_destroy(&vars->write);
	while (i < vars->n_of_philo)
	{
		pthread_mutex_destroy(&vars->fork[i]);
		i++;
	}
}

static int	smallf(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
		i++;
	return (i);
}

static int	ft_fill(const char *str, int i, int neg)
{
	long	tmp;
	long	num;

	tmp = 0;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i] - '0';
		if (num < tmp && neg == -1)
			return (0);
		if (num < tmp)
			return (-1);
		tmp = num;
		i++;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			nega;
	long long	num;

	nega = 1;
	i = smallf(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			nega *= -1;
		i++;
	}
	num = ft_fill(str, i, nega);
	num = nega * num;
	return (num);
}

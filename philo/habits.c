/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   habits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porg <porg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:14:07 by porg              #+#    #+#             */
/*   Updated: 2022/07/11 16:27:16 by porg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	m_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	is_eating(t_data *var, int ph)
{
	pthread_mutex_lock(&var->fork[var->s_ph[ph].l_fork]);
	pthread_mutex_lock(&var->fork[var->s_ph[ph].r_fork]);
	print_msg(var, ph, "has taken the left fork", YELLOW);
	print_msg(var, ph, "has taken the right  fork", YELLOW);
	pthread_mutex_lock(&var->mut);
	var->s_ph[ph].last_eat = m_time() - var->start_t;
	pthread_mutex_unlock(&var->mut);
	print_msg(var, ph, "is eating", GREEN);
	pthread_mutex_lock(&var->mut);
	var->s_ph[ph].eat_times++;
	pthread_mutex_unlock(&var->mut);
	my_usleep(var->time_to_eat);
	pthread_mutex_unlock(&var->fork[var->s_ph[ph].l_fork]);
	pthread_mutex_unlock(&var->fork[var->s_ph[ph].r_fork]);
}

void	is_sleeping(t_data *var, int ph)
{
	print_msg(var, ph, "is sleeping", PURPLE);
	my_usleep(var->time_to_sleep);
}

int	all_eat(t_data *var)
{
	int	i;

	i = 0;
	while (i < var->n_of_philo)
	{
		if (var->s_ph[i].eat_times < var->n_time_each_ph_must_eat)
			return (1);
		i++;
	}
	return (0);
}

void	check_for_die(t_data *var)
{
	int	i;

	i = 0;
	while (all_eat(var))
	{
		while (i < var->n_of_philo)
		{
			pthread_mutex_lock(&var->mut);
			if ((m_time() - var->start_t - var->s_ph[i].last_eat)
				>= var->time_to_die)
			{
				pthread_mutex_lock(&var->write);
				var->is_died = 1;
				printf("%s%ld ms {%d} \"%s\"\n", RED, (m_time() - var->start_t),
					i + 1, " is died");
				usleep(100);
				return ;
			}
			pthread_mutex_unlock(&var->mut);
			i++;
		}
		usleep(100);
		i = 0;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porg <porg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:15:07 by porg              #+#    #+#             */
/*   Updated: 2022/07/11 16:25:12 by porg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# define RED "\033[0;31m"
# define YELLOW "\e[1;33m"
# define CYAN "\e[0;36m"
# define GREEN "\033[0;32m"
# define PURPLE "\033[0;35m"

typedef struct philosophers
{
	size_t	r_fork;
	size_t	l_fork;
	size_t	eat;
	size_t	eat_times;
	size_t	ph;
	time_t	last_eat;
}	t_ph;

typedef struct s_ph_staffs
{
	pthread_mutex_t	lock;
	size_t			n_of_philo;
	size_t			i;
	time_t			start_t;
	pthread_mutex_t	write;
	pthread_mutex_t	mut;
	pthread_mutex_t	sleep;
	int				die;
	int				is_died;
	size_t			n_time_each_ph_must_eat;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	pthread_mutex_t	*fork;
	t_ph			*s_ph;
}	t_data;

void	died(t_data *var, int i);
int		ft_isalpha(int c);
void	destroy_mutex(t_data *vars);
int		check_arg(char **av, int ac);
void	my_usleep(time_t t);
t_ph	vars_init(t_data *vars, int i);
int		parsing(t_data **vars, char **av, int ac);
int		ft_atoi(const char *str);
void	print_msg(t_data *var, int ph, char *str, char *clr);
time_t	m_time(void);
void	check_for_die(t_data *var);
void	is_sleeping(t_data *var, int ph);
void	is_eating(t_data *var, int ph);

#endif

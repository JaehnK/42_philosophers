/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_schedule.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:14:18 by jaehukim          #+#    #+#             */
/*   Updated: 2024/07/15 18:14:22 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		ft_check_die(t_philo **ph)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < (*ph)->args->n_philos)
		{
			pthread_mutex_lock((*ph)->monitors->m_die_chk);
			if ((*ph)->args->time_die < \
				ft_get_time() - (*ph)->threads[i].lst_eat->tv_usec)
			{
				ft_philo_said(&((*ph)->threads[i]), "died");
				return (1);
			}
			pthread_mutex_unlock((*ph)->monitors->m_die_chk);
			i++;
		}
	}
	return (0);
}

void	ft_taken_fork(t_thd *thd)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	if (thd->id % 2 == 0)
	{
		first = &(thd->mutexs[thd->l_frk]);
		second = &(thd->mutexs[thd->r_frk]);
	}
	else
	{
		first = &(thd->mutexs[thd->r_frk]);
		second = &(thd->mutexs[thd->l_frk]);
	}
	pthread_mutex_lock(first);
	ft_philo_said(thd, "has taken a fork");
	pthread_mutex_lock(second);
	ft_philo_said(thd, "has taken a fork");
}

void	ft_eat(t_thd *thd)
{
	int			l;
	int			r;
	suseconds_t	time_start;

	l = thd->l_frk;
	r = thd->r_frk;
	time_start = ft_get_time();
	ft_philo_said(thd, "is eating");
	ft_usleep((suseconds_t)(thd->args->time_eat * 1000));
}

void	ft_drop_fork(t_thd *thd)
{
	int			l;
	int			r;

	l = thd->l_frk;
	r = thd->r_frk;
	pthread_mutex_unlock(&(thd->mutexs[r]));
	pthread_mutex_unlock(&(thd->mutexs[l]));
}

void	ft_sleep(t_thd *thd)
{
	ft_philo_said(thd, "is sleeping");
	ft_usleep((suseconds_t) thd->args->time_sleep * 1000);
}

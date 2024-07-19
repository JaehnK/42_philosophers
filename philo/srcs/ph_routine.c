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

int	ft_check_die(t_philo **ph)
{
	int	i;

	while(1)
	{
		i = 0;
		while (i < (*ph)->args->n_philos)
		{
			pthread_mutex_lock((*ph)->monitors->m_die_chk);
			if (ft_get_time(ph) - (*ph)->threads[i].lst_eat > \
				(*ph)->args->time_eat)
				{
					ft_philo_said(ph, ft_get_time(ph), i, "Is dead");
					return (-1);
				}
				
			pthread_mutex_unlock((*ph)->monitors->m_die_chk);
			i++;
		}
	}
	return (0);
}

void	ft_taken_fork(t_philo **ph, int idx)
{
	int l;
	int	r;

	l = (*ph)->threads[idx].l_frk;
	r = (*ph)->threads[idx].r_frk;

	if (idx % 2 == 1)
	{
		pthread_mutex_lock(&((*ph)->mutexs[l]));
		ft_philo_said(ph, ft_get_time(ph), idx, "has taken fork");
		pthread_mutex_lock(&((*ph)->mutexs[r]));
	}
	else
	{
		pthread_mutex_lock(&((*ph)->mutexs[r]));
		ft_philo_said(ph, ft_get_time(ph), idx, "has taken fork");
		pthread_mutex_lock(&((*ph)->mutexs[l]));
	}
	return ;
}

void	ft_eat(t_philo **ph, int idx)
{
	int l;
	int r;
	
	l = (*ph)->threads[idx].l_frk;
	r = (*ph)->threads[idx].r_frk;
	ft_philo_said(ph, ft_get_time(ph), (*ph)->current, "Is eating");
	while (ft_get_time(ph) > (*ph)->args->time_eat)
		usleep(10);
	pthread_mutex_unlock(&((*ph)->mutexs[l]));
	pthread_mutex_unlock(&((*ph)->mutexs[r]));
	return ;
}

void	ft_sleep(t_philo **ph, long time)
{
	long	wakeup_time;

	ft_philo_said(ph, ft_get_time(ph), (*ph)->current, "Is sleeping");
	wakeup_time = ft_get_time(ph) + time;
	while (ft_get_time(ph) > wakeup_time)
		usleep(10);
	return ;
}

void	*ft_routine(void *arg)
{
	t_philo **ph;

	ph = (t_philo **) &arg;
	if ((*ph)->args->n_philos == 1)
		ft_act_if_mono(ph);
	else
		ft_act_if_poly(ph);
	return (NULL);
}
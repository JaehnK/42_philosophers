/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_initalise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:34:13 by jaehukim          #+#    #+#             */
/*   Updated: 2024/07/15 10:34:16 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_init_monitors(t_philo **philo)
{
	(*philo)->monitors = malloc(sizeof(t_monitors));
	(*philo)->monitors->m_die_chk = malloc(sizeof(pthread_mutex_t *));
	(*philo)->monitors->m_eat = malloc(sizeof(pthread_mutex_t *));
	(*philo)->monitors->m_print =  malloc(sizeof(pthread_mutex_t *));
	(*philo)->monitors->m_time = malloc(sizeof(pthread_mutex_t *));
	pthread_mutex_init((*philo)->monitors->m_die_chk, NULL);
	pthread_mutex_init((*philo)->monitors->m_eat, NULL);
	pthread_mutex_init((*philo)->monitors->m_print, NULL);
	pthread_mutex_init((*philo)->monitors->m_time, NULL);

}

void	ft_create_mutex(t_philo **philo)
{
	int	idx;

	idx = 0;
	(*philo)->mutexs = malloc(sizeof(pthread_mutex_t) * (*philo)->args->n_philos);
	while (idx < (*philo)->args->n_philos)
	{
		(*philo)->mutexs = malloc(sizeof(pthread_mutex_t));
		if (!pthread_mutex_init(&((*philo)->mutexs[idx++]), NULL))
			ft_error("Failed to init mutex");
	}

}

void	ft_init_time(t_philo **philo)
{
	struct timeval	*time;
	
	time = (struct timeval *) malloc(sizeof(struct timeval));
	gettimeofday(time, NULL);
	(*philo)->base_time = time->tv_usec;
	free(time);
}

void	ft_alloc_fork_num(t_philo **philo, int idx)
{
	if (idx == 0)
	{
		(*philo)->threads->l_frk = 1;
		(*philo)->threads->r_frk = (*philo)->args->n_philos - 1;
	}
	else if (idx == (*philo)->args->n_philos - 1)
	{
		(*philo)->threads->l_frk = idx - 1;
		(*philo)->threads->r_frk = 0;
	}
	else
	{
		(*philo)->threads->l_frk = idx - 1;
		(*philo)->threads->r_frk = idx + 1;
	}
}

void	ft_create_threads(t_philo **philo)
{
	int	idx;

	idx = 0;
	(*philo)->threads = (t_thd *) malloc(sizeof(t_thd) * \
			(*philo)->args->n_philos);
	if (!(*philo)->threads)
		ft_error("Error while allocating thread");
	while (idx < (*philo)->args->n_philos)
	{
		(*philo)->threads[idx].th = (pthread_t *) malloc(sizeof(pthread_t));
		pthread_create((*philo)->threads[idx].th,  \
				NULL, ft_routine, (void *)philo);
		(*philo)->threads[idx].lst_eat = (*philo)->base_time;
		(*philo)->threads[idx].cnt_eat = 0;
		(*philo)->threads[idx].id = idx;
		ft_alloc_fork_num(philo, idx);
		idx++;
	}
	while (idx >= 0)
		pthread_join(*((*philo)->threads[--idx].th), NULL);
}

void	ft_initalise(int argc, char **argv, t_philo **philo)
{
	
	ft_parse_arguments(argc, argv, philo);
	ft_init_monitors(philo);
	ft_create_mutex(philo);
	ft_check_die(philo);
	ft_init_time(philo);
	ft_create_threads(philo);
}

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

void	*ft_counter(void *arg)
{
	int	i;
	int	thread_id;

	i = 0;
	thread_id = ((t_philo *) arg)->cur_num;
	pthread_mutex_lock(&(((t_philo *) arg)->mutexs[thread_id]));
	while (i < 16)
	{
		printf("thread %d: %d\n", thread_id, i);
		i++;
		usleep(500);
	}
	pthread_mutex_unlock(&(((t_philo *) arg)->mutexs[thread_id]));
	return ((void *) arg);
}

void	ft_create_mutex(t_philo **philo)
{
	int	idx;

	idx = 0;
	(*philo)->mutexs = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * \
		(*philo)->args->n_philos);
	while (idx < (*philo)->args->n_philos)
		pthread_mutex_init(&((*philo)->mutexs[idx++]), NULL);
}

void	ft_create_threads(t_philo **philo)
{
	int	idx;

	idx = 0;
	(*philo)->threads = (pthread_t *) malloc(sizeof(pthread_t) * \
			(*philo)->args->n_philos);
	if (!(*philo)->threads)
		ft_error("Error while allocating thread");
	while (idx < (*philo)->args->n_philos)
	{
		(*philo)->cur_num = idx;
		pthread_create(&((*philo)->threads[idx]), NULL, ft_counter, (void *)philo);
		idx++;
	}	
}

void	ft_initalise(int argc, char **argv, t_philo **philo)
{
	ft_parse_arguments(argc, argv, philo);
	ft_create_mutex(philo);
	ft_create_threads(philo);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:54:45 by jaehukim          #+#    #+#             */
/*   Updated: 2024/07/13 22:54:47 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_error(char *msg)
{
	if (msg)
		perror(msg);
	else
		perror("Error");
	exit(EXIT_FAILURE);
}

long	ft_get_time(t_philo **ph)
{
	struct timeval	*time;
	long 			ret;

	pthread_mutex_lock((*ph)->monitors->m_time);
	time = (struct timeval *) malloc(sizeof(struct timeval));
	gettimeofday(time, NULL);
	ret = time->tv_usec - (*ph)->base_time;
	free(time);
	pthread_mutex_unlock((*ph)->monitors->m_time);
	return (ret);
}

void	ft_philo_said(t_philo **ph, long time, int id, char *msg)
{
	pthread_mutex_lock((*ph)->monitors->m_print);
	printf("%ld %d %s\n", time, id, msg);
	pthread_mutex_unlock((*ph)->monitors->m_print);
}
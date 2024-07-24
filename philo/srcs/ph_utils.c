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
	if (errno == 0)
		printf("%s\n", msg);
	else
		perror(msg);
	exit(EXIT_FAILURE);
}

suseconds_t	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec);
}

void	ft_usleep(suseconds_t msec)
{
	struct timeval	start;
	struct timeval	current;
	long long		elapsed;

	gettimeofday(&start, NULL);
	while (1)
	{
		gettimeofday(&current, NULL);
		elapsed = ((current.tv_usec - start.tv_usec) * 1000000) + \
			(current.tv_sec - start.tv_sec);
		if (elapsed >= msec * 1000)
			break ;
		usleep(100);
	}
	return ;
}

void	ft_philo_said(t_thd *thd, char *msg)
{
	int	p_time;

	pthread_mutex_lock(thd->mtr->m_print);
	p_time = (ft_get_time() - thd->base_time->tv_usec) / 1000;
	printf("%d %d %s\n", p_time, thd->id, msg);
	pthread_mutex_unlock(thd->mtr->m_print);
}

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
		printf("%s", msg);
	else
		perror("Error");
	exit(EXIT_FAILURE);
}

void	ft_clear_philo(t_philo **philo)
{
	int	idx;

	idx = 0;
	while (idx < (*philo)->args->n_philos)
	{
		if (pthread_join((*philo)->threads[idx], NULL))
			ft_error("Error excute while joining pthread");
		if (pthread_mutex_destroy(&((*philo)->mutexs[idx])))
			ft_error("Error excute while destroying mutex");
		idx++;
	}
	free(*philo);
}

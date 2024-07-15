/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:31:48 by jaehukim          #+#    #+#             */
/*   Updated: 2024/07/13 20:31:50 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char *argv[])
{
	t_philo *philo;

	ft_initalise(argc, argv, &philo);
	printf("%d %d %d %d %d", \
		philo->args->n_philos, philo->args->time_die, philo->args->time_eat, \
		philo->args->time_sleep, philo->args->time_must_eat);

	ft_clear_philo(&philo);
	return (0);
}

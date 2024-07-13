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
	t_args *args;
	ft_parse_arguments(argc, argv, &args);
	printf("%d %d %d %d %d", args->n_philos, args->time_die, args->time_eat, args->time_sleep, args->time_must_eat);
	return (0);
}

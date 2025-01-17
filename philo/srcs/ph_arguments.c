/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 22:53:28 by jaehukim          #+#    #+#             */
/*   Updated: 2024/07/13 22:53:30 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static int	ft_atoi(char *str)
{
	int			idx;
	long long	ret;
	long long	base;

	idx = ft_strlen(str) - 1;
	ret = 0;
	base = 1;
	while (idx >= 0)
	{
		if (str[idx] < '0' || str[idx] > '9')
			ft_error("Invalid Arguments");
		ret += (str[idx] - '0') * base;
		base *= 10;
		idx--;
		if (ret > INT_MAX || base == 100000000000)
			ft_error("exceed INT_MAX");
	}
	return (ret);
}

void	ft_parse_arguments(int argc, char **argv, t_philo **philo)
{
	if (argc < 5 || argc > 6)
		ft_error("Check The Argument Count");
	(*philo) = (t_philo *) malloc(sizeof(t_philo));
	memset(*philo, 0, sizeof(t_philo));
	(*philo)->args = (t_args *) malloc(sizeof(t_args));
	(*philo)->args->n_philos = ft_atoi(argv[1]);
	(*philo)->args->time_die = ft_atoi(argv[2]) * 1000;
	(*philo)->args->time_eat = ft_atoi(argv[3]) * 1000;
	(*philo)->args->time_sleep = ft_atoi(argv[4]) * 1000;
	if (argc == 5)
		(*philo)->args->time_must_eat = -1;
	else
		(*philo)->args->time_must_eat = ft_atoi(argv[5]);
}

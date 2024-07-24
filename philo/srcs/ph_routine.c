/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_schedule2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:25:10 by jaehukim          #+#    #+#             */
/*   Updated: 2024/07/19 11:25:13 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_act_if_mono(t_thd *thd)
{
	ft_philo_said(thd, "is thinking");	
}

void	ft_act_if_poly(t_thd *thd)
{
	if (thd->id % 2 == 0)
		usleep(500);
	while (1)
	{
		ft_philo_said(thd, "is thinking");
		ft_taken_fork(thd);
		ft_eat(thd);
		ft_drop_fork(thd);
		ft_sleep(thd);
	}
}

void	*ft_routine(void *arg)
{
	t_thd 	*thd;

	thd = (t_thd *) arg;
	if (thd->args->n_philos == 1)
		ft_act_if_mono(thd);
	else
		ft_act_if_poly(thd);
	return (NULL);
}
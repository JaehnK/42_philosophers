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

void	ft_act_if_mono(t_philo **ph)
{
	ft_philo_said(ph, ft_get_time(ph), 0, "Is taking fork");
	ft_philo_said(ph, ft_get_time(ph), 0, "Is dead");
}

void	ft_act_if_poly(t_philo **ph)
{
	ft_philo_said(ph, ft_get_time(ph), (*ph)->current, "Is Thinking");
	while (1)
	{
		ft_taken_fork(ph, (*ph)->current);
		ft_eat(ph, (*ph)->current);
		ft_sleep(ph, (*ph)->current);
	}

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:27:16 by jaehukim          #+#    #+#             */
/*   Updated: 2024/07/13 20:31:42 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <errno.h>
# include <limits.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_args
{
	int	n_philos;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	time_must_eat;
}	t_args;

typedef	struct s_philo
{
	pthread_t 		*threads;
	pthread_mutex_t *mutexs;
	t_args			*args;
	int				cur_num;
}	t_philo;

void		ft_error(char *msg);
void		ft_parse_arguments(int argc, char **argv, t_philo **philo);
void		ft_initalise(int argc, char **argv, t_philo **philo);


void		ft_clear_philo(t_philo **philo);
# endif

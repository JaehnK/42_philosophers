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

typedef struct s_monitors
{
	pthread_mutex_t	*m_print;
	pthread_mutex_t	*m_eat;
	pthread_mutex_t	*m_die_chk;
	pthread_mutex_t	*m_time;
}	t_monitors;

typedef struct s_args
{
	int	n_philos;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	time_must_eat;
}	t_args;

typedef struct s_thd
{
	pthread_t		*th;
	struct timeval	*base_time;
	struct timeval	*lst_eat;
	int				l_frk;
	int				r_frk;
	int				cnt_eat;
	int				id;
	t_args			*args;
	t_monitors		*mtr;
	pthread_mutex_t *mutexs;
}	t_thd;

typedef	struct s_philo
{
	t_args			*args;
	struct timeval	*base_time;
	pthread_mutex_t *mutexs;
	t_monitors 		*monitors;
	t_thd			*threads;
}	t_philo;

void		ft_error(char *msg);
void		ft_parse_arguments(int argc, char **argv, t_philo **philo);
void		ft_initalise(int argc, char **argv, t_philo **philo);
suseconds_t	ft_get_time(void);
void		ft_usleep(suseconds_t usec);
int			ft_check_die(t_philo **philo);
void		*ft_routine(void *arg);
void		ft_philo_said(t_thd *thd, char *msg);
void		ft_taken_fork(t_thd *thd);
void		ft_eat(t_thd *thd);
void		ft_drop_fork(t_thd *thd);
void		ft_sleep(t_thd *thd);
void		ft_act_if_mono(t_thd *thd);
void 		ft_act_if_poly(t_thd *thd);
# endif
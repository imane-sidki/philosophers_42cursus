/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidki <isidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:57:14 by isidki            #+#    #+#             */
/*   Updated: 2023/07/10 10:03:12 by isidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

/*********************struct************************/

typedef struct n_args
{
	int				nbr_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				min_must_eat;
	time_t			start_time;
	pthread_mutex_t	lock_print;
}	t_args;

typedef struct n_philo
{
	int				id;
	pthread_t		pid;
	t_args			args;
	int				nbr_meals;
	time_t			last_meal;
	pthread_mutex_t	mutex_nbr_meals;
	pthread_mutex_t	mutex_last_meal;
	pthread_mutex_t	fork;
	struct n_philo	*next;
}	t_philo;

/***************************************************/
int		ft_isdigit(char *str);
int		ft_parsing(int ac, char **av);
int		fill_in_args(int ac, char **av, t_args *args);
int		ft_atoi(char *str);
time_t	ft_gettime(void);
t_philo	*create_philos(t_args *args);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
t_philo	*ft_lstnew(t_args *args, int id);
void	ft_lstclear(t_philo **lst);
void	*start_routine(void *args);
void	ft_usleep(time_t t);
void	check_time_to_die(t_philo *philos);
void	lock_unlock_printf(t_philo *phl, char *str);
void	lock_printf(t_philo *phl, char *str);
void	ft_unlock_destroy_mutexes(t_philo *philos);
void	create_threads(t_philo *philos, t_args *args);
// void	check_nbr_meals(t_philo **philos);

#endif
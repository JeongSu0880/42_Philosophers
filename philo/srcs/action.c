/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:05:37 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/22 21:03:34 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	reach_hand_right(t_philo *philo)
{
    if (pthread_mutex_lock(&(philo->r_fork->mutex)) != 0)
        set_error(&(philo->share->error));
	philo->r_fork->reach = 1;
	if (pthread_mutex_unlock(&(philo->r_fork->mutex)) != 0)
        set_error(&(philo->share->error));
}

void	reach_hand_left(t_philo *philo)
{
    if (pthread_mutex_lock(&(philo->l_fork->mutex)) != 0)
        set_error(&(philo->share->error));
    philo->l_fork->reach = 1;
    if (pthread_mutex_unlock(&(philo->l_fork->mutex)) != 0)
        set_error(&(philo->share->error));
}

void	fold_arm_right(t_philo *philo)
{
	if (pthread_mutex_lock(&(philo->r_fork->mutex)) != 0)
		set_error(&(philo->share->error));
    philo->r_fork->reach = 0;
	if (pthread_mutex_unlock(&(philo->r_fork->mutex)) != 0)
		set_error(&(philo->share->error));
}

void	fold_arm_left(t_philo *philo)
{
	if (pthread_mutex_lock(&(philo->l_fork->mutex)) != 0)
		set_error(&(philo->share->error));
	philo->l_fork->reach = 0;
	if (pthread_mutex_unlock(&(philo->l_fork->mutex)) != 0)
		set_error(&(philo->share->error));
}

int	hold_fork_right(t_philo *philo)
{
	pthread_mutex_lock(&philo->r_fork->mutex);
	if (philo->r_fork->fork_stat == 0)
	{
		philo->r_fork->fork_stat = 1;
		pthread_mutex_unlock(&(philo->r_fork->mutex));
		return (1);
	}
	pthread_mutex_unlock(&philo->r_fork->mutex);
	return (0);
}

int	hold_fork_left(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork->mutex);
	if (philo->l_fork->fork_stat == 0)
	{
	    philo->l_fork->fork_stat = 1;
		pthread_mutex_unlock(&(philo->l_fork->mutex));
		return (1);
	}
	pthread_mutex_unlock(&philo->l_fork->mutex);
	return (0);
}

// void	hold_fork_left(t_philo *philo)
// {
// 	if (pthread_mutex_lock(&(philo->l_fork->mutex)) != 0)
// 		set_error(&(philo->share->error));
//     philo->l_fork->fork_stat = 1;
//     if (pthread_mutex_unlock(&(philo->l_fork->mutex)) != 0)
// 		set_error(&(philo->share->error));
// }

void	put_fork_down_right(t_philo *philo)
{
	if (pthread_mutex_lock(&(philo->r_fork->mutex)) != 0)
		set_error(&(philo->share->error));
    philo->r_fork->fork_stat = 0;
    if (pthread_mutex_unlock(&(philo->r_fork->mutex)) != 0)
		set_error(&(philo->share->error));
}

void	put_fork_down_left(t_philo *philo)
{
	if (pthread_mutex_lock(&(philo->l_fork->mutex)) != 0)
		set_error(&(philo->share->error));
    philo->l_fork->fork_stat = 0;
    if (pthread_mutex_unlock(&(philo->l_fork->mutex)) != 0)
		set_error(&(philo->share->error));
}

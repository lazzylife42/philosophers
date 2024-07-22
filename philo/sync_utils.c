/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:22:55 by smonte-e          #+#    #+#             */
/*   Updated: 2023/12/04 20:42:05 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_all_threads(t_table *table)
{
	while (!get_int(&table->table_mutex, &table->all_threads_ready))
		;
}

void	increase_long(t_mtx *mutex, long *value)
{
	s_mutex(mutex, LOCK);
	(*value)++;
	s_mutex(mutex, UNLOCK);
}

int	all_threads_running(t_mtx *mutex, long *threads, long philo_nbr)
{
	int	ret;

	ret = FALSE;
	s_mutex(mutex, LOCK);
	if (*threads == philo_nbr)
		ret = TRUE;
	s_mutex(mutex, UNLOCK);
	return (ret);
}

void	un_sync(t_philo *philo)
{
	if (philo->table->philo_nbr % 2 == 0)
	{
		if (philo->id % 2 == 0)
			precise_usleep(3e4, philo->table);
	}
	else
	{
		if (philo->id % 2 == 0)
			think(philo, TRUE);
	}
}

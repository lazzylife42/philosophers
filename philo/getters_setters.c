/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:51:47 by smonte-e          #+#    #+#             */
/*   Updated: 2023/12/04 20:42:33 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_int(t_mtx *mutex, int *dest, int value)
{
	s_mutex(mutex, LOCK);
	*dest = value;
	s_mutex(mutex, UNLOCK);
}

int	get_int(t_mtx *mutex, int *value)
{
	int	ret;

	s_mutex(mutex, LOCK);
	ret = *value;
	s_mutex(mutex, UNLOCK);
	return (ret);
}

void	set_long(t_mtx *mutex, long *dest, long value)
{
	s_mutex(mutex, LOCK);
	*dest = value;
	s_mutex(mutex, UNLOCK);
}

long	get_long(t_mtx *mutex, long *value)
{
	long	ret;

	s_mutex(mutex, LOCK);
	ret = *value;
	s_mutex(mutex, UNLOCK);
	return (ret);
}

int	simulation_finished(t_table *table)
{
	return (get_int(&table->table_mutex, &table->simulation_end));
}

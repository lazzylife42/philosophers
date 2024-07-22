/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 23:12:49 by smonte-e          #+#    #+#             */
/*   Updated: 2023/12/04 20:41:31 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	assign_fork(t_philo *philo, t_fork *forks, int pos)
{
	int	philo_nbr;

	philo_nbr = philo->table->philo_nbr;
	philo->first_fork = &forks[(pos + 1) % philo_nbr];
	philo->second_fork = &forks[pos];
	if ((philo->id % 2) == 0)
	{
		philo->first_fork = &forks[pos];
		philo->second_fork = &forks[(pos + 1) % philo_nbr];
	}
}

static void	philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < table->philo_nbr)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->full = FALSE;
		philo->meals_count = 0;
		s_mutex(&philo->philo_mutex, INIT);
		philo->table = table;
		assign_fork(philo, table->forks, i);
	}
}

void	data_init(t_table *table)
{
	int	i;

	i = -1;
	table->simulation_end = FALSE;
	table->all_threads_ready = FALSE;
	table->threads_running_nbr = 0;
	table->philos = s_malloc(sizeof(t_philo) * table->philo_nbr);
	table->forks = s_malloc(sizeof(t_fork) * table->philo_nbr);
	s_mutex(&table->write_mutex, INIT);
	s_mutex(&table->table_mutex, INIT);
	while (++i < table->philo_nbr)
	{
		s_mutex(&table->forks[i].fork, INIT);
		table->forks[i].fork_id = i;
	}
	philo_init(table);
}

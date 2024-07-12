/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:08:10 by jungslee          #+#    #+#             */
/*   Updated: 2024/07/12 17:10:48 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_state	state;
	t_philo	*philo;

	memset(&state, 0, sizeof(t_state));
	philo = NULL;
	if (check_argument_validity_and_init_input(argc, argv, &state) == -1)
		return (argument_error_return());
	if (init_all(&state, &philo) == -1)
		return (0);
}

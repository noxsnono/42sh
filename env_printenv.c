/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_printenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 15:41:22 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/01 16:14:47 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

// static void	ft_printenv(char **env)
// {
// 	while (*env && **env)
// 	{
// 		ft_putendl(*env);
// 		++env;
// 	}
// }

void	env_printenv(t_data *d)
{
	int		i;

	i = 0;
	printf("%s\n", "printenv");
	while (d->env[i] != NULL)
	{
		ft_putendl(d->env[i]);
		++i;
	}
}
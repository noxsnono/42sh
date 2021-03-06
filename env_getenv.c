/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_getenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 19:26:46 by nmohamed          #+#    #+#             */
/*   Updated: 2014/03/27 15:23:24 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Return values:
** NULL if *str is not found in **env
** Otherwise, returns an allocated COPY of the string found in **env
*/

char		*ft_getenv(char *var, char **env)
{
	int	i;

	i = 0;
	if (env == NULL || var == NULL)
	{
		ft_putstr_fd("Env is null | ft_getenv\n", 2);
		_exit(1);
		return (NULL);
	}
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], var, ft_strlen(var)) == 0
				&& env[i][ft_strlen(var)] == '=')
			break ;
		i++;
	}
	if (env != NULL && env[i] != NULL)
		return (ft_strdup(ft_strchr(env[i], '=') + 1));
	return (NULL);
}

char		*env_getenv(t_data *d)
{
	return (ft_getenv(d->varenv, d->cenv));
}

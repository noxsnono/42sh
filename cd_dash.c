/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_dash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scohen <scohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 18:02:56 by scohen            #+#    #+#             */
/*   Updated: 2014/03/11 18:02:57 by scohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	cd_dash(t_data *d, char *name)
{
	char	*pwd;
	char	*oldpwd;
	
	pwd = ft_getenv("PWD", d->env);
	oldpwd = ft_getenv("OLDPWD", d->env);
	if (chdir(oldpwd) == -1)
		cd_error(name);
	else
	{
		ft_setenv(d, "PWD", oldpwd);
		ft_setenv(d, "OLDPWD", pwd);
		free(pwd);
		free(oldpwd);
	}
}
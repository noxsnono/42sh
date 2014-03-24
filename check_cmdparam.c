/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmdparam.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 13:33:48 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/03/24 17:23:20 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	param_exit(t_data *d, char *tmp);
static int	param_unsetenv(t_data *d, char *tmp);
static int	param_setenv(t_data *d, char *tmp);
static int	param_cd(t_data *d, char *tmp);

/*
** check incoming linkcmd, execute if
** TEST OK jmoiroux
*/

int			check_cmdparam(t_data *d, t_more *link)
{
	char	*tmp;

	if (link->str != NULL)
	{
		tmp = ft_strtrim(link->str);
		if (ft_strncmp("cd", tmp, ft_strlen("cd")) == 0)
			return (param_cd(d, tmp));
		else if (ft_strncmp("setenv", tmp, ft_strlen("setenv")) == 0)
			return (param_setenv(d, tmp));
		else if (ft_strncmp("unsetenv", tmp, ft_strlen("unsetenv")) == 0)
			return (param_unsetenv(d, tmp));
		else if (ft_strncmp("exit", tmp, ft_strlen("exit")) == 0)
			return (param_exit(d, tmp));
		else if (ft_strncmp("echo", tmp, ft_strlen("echo")) == 0)
		{
			d->toexec = tmp;
			build_echo(d);
			ft_memdel((void **)&tmp);
			return (1);
		}
		else if (ft_strncmp("env", tmp, ft_strlen("env")) == 0)
		{
			d->toexec = tmp;
			env_printenv(d);
			ft_memdel((void **)&tmp);
			return (1);
		}
		else
		{
			ft_memdel((void **)&tmp);
			return (0);
		}
	}
	return (0);
}

static int	param_cd(t_data *d, char *tmp)
{
	d->toexec = tmp;
	build_cd(d);
	ft_memdel((void **)&tmp);
	return (1);
}

static int	param_setenv(t_data *d, char *tmp)
{
	d->toexec = tmp;
	build_setenv(d);
	ft_memdel((void **)&tmp);
	return (1);
}

static int	param_unsetenv(t_data *d, char *tmp)
{
	d->toexec = tmp;
	build_unsetenv(d);
	ft_memdel((void **)&tmp);
	return (1);
}

static int	param_exit(t_data *d, char *tmp)
{
	d->toexec = tmp;
	build_exit(d);
	ft_memdel((void **)&tmp);
	return (1);
}

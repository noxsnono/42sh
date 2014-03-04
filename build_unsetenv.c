/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_unsetenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoiroux <jmoiroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 11:12:09 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/03/03 12:08:06 by jmoiroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** remove line on env called from command
** TEST OK jmoiroux
*/

void	build_unsetenv(t_data *d)
{
	char	**tmp;

	tmp = ft_strsplit(d->line, ' ');
	if (tmp == NULL)
		ft_exit(d, "Split error (build_unsetenv)\n");
	if (tmp[1] == NULL)
	{
		ft_putstr("unsetenv usage: 'unsetenv variable'\n");
		return ;
	}
	d->varenv = tmp[1];
	env_unsetenv(d);
	if (tmp[0] != NULL)
		ft_memdel((void **)&tmp[0]);
}
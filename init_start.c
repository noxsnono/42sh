/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 12:55:55 by jmoiroux          #+#    #+#             */
/*   Updated: 2014/03/05 15:32:26 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** init all vars on struct data
** TEST OK jmoiroux
*/

void	init_start(t_data *d)
{
	d->env = NULL;
	d->buff = NULL;
	d->line = NULL;
	d->tree = NULL;
	d->varenv = NULL;
	d->valenv = NULL;
	d->lst_line = NULL;
}

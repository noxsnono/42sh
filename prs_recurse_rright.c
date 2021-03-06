/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_recurse_rright.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 12:29:00 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/27 15:24:40 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Do double right arrow
*/

static void	recurse_rright_error(void)
{
	ft_putstr_fd("Operator: '>>' usage: 'executable >> file'\n", 2);
	ft_putstr_fd("or 'executable | executable >> file' only\n", 2);
}

static int	recurse_rrightfork(t_data *d, int father, t_more *link, int fd)
{
	if ((father = fork()) < 0)
	{
		ft_putstr_fd("Fork() error >> (recurse_rright)\n", 2);
		return (-1);
	}
	if (father == 0)
	{
		d->toexec = link->prev->str;
		if (link->prev != NULL && link->prev->prev != NULL
				&& link->prev->prev->end == 1)
			recurse_pipe(d, link->prev, fd);
		else if (link->prev != NULL && link->prev->prev != NULL
				&& (link->prev->prev->end == 2
				|| link->prev->prev->end == 3))
			recurse_rright_error();
		else
		{
			dup2(fd, 1);
			exe_build_system(d);
		}
		_exit(0);
	}
	return (-1);
}

int			recurse_rright(t_data *d, t_more *link)
{
	int		father;
	int		fd;
	char	*tmp;

	father = -1;
	tmp = ft_strtrim(link->str);
	if ((fd = open(tmp, O_RDWR | O_CREAT | O_APPEND, 0777)) == -1)
	{
		ft_putstr_fd("File open error >> (recurse_rright)\n", 2);
		ft_memdel((void **)&tmp);
		return (-1);
	}
	ft_memdel((void **)&tmp);
	if (recurse_rrightfork(d, father, link, fd) == -1)
		return (-1);
	return (1);
}

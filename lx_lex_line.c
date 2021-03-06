/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_lex_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 12:54:43 by vjacquie          #+#    #+#             */
/*   Updated: 2014/03/27 15:24:10 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** return the pos of cmp in str, 0 if not found
*/

static int	lx_pos_str(char *str, char *cmp)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == cmp[0] && str[i + 1] == cmp[1])
			return (i + 2);
		i++;
	}
	return (0);
}

static char	*lx_or_and(char *str, t_data *d, char *cmp, int n)
{
	char	*tmp;
	char	*cpy;
	int		start;

	start = lx_pos_str(str, cmp);
	tmp = ft_strsub(str, 0, start - 2);
	lx_add_cmd(d, lx_new_cmd(tmp, n));
	cpy = ft_strsub(str, start, ft_strlen(str) - start);
	ft_memdel((void **)&str);
	return (cpy);
}

void		lx_lex_line(char *line, t_data *d)
{
	char	**cmd;
	int		i;

	i = 0;
	cmd = ft_strsplit(line, ';');
	while (cmd[i])
	{
		if (lx_pos_str(cmd[i], "||") != 0 || lx_pos_str(cmd[i], "&&") != 0)
		{
			if (lx_pos_str(cmd[i], "&&") == 0
				|| (lx_pos_str(cmd[i], "||") != 0
				&& lx_pos_str(cmd[i], "||") < lx_pos_str(cmd[i], "&&")))
				cmd[i] = lx_or_and(cmd[i], d, "||", 2);
			else
				cmd[i] = lx_or_and(cmd[i], d, "&&", 1);
		}
		else
		{
			lx_add_cmd(d, lx_new_cmd(cmd[i], 0));
			i++;
		}
	}
	free(cmd);
}

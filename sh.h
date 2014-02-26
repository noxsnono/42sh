/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 14:16:49 by mlaize            #+#    #+#             */
/*   Updated: 2014/02/26 13:48:14 by scohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include "libft/includes/libft.h"
# define MAX_PRIORITY 2

extern char			**environ;

typedef struct		s_tree
{
	int				type; /* type: 0 don't know type / 1 OPE / 2 CMD */
	int				ope; /* What operator is it */
	char			*command; /* The command string */
	struct s_tree	*left; /* link to left next node */
	struct s_tree	*right; /* link to right next node */
}					t_tree;


typedef struct	s_ope
{
	char		*operand;
	int			code;
	int			priority;
}				t_ope;


/*static t_ope	list_ope[] =
{
	{"|", 0, 0},
	{"<", 1, 0},
	{">>", 2, 1},
	{">", 3, 1},
	{"&&", 4, 2},
	{"||", 5, 2},
	{NULL, -1, -1}
};
*/

typedef struct	s_data
{
	char		**c_env;
}				t_data;


int		prs_build_me_tree(char *str, t_tree **tree);
int		prs_cut_last_str(t_tree *tree, t_ope operation);
int		prs_parser_lexer(char *str);

void	read_me_tree_mothafocka(t_tree*);

t_tree	*prs_create_tree_node(int type, int ope, char *command);

int		env_tablen(char **tab);
int		env_tabheight(char **tab);
void	env_copy(char **environ, t_data *d);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohamed <nmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 14:16:49 by mlaize            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2014/02/26 15:05:06 by nmohamed         ###   ########.fr       */
=======
/*   Updated: 2014/02/26 14:00:15 by nmohamed         ###   ########.fr       */
>>>>>>> c156a5b5d0cb5fdf718bb3f291845fe6c20a9363
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include "libft/includes/libft.h"
# define MAX_PRIORITY 2

# define WR(fd, str) write(fd, str, sizeof(str) - 1)
<<<<<<< HEAD

extern char			**environ;
=======
>>>>>>> c156a5b5d0cb5fdf718bb3f291845fe6c20a9363

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

<<<<<<< HEAD

=======
>>>>>>> c156a5b5d0cb5fdf718bb3f291845fe6c20a9363
static t_ope	list_ope[] =
{
	{"|", 0, 0},
	{"<", 1, 0},
	{">>", 2, 1},
	{">", 3, 1},
	{"&&", 4, 2},
	{"||", 5, 2},
	{NULL, -1, -1}
};
<<<<<<< HEAD


typedef struct	s_data
{
	char		**c_env;
=======

typedef struct	s_data
{
>>>>>>> c156a5b5d0cb5fdf718bb3f291845fe6c20a9363
	char		**env;
	t_tree		*tree;
	char		**cmd;
}				t_data;

<<<<<<< HEAD
char	*env_getenv(const char *name, t_data *d);
int		env_setenv(const char *name, const char *value, t_data *d);

=======
>>>>>>> c156a5b5d0cb5fdf718bb3f291845fe6c20a9363
int		prs_build_me_tree(char *str, t_tree **tree);
int		prs_cut_last_str(t_tree *tree, t_ope operation);
int		prs_parser_lexer(char *str);

void	read_me_tree_mothafocka(t_tree*);

t_tree	*prs_create_tree_node(int type, int ope, char *command);

#endif

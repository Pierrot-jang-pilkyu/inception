/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:35:19 by pjang             #+#    #+#             */
/*   Updated: 2022/11/19 14:36:35 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include <termios.h>
# include <string.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# define START (0)
# define END (1)
# define COMMAND (43)		// upper C
# define B_QUOTE (34)		// "
# define S_QUOTE (39)		// '
# define AND (38)			// &&
# define OR (125)			// ||
# define PIPE (124)			// |
# define OPEN_PTS (40)		// ( - parenthesis
# define CLOSE_PTS (41)		// )
# define REDIR (59)		// redirection
# define STD_IN (60)		// <
# define HEREDOC (61)		// <<
# define STD_OUTT (62)		// >
# define STD_OUTA (63)		// >>

typedef struct s_env
{
	char	*key;
	char	*value;
}				t_env;

// parsing
typedef struct s_prs
{
	int		s_e[2];
	char	*priority;
	t_list	*quote;
	t_list	*pts;
	t_list	*logical;
	t_list	*pipe;
	t_list	*redirect;
}				t_prs;

typedef struct s_tkn
{
	int		idx;
	char	*value;
}				t_tkn;

// typedef struct s_list
// {
// 	struct s_list	*prev;
// 	struct s_list	*next;
// 	void			*contents;
// }				t_list;

typedef struct s_tree
{
	int				key;
	char			*value;
	struct s_tree	*left;
	struct s_tree	*right;
}				t_tree;

typedef struct s_mini
{
	t_list	*env;
	t_tkn	*tkn;
	t_tree	*tree;
	int		*tree_idx;
	void	*contents;
}				t_mini;

t_mini	g_mini;

// init
void		init_prs(t_prs *prs);
void		init_tkn(t_list *temp);
void		init_mini(void);

// utils
u_int64_t	ft_pow(u_int64_t num, u_int64_t power);
void		free_prs(t_prs *prs);
void		safety_free(void *str);
void		safety_dimention_free(char **strs);
void		put_error(char *error_msg);

// token
void		set_token(t_tkn *token, int idx, char *value);
int			set_logical_pipe_token(char *buf, int i);
char		*get_token_value(t_list *temp, char *buf, int i);
int			set_redirection_token(t_list *temp, char *buf, int i);
void		set_command_token(t_list *temp, char *buf, int i);
void		get_token_array(t_prs *prs);

// parsing department
int			is_seq(char *c);
int			is_seq1(char *c);
int			is_seq2(char *c);
int			is_seq3(char *c);

// parsing divide
void		divide_quote(char *buf, t_prs *prs);
void		divide_pts(t_prs *prs);
void		divide_logical(t_prs *prs);
void		divide_pipe(t_prs *prs);
void		divide_redirection(t_prs *prs);
void		parsing(char *buf);
void		do_priority(char *buf, t_prs *prs);
char		*get_content(char	*buf, t_prs *prs);
void		into_list(char *buf, t_prs *prs, int no);
int			add_token(char *c, int *flag, int idx, int *init);
void		run_cmd(void);
void		run_exec(int flag);
int			is_builtin(char	*token);

#endif
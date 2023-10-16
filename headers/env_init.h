#ifndef ENV_INIT_H
# define ENV_INIT_H

typedef struct s_env
{
	char			*variable;
	char			*value;
	int				type;
	struct s_env	*next;
}	t_env;

char	*get_env_variable(char *s);
char	*get_env_value(char *s);
t_env	*env_to_linkedlist(char **envp);
char	**linked_list_to_double_array(t_env **env_head);

#endif

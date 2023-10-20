/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:14:03 by macarval          #+#    #+#             */
/*   Updated: 2023/10/16 11:52:32 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	c_echo(t_shell *shell)
{
	if (!strcmp_mod(shell->command, "echo"))
	{
		if (shell->flag && print_flag(*shell))
		{
			free(shell->flag);
			shell->flag = ft_strdup("-n");
		}
		if (strcmp_mod(shell->content, "$_"))
			update_(*shell);
		if (!strcmp_mod(shell->content, "$?"))
		{
			printf("%i", shell->exit_code);
			shell->exit_code = 0;
		}
		else
			apart_args(shell, ' ', print_echo);
		if (!shell->flag || verify_flags(shell->flag, "n"))
			printf("\n");
		return (1);
	}
	return (0);
}

int	print_echo(t_shell *shell)
{
	printf("%s", shell->content);
	return (1);
}

int	print_flag(t_shell shell)
{
	char	**split;
	int		i;
	int		control;

	split = ft_split(shell.flag, ' ');
	i = -1;
	control = 0;
	while (split[++i] && !verify_flags(split[i], "n"))
		control++;
	while (split[i])
		printf("%s ", split[i++]);
	free_array(&split);
	return (control);
}
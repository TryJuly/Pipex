/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:51:02 by strieste          #+#    #+#             */
/*   Updated: 2025/11/24 13:46:00 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	char	**path;
	char	*cmd;
	// char	**cmd_one;
	// char	**cmd_two;
	(void)ac;
	(void)av;
	(void)envp;

	path = get_envp(envp);
	cmd = check_path(av[2], path);
	ft_printf("%s\n", cmd);
	free(cmd);
	ft_free_array(path);
	return (0);
}

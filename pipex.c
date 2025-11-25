/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:51:02 by strieste          #+#    #+#             */
/*   Updated: 2025/11/25 12:36:39 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	char	**path;
	char	*cmd_1;
	char	*cmd_2;
	int		in_fd;
	int		out_fd;
	
	if (ac != 5)
		return (ft_printf("Error input less than 5\n"), 2);
	in_fd = check_infile_open(av[1]);
	out_fd = check_outfile_open(av[4]);
	path = get_envp(envp);
	if (!path)
		return (ft_printf("Error exctract PATH\n"), 2);
	cmd_1 = extract_cmd(2, av);
	if (!cmd_1)
		return (ft_free_array(path), 2);
	cmd_2 = extract_cmd(3, av);
	if (!cmd_2)
		return (ft_free_array(path), free(cmd_1), 2);
	pipex(in_fd, out_fd, cmd_1, cmd_2, path);
	ft_free_array(path);
	return (0);
}

void	pipex(int in_fd, int out_fd, char *cmd_1, char *cmd_2, char **path)
{
	int		pipe_fd[2];
	pid_t	child;
	
	pipe(pipe_fd);
}

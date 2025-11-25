/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:51:02 by strieste          #+#    #+#             */
/*   Updated: 2025/11/25 17:25:41 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_struct(t_data *data, char **av, char **envp);

int	main(int ac, char **av, char **envp)
{
	t_data	data;
	
	if (ac != 5)
		return (ft_printf("Error input less than 5\n"), 2);
	init_struct(&data, av, envp);
	ft_printf("data.envp: %s\n", data.envp[0]);
	ft_printf("data.envp: %s\n", data.envp[1]);
	ft_printf("data.envp: %s\n", data.envp[2]);
	ft_printf("data.envp: %s\n", data.envp[3]);
	ft_printf("data.envp: %s\n", data.envp[4]);
	ft_printf("#######################\n");
	ft_printf("data.cmd_1: %s\n", data.cmd_1[0]);
	ft_printf("data.cmd_1: %s\n", data.cmd_1[1]);
	ft_printf("data.cmd_1: %s\n", data.cmd_1[2]);
	ft_printf("#######################\n");
	ft_printf("data.cmd_2: %s\n", data.cmd_2[0]);
	ft_printf("data.cmd_2: %s\n", data.cmd_2[1]);
	ft_printf("data.cmd_2: %s\n", data.cmd_2[2]);
	ft_printf("#######################\n");
	ft_printf("data.path: %s\n", data.path[0]);
	ft_printf("data.path: %s\n", data.path[1]);
	ft_printf("data.path: %s\n", data.path[2]);
	ft_printf("data.path: %s\n", data.path[3]);
	return (0);
}

void	init_struct(t_data *data, char **av, char **envp)
{
	char	*tmp;
	
	data->fd_in = check_infile_open(av[1]);
	data->fd_out = check_outfile_open(av[4]);
	data->envp = envp;
	data->path = get_envp(envp);
	data->cmd_1 = extract_cmd(2, av);
	tmp = data->cmd_1[0];
	data->cmd_1[0] = find_path(data->cmd_1[0], data->path);
	free(tmp);
	data->cmd_2 = extract_cmd(3, av);
	tmp = data->cmd_2[0];
	data->cmd_2[0] = find_path(data->cmd_2[0], data->path);
	free(tmp);
}

// void	pipex(int in_fd, int out_fd, char *cmd_1, char *cmd_2, char **path)
// {
// 	int		pipe_fd[2];
// 	pid_t	child1;
// 	pid_t	child2;

// 	pipe(pipe_fd);
// }

void	child(int fd_in, int fd_out, char **cmd, char **envp)
{
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_in);
	close(fd_out);
	execve(cmd[0], cmd, envp);
	perror("execve");
	exit(1); // Need To FREE
}

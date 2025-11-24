/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:51:02 by strieste          #+#    #+#             */
/*   Updated: 2025/11/22 14:12:02 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// static int	check_path(char *cmd);
static int	check_infile_open(char *file);

int	main(int ac, char **av, char **envp)
{
	// char	**path;
	// char	**cmd_one;
	// char	**cmd_two;
	(void)ac;
	(void)av;
	(void)envp;

	// path = get_envp(envp);
	ft_printf("%d\n", check_file(av[1]));
	return (0);
}

static int	check_infile_open(char *file)
{
	int	fd;
	
	if (access(file, F_OK))
		return (ft_printf("Error invalide file\n"), 0);
	if (access(file, R_OK))
		return (ft_printf("Error access read file\n"), 0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error open\n"), 0);
	return (fd);
}

static int	check_outfile_open(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
}

// static int	check_path(char *cmd)
// {
// 	if (cmd[0] == '/')
// 	{
// 		if ()
// 	}
// 	return (0);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:29:04 by strieste          #+#    #+#             */
/*   Updated: 2025/11/24 13:30:47 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_infile_open(char *file)
{
	int	fd;
	
	if (access(file, F_OK))
		return (ft_printf("Error invalide infile\n"), 0);
	if (access(file, R_OK))
		return (ft_printf("Error access read infile\n"), 0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error open infile\n"), 0);
	return (fd);
}

int	check_outfile_open(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (ft_printf("Error open or create outfile\n"), 0);
	return (fd);
}

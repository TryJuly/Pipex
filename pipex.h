/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:51:36 by strieste          #+#    #+#             */
/*   Updated: 2025/11/24 13:30:06 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

/*				Extract command				*/

char	**extract_cmd(int ac, char **av);
char	**get_envp(char **envp);

/*				Check Path					*/

char	*check_path(char *cmd, char **path);

/*				File 						*/

int	check_infile_open(char *file);
int	check_outfile_open(char *file);

/*				Clean service				*/

void	ft_free_array(char **array);

#endif
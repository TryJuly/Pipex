/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:43:48 by strieste          #+#    #+#             */
/*   Updated: 2025/11/21 10:48:17 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**extract_cmd(int ac, char **av)
{
	char	**cmd_arg;

	cmd_arg = ft_split(av[ac], ' ');
	if (!cmd_arg[0])
		return (ft_printf("Fail extract cmd\n"), NULL);
	return (cmd_arg);
}

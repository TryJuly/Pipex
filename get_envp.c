/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:46:38 by strieste          #+#    #+#             */
/*   Updated: 2025/11/21 13:20:59 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_envp(char **envp)
{
	size_t	count;
	char	**path;
	char	*first;

	count = 0;
	while (ft_strncmp(envp[count], "PATH=", 5))
		count++;
	path = ft_split(envp[count], ':');
	if (!path[0])
		return (ft_printf("Error search PATH\n"), NULL);
	first = ft_substr(path[0], 5, ft_strlen(path[0]));
	if (!first[0])
		return (ft_free_array(path), NULL);
	free(path[0]);
	path[0] = first;
	return (path);
}

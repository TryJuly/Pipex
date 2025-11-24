/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:17:58 by strieste          #+#    #+#             */
/*   Updated: 2025/11/21 13:20:08 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_array(char **array)
{
	size_t	count;

	count = 0;
	while (array[count])
	{
		free(array[count]);
		count++;
	}
	free(array);
	return ;
}

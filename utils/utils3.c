/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:19:05 by belmiro           #+#    #+#             */
/*   Updated: 2024/08/21 11:31:22 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char	**copy_map(char **original_map)
{
	int		i;
	int		height;
	char	**copy;

	i = 0;
	height = 0;
	while (original_map[height])
		height++;
	copy = (char **)malloc((height + 1) * sizeof(char *));
	while (i < height)
	{
		copy[i] = ft_strdup(original_map[i]);
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

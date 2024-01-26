/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:03:11 by lbarcelo          #+#    #+#             */
/*   Updated: 2024/01/13 13:04:34 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	finish_line(t_list *stock)
{
	int		i;
	t_list	*current_node;

	if (!stock)
		return (0);
	current_node = ft_last_node(stock);
	i = 0;
	while (current_node->content[i])
	{
		if (current_node->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_last_node(t_list *stock)
{
	t_list	*current;

	current = stock;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	ft_malloc_line(char **line, t_list *stock)
{
	int	i;
	int	len;

	len = 0;
	while (stock)
	{
		i = 0;
		while (stock->content[i])
		{
			if (stock->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		stock = stock->next;
	}
	*line = malloc(sizeof(line) * (len + 1));
}

void	free_stock(t_list *stock)
{
	t_list	*current;
	t_list	*next;

	current = stock;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}

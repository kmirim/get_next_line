/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:11:19 by lbarcelo          #+#    #+#             */
/*   Updated: 2024/01/15 09:39:07 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_list	*stock[FD_SIZE];
	char			*line;

	if (fd < 0 || fd > FD_SIZE || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	ft_read(fd, &stock[fd]);
	if (!stock[fd])
		return (NULL);
	ft_line(stock[fd], &line);
	ft_clean(&stock[fd]);
	if (line[0] == '\0')
	{
		free_stock(stock[fd]);
		stock[fd] = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

void	ft_read(int fd, t_list **stock)
{
	char	*buf;
	int		bytes;

	bytes = 1;
	while (!finish_line(*stock) && bytes != 0)
	{
		buf = malloc(sizeof(buf) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		bytes = (int)read(fd, buf, BUFFER_SIZE);
		if ((*stock == NULL && bytes == 0) || bytes == -1)
		{
			free(buf);
			return ;
		}
		buf[bytes] = '\0';
		ft_stock(stock, buf, bytes);
		free(buf);
	}
}

void	ft_stock(t_list **stock, char *buf, int bytes)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->content = (char *)malloc(sizeof(char) * (bytes + 1));
	if (!new_node->content)
		return ;
	i = 0;
	while (buf[i] && i < bytes)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (!*stock)
	{
		*stock = new_node;
		return ;
	}
	last = ft_last_node(*stock);
	last->next = new_node;
}

void	ft_line(t_list *stock, char **line)
{
	int	i;
	int	j;

	if (!stock)
		return ;
	ft_malloc_line(line, stock);
	if (!*line)
		return ;
	j = 0;
	while (stock)
	{
		i = 0;
		while (stock->content[i])
		{
			if (stock->content[i] == '\n')
			{
				(*line)[j++] = stock->content[i];
				break ;
			}
			(*line)[j++] = stock->content[i++];
		}
		stock = stock->next;
	}
	(*line)[j] = '\0';
}

void	ft_clean(t_list **stock)
{
	t_list	*last;
	t_list	*res;
	int		i;
	int		j;

	res = malloc(sizeof(t_list));
	if (!stock || !res)
		return ;
	res->next = NULL;
	last = ft_last_node(*stock);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	res->content = malloc(sizeof(char) * ((ft_strlen(last->content) - i) + 1));
	if (!res->content)
		return ;
	j = 0;
	while (last->content[i])
		res->content[j++] = last->content[i++];
	res->content[j] = '\0';
	free_stock(*stock);
	*stock = res;
}

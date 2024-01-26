/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarcelo <lbarcelo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:58:59 by lbarcelo          #+#    #+#             */
/*   Updated: 2024/01/15 09:59:01 by lbarcelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef FD_SIZE
#  define FD_SIZE 1024
# endif 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
int		finish_line(t_list *stock);
t_list	*ft_last_node(t_list *stock);
void	ft_read(int fd, t_list **stock);
void	ft_stock(t_list **stock, char *buf, int bytes);
void	ft_line(t_list *stock, char **line);
void	ft_malloc_line(char **line, t_list *stock);
void	ft_clean(t_list **stock);
int		ft_strlen(const char *str);
void	free_stock(t_list *stock);
#endif

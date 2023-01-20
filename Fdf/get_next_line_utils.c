/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:25:22 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/01/19 15:51:41 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strchr(t_list *head)
{
	int		j;
	t_list	*last;

	j = 0;
	if (!head)
		return (1);
	last = ft_lstlast(head);
	while (last->text[j])
	{
		if (last->text[j] == '\n')
			return (0);
		j++;
	}
	return (1);
}

void	free_node(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !*lst || !del)
		return ;
	if (lst && del)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			del((*lst)->text);
			free(*lst);
			*lst = temp;
		}
	}
	*lst = NULL;
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	last = lst;
	if (!last)
		return (NULL);
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	ft_malloc(t_list *head, char **line)
{
	int	i;
	int	j;

	i = 0;
	while (head)
	{
		j = 0;
		while (head->text[j])
		{
			if (head->text[j] == '\n')
			{
				i++;
				break ;
			}
			j++;
			i++;
		}
		head = head->next;
	}
	(*line) = malloc (i * (sizeof(char) + 1));
	if (!(*line))
		return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:16:47 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/01/16 16:27:26 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	node_creat(t_list **buffer, char *buff, int red)
{
	int		i;
	t_list	*last;
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->next = NULL;
	new->text = malloc((red + 1) * sizeof(char));
	if (!new->text)
		return ;
	i = 0;
	while (buff[i] && i < red)
	{
		new->text[i] = buff[i];
		i++;
	}
	new->text[i] = '\0';
	if (!*buffer)
	{
		*buffer = new;
		return ;
	}
	last = ft_lstlast(*buffer);
	last->next = new;
}

void	read_file2(int fd, t_list **head)
{
	char	*buffer;
	int		read_count;

	read_count = 1;
	buffer = malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return ;
	while (ft_strchr(*head) && read_count > 0)
	{
		read_count = read (fd, buffer, BUFFER_SIZE);
		if (read_count < 0 || !buffer)
		{
			free(buffer);
			return ;
		}
		buffer[read_count] = '\0';
		node_creat(head, buffer, read_count);
	}
	free(buffer);
}

void	get_line(t_list *head, char **line)
{
	int		i;
	int		j;

	if (!head)
		return ;
	ft_malloc(head, line);
	if (!*line)
		return ;
	i = 0;
	while (head)
	{
		j = 0;
		while (head->text[j])
		{
			if (head->text[j] == '\n')
			{
				(*line)[i++] = head->text[j];
				break ;
			}
			(*line)[i++] = head->text[j++];
		}
		head = head->next;
	}
	(*line)[i] = '\0';
}

void	rest_node(t_list **head)
{
	t_list	*node;
	t_list	*rest;
	int		j;
	int		i;

	j = 0;
	i = 0;
	rest = malloc(sizeof(t_list));
	if (!rest || head == NULL)
		return ;
	rest->next = NULL;
	node = ft_lstlast(*head);
	while (node->text[j] && node->text[j] != '\n')
		j++;
	if (node->text[j] && node->text[j] == '\n')
		j++;
	rest->text = malloc (ft_strlen(node->text) - j + 1);
	if (!rest->text)
		return (free(node));
	while (node->text[j])
		rest->text[i++] = node->text[j++];
	rest->text[i] = '\0';
	free_node(head, free);
	*head = rest;
}

char	*get_next_line(int fd)
{
	static t_list	*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_file2(fd, &buffer);
	if (!buffer)
		return (NULL);
	get_line(buffer, &line);
	rest_node(&buffer);
	if (line[0] == '\0')
	{
		free_node(&buffer, free);
		free(line);
		line = NULL;
		return (NULL);
	}
	return (line);
}

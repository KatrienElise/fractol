/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/18 14:07:16 by rsteigen      #+#    #+#                 */
/*   Updated: 2019/04/03 17:52:39 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*find_curr_file(t_list **filelist, const int fd)
{
	t_list		*temp;

	temp = *filelist;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("\0", 1);
	if (!temp)
		return (NULL);
	temp->content_size = fd;
	ft_lstadd(filelist, temp);
	temp = *filelist;
	return (temp);
}

static int		line_length(char *str, int ret)
{
	int len;

	len = 0;
	while (str[len])
	{
		if (str[len] == '\n')
			return (len);
		len++;
	}
	if (ret == 0)
		return (ft_strlen(str));
	return (-1);
}

static int		add_content(t_list **currfile, char *buff, int ret)
{
	char	*t;
	t_list	*list;

	buff[ret] = '\0';
	list = *currfile;
	if (list->content == NULL)
		list->content = ft_strdup(buff);
	else
	{
		t = ft_strdup((char*)list->content);
		if (!t)
			return (0);
		free(list->content);
		list->content = ft_strjoin(t, buff);
		if (!list->content)
			return (0);
		free(t);
	}
	return (1);
}

static int		change_content(t_list **currfile, int l)
{
	char	*t;
	t_list	*list;
	int		length;

	list = *currfile;
	length = (int)ft_strlen(list->content);
	if (l < length)
	{
		t = ft_strdup((char*)list->content);
		if (!t)
			return (0);
		free(list->content);
		list->content = ft_strsub(t, l + 1, length - (l + 1));
		if (!list->content)
			return (0);
		free(t);
	}
	else
	{
		free(list->content);
		list->content = ft_strnew(0);
		if (!list->content)
			return (0);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	int				ret;
	static t_list	*head;
	t_list			*currfile;
	int				l;

	ret = 1;
	l = -1;
	if (!line || fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	currfile = find_curr_file(&head, fd);
	while (ret > 0 && ft_strchr(currfile->content, '\n') == NULL)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (!add_content(&currfile, buff, ret))
			return (-1);
	}
	if (ret == 0 && !ft_strlen(currfile->content))
		return (0);
	l = line_length(currfile->content, ret);
	*line = ft_strsub(currfile->content, 0, l);
	if (!change_content(&currfile, l) || !*line)
		return (-1);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:58:07 by jacens            #+#    #+#             */
/*   Updated: 2021/03/09 12:38:21 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.hpp"
#include "libft.hpp"

static int			ft_read_buffer(int fd, t_list_gnl **lst_fd)
{
	int		ret;
	char	*buffer;

	if (!(buffer = (char *)malloc(BUFFER_SIZE + 1)) || BUFFER_SIZE == 0)
		return (-1);
	ret = read(fd, buffer, BUFFER_SIZE);
	buffer[ret] = '\0';
	if ((*lst_fd)->buffer != NULL)
		free((*lst_fd)->buffer);
	(*lst_fd)->buffer = ft_strdup(buffer);
	free(buffer);
	buffer = NULL;
	return (ret);
}

static int			ft_strjoin_lst(t_list_gnl *lst_fd)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = ft_strlchr(lst_fd->line, '\n');
	j = ft_strlchr(lst_fd->buffer, '\n');
	if (!(ptr = (char *)malloc(i + j + 1))
	|| lst_fd->buffer == NULL)
		return (-1);
	*ptr = 0;
	if (lst_fd->line != NULL)
		ptr = ft_strcat_line(ptr, lst_fd->line);
	free(lst_fd->line);
	lst_fd->line = ptr;
	ptr = ft_strcat_line(ptr, lst_fd->buffer);
	ptr[i + j] = 0;
	if (lst_fd->buffer[j] != '\n')
		return (0);
	ft_strdel(lst_fd);
	return (1);
}

static int			ft_clear_one_line(t_list_gnl *lst_fd, int fd)
{
	int eol;
	int eof;

	eol = 0;
	eof = 1;
	while (eol == 0 && eof != 0)
	{
		eol = ft_strjoin_lst(lst_fd);
		if (eol == 0)
			eof = ft_read_buffer(fd, &lst_fd);
		if (eol == -1 || eof == -1)
			return (-1);
	}
	if (eol == 0 && eof == 0)
		return (0);
	return (1);
}

static t_list_gnl	*ft_list(t_list_gnl **lst, int fd)
{
	t_list_gnl	*beg_lst;
	t_list_gnl	*tmp;
	t_list_gnl	*news;

	beg_lst = *lst;
	while (beg_lst != NULL)
	{
		tmp = beg_lst;
		if (beg_lst->fd == fd)
			return (beg_lst);
		beg_lst = beg_lst->next;
	}
	if (!(news = (t_list_gnl *)malloc(sizeof(t_list_gnl))))
		return (NULL);
	news->fd = fd;
	news->next = NULL;
	news->buffer = NULL;
	news->line = NULL;
	ft_read_buffer(fd, &news);
	if (*lst == NULL)
		*lst = news;
	else
		tmp->next = news;
	return (news);
}

int					get_next_line(int fd, char **line)
{
	static t_list_gnl	*lst;
	t_list_gnl			*lst_fd;
	char				*ligne;
	int					clear_val;

	ligne = NULL;
	lst_fd = ft_list(&lst, fd);
	if (read(fd, 0, 0) < 0 || line == NULL || lst_fd == NULL)
		return (-1);
	lst_fd->line = ligne;
	if (lst_fd->buffer[0] == '\0' || lst_fd->buffer == NULL)
		if (ft_read_buffer(fd, &lst_fd) == 0)
		{
			ft_del_list(&lst, lst_fd);
			*line = ft_strdup("");
			return (0);
		}
	clear_val = ft_clear_one_line(lst_fd, fd);
	*line = ft_strdup(lst_fd->line);
	free(lst_fd->line);
	if (clear_val == 0)
		ft_del_list(&lst, lst_fd);
	if (*line == NULL)
		*line = ft_strdup("");
	return (clear_val);
}

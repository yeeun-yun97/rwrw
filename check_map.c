/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeyun <yeyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 10:29:32 by yeyun             #+#    #+#             */
/*   Updated: 2022/02/19 20:01:47 by yeyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	char			data;
};

int	is_number(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	else
		return (0);
}

void	write_list(struct s_node *root)
{
	struct s_node	*node;

	node = root;
	while (node->next != 0)
	{
		write(1, &(node->data), 1);
		node = node->next;
	}
}

int	is_printable_char(char ch)
{
	if (ch >= ' ' && ch <= '~')
		return (1);
	else
		return (0);
}

void	get_first_data(struct s_node *root, char *data, long long *row_length)
{
	struct s_node	*node;
	int				len;
	int				index;

	node = root;
	len = 0;
	while (node->data != '/n')
	{
		len++;
		node = node->next;
	}
	if (len < 4)
	{
		//error!
	}
	node = root;
	*row_length = 0;
	index = 0;
	while (index < len - 3)
	{
		if (is_number(node->data))
		{
			*row_length = (*row_length * 10) + (node->data - '0');
		}
		else
		{
			//error!
		}
		index++;
		node = node->prev;
	}
	data[0] = node->data;
	node = node->prev;
	data[1] = node->data;
	node = node->prev;
	data[2] = node->data;
	node = node->prev;
	data[3] = '\0';
	if (data[0] == data[1] || data[0] == data[2] || data[1] == data[2])
	{
		//error!
	}
	else if (is_printable_char(data[0]) == 0
		|| is_printable_char(data[1]) == 0
		|| is_printable_char(data[2]) == 0)
	{
		//error!
	}
}

void	free_list(struct s_node *root)
{
	while (node->next != 0)
	{
		write(1, &(node->data), 1);
		node = node->next;
		free(node->prev);
	}
}

int	check_map(char *fileName)
{
	int				fd;
	struct s_node	*root;
	struct s_node	*prev;
	char			ch;
	char			data[4];
	long long		*row_length;

	data = malloc(sizeof(char) * 4);
	root = malloc(sizeof(struct s_node) * 2);
	prev = root;
	fd = open(fileName, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot Open File\n", 17);
	}
	else
	{
		while (read(fd, &ch, 1) > 0)
		{
			prev->next = malloc(sizeof(struct s_node));
			prev->next->data = ch;
			prev->next->prev = prev;
			prev = prev->next;
		}
		write_list(root);
		get_first_data(root, data, row_length);
		fd = 0;
		while (fd >= row_length)
		{
			
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	index;

	if (argc == 1)
	{
		//여기서 표준입력? 받을 듯.
	}
	index = 1;
	if (argc > 1)
	{
		while (index < argc)
		{
			check_map(argv[index]);
			index++;
		}
	}
	return (0);
}

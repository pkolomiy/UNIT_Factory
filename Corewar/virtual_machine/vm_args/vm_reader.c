/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:30:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/03/30 20:29:16 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static unsigned int	to_big_endian(unsigned int x)
{
	return (((x >> 24) & 0x000000ff) |
	((x >> 8) & 0x0000ff00) |
	((x << 8) & 0x00ff0000) |
	((x << 24) & 0xff000000));
}

static _Bool		check_if_file_ok(char *name, char **error, int *fd,
															off_t *file_size)
{
	char	buff[2];

	if ((*fd = open(name, O_RDONLY)) < 0 || (read(*fd, buff, 0)) < 0)
	{
		*error = "Invalid argument\n";
		return (1);
	}
	*file_size = lseek(*fd, 0, SEEK_END);
	lseek(*fd, 0, SEEK_SET);
	if (*file_size > (long)(sizeof(t_header) + CHAMP_MAX_SIZE))
	{
		write(1, name, string_len(name));
		write(1, "\n", 1);
		*error = "Champion size bigger than CHAMP_MAX_SIZE\n";
		close(*fd);
		return (1);
	}
	return (0);
}

static _Bool		check_if_header_ok(char *name, t_cor *file, off_t file_size,
																char **error)
{
	*error = NULL;
	if (file->header->magic != COREWAR_EXEC_MAGIC)
		*error = "Invalid COREWAR_EXEC_MAGIC\n";
	if (file->header->prog_size != file_size - sizeof(t_header))
		*error = "Invalid program size\n";
	if (*error)
	{
		write(1, name, string_len(name));
		write(1, "\n", 1);
		free(file->header);
		free(file);
		return (1);
	}
	return (0);
}

t_cor				*vm_reader(char *name, char **error)
{
	int		fd;
	off_t	file_size;
	t_cor	*file;

	if (check_if_file_ok(name, error, &fd, &file_size))
		return (NULL);
	if (!(file = (t_cor*)malloc(sizeof(t_cor))))
		exit(malloc_error("vm_reader : file"));
	if (!(file->header = (t_header*)malloc(sizeof(t_header))))
		exit(malloc_error("vm_reader : file->header"));
	read(fd, file->header, sizeof(t_header));
	file->header->magic = to_big_endian(file->header->magic);
	file->header->prog_size = to_big_endian(file->header->prog_size);
	if (check_if_header_ok(name, file, file_size, error))
		return (NULL);
	if (!(file->program = (t_byte*)malloc(file->header->prog_size)))
		exit(malloc_error("vm_reader : file->program"));
	read(fd, file->program, file->header->prog_size);
	close(fd);
	return (file);
}

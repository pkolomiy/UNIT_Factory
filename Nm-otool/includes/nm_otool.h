/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:50:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/12/17 20:19:49 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_OTOOL_H
# define NM_OTOOL_H

# include <fcntl.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <unistd.h>
# include <stdbool.h>

# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <ar.h>

# include "arch.h"
# include "errors.h"

# define SWAP_16(x) ((((x) & 0xff00U) >> 8U) | (((x) & 0x00ffU) << 8U))
# define SWAP_32(x) ((SWAP_16(x) << 16U) | (SWAP_16((x) >> 16U)))
# define SWAP_64(x) ((SWAP_32(x) << 32U) | (SWAP_32((x) >> 32U)))

enum {FT_NM, FT_OTOOL};

typedef struct ar_hdr				t_ar;
typedef struct fat_header			t_fat;
typedef struct fat_arch				t_arch;
typedef struct fat_arch_64			t_arch64;
typedef struct mach_header			t_mh;
typedef struct mach_header_64		t_mh64;
typedef struct load_command			t_lc;
typedef struct symtab_command		t_symcmd;
typedef struct segment_command		t_segcmd;
typedef struct segment_command_64	t_segcmd64;
typedef struct section				t_sec;
typedef struct section_64			t_sec64;
typedef struct nlist				t_nlst;
typedef struct nlist_64				t_nlst64;

typedef struct s_sections	t_sections;
typedef struct s_symbol		t_symbol;

typedef struct s__text		t__text;

typedef struct s_nm_otool	t_nm_otool;

/*
** structs for nm
*/

struct		s_sections
{
	int	text;
	int	data;
	int	bss;
	int	iterator;
};

struct		s_symbol
{
	char		*str;
	uint8_t		type;
	uint8_t		sect;
	uint64_t	value;
};

/*
** structs for otool
*/

struct		s__text
{
	uint8_t		*mem;
	uint32_t	size;
	uint64_t	addr;
	cpu_type_t	cputype;
};

struct		s_nm_otool
{
	bool		print_file_name;
	int			program;
	char		*file_name;
	void		*ptr;
	size_t		ptr_size;
	size_t		ptr_offset;
	bool		swap;
	bool		is_64;
	t_sections	sect;
	t_symbol	*syms;
	uint32_t	nsyms;
	t__text		text_sect;
};

/*
** libft
*/

int			ft_strlen(const char *str);
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(char *s1, char *s2, int size);
int			ft_atoi(char *str);

/*
** parse
*/

int			parse_file(t_nm_otool *prog);
int			parse_object(t_nm_otool prog);
int			parse_archive(t_nm_otool *prog);
int			parse_fat(t_nm_otool *prog);
int			parse_macho(t_nm_otool *prog);
int			parse_segment_32(t_nm_otool *prog, size_t offset);
int			parse_segment_64(t_nm_otool *prog, size_t offset);
int			parse_load_cmd_32(t_nm_otool *prog, uint32_t lc_type,
									int (*parse_func)(t_nm_otool*, size_t));
int			parse_load_cmd_64(t_nm_otool *prog, uint32_t lc_type,
									int (*parse_func)(t_nm_otool*, size_t));

/*
** print
*/

int			print_error(t_nm_otool *prog, char *error_msg);
void		print_arch(t_nm_otool *prog, cpu_type_t cputype,
														cpu_subtype_t subtype);
void		print_symbols(t_nm_otool *prog);
int			print_otool(t_nm_otool *prog);
void		print_hex(uint64_t nbr, int width);

/*
** src
*/

void		*get_mem(t_nm_otool *prog, size_t offset, size_t size);
uint32_t	swap(t_nm_otool *prog, uint32_t nbr);
void		sort_symbols(t_nm_otool *prog);

#endif

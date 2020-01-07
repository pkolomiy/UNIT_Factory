/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arch.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 22:38:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/12/17 20:19:34 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARCH_H
# define ARCH_H

# include <mach-o/fat.h>
# include <stdlib.h>

# ifndef CPU_TYPE_VEO
#  define CPU_TYPE_VEO ((cpu_type_t) 255)
#  define CPU_SUBTYPE_VEO_1 ((cpu_subtype_t) 1)
#  define CPU_SUBTYPE_VEO_2 ((cpu_subtype_t) 2)
#  define CPU_SUBTYPE_VEO_3 ((cpu_subtype_t) 3)
#  define CPU_SUBTYPE_VEO_4 ((cpu_subtype_t) 4)
#  define CPU_SUBTYPE_VEO_ALL CPU_SUBTYPE_VEO_2
# endif

typedef struct s_arch_flag	t_arch_flag;

struct	s_arch_flag
{
	char			*name;
	cpu_type_t		cputype;
	cpu_subtype_t	cpusubtype;
};

static const t_arch_flag	g_arch[56] = {
	{"any", CPU_TYPE_ANY, CPU_SUBTYPE_MULTIPLE},
	{"little", CPU_TYPE_ANY, CPU_SUBTYPE_LITTLE_ENDIAN},
	{"big", CPU_TYPE_ANY, CPU_SUBTYPE_BIG_ENDIAN},
	{"ppc64", CPU_TYPE_POWERPC64, CPU_SUBTYPE_POWERPC_ALL},
	{"x86_64", CPU_TYPE_X86_64, CPU_SUBTYPE_X86_64_ALL},
	{"x86_64h", CPU_TYPE_X86_64, CPU_SUBTYPE_X86_64_H},
	{"arm64", CPU_TYPE_ARM64, CPU_SUBTYPE_ARM64_ALL},
	{"ppc970-64", CPU_TYPE_POWERPC64, CPU_SUBTYPE_POWERPC_970},
	{"ppc", CPU_TYPE_POWERPC, CPU_SUBTYPE_POWERPC_ALL},
	{"i386", CPU_TYPE_I386, CPU_SUBTYPE_I386_ALL},
	{"m68k", CPU_TYPE_MC680x0, CPU_SUBTYPE_MC680x0_ALL},
	{"hppa", CPU_TYPE_HPPA, CPU_SUBTYPE_HPPA_ALL},
	{"sparc", CPU_TYPE_SPARC, CPU_SUBTYPE_SPARC_ALL},
	{"m88k", CPU_TYPE_MC88000, CPU_SUBTYPE_MC88000_ALL},
	{"i860", CPU_TYPE_I860, CPU_SUBTYPE_I860_ALL},
	{"veo", CPU_TYPE_VEO, CPU_SUBTYPE_VEO_ALL},
	{"arm", CPU_TYPE_ARM, CPU_SUBTYPE_ARM_ALL},
	{"ppc601", CPU_TYPE_POWERPC, CPU_SUBTYPE_POWERPC_601},
	{"ppc603", CPU_TYPE_POWERPC, CPU_SUBTYPE_POWERPC_603},
	{"ppc603e", CPU_TYPE_POWERPC, CPU_SUBTYPE_POWERPC_603e},
	{"ppc603ev", CPU_TYPE_POWERPC, CPU_SUBTYPE_POWERPC_603ev},
	{"ppc604", CPU_TYPE_POWERPC, CPU_SUBTYPE_POWERPC_604},
	{"ppc604e", CPU_TYPE_POWERPC, CPU_SUBTYPE_POWERPC_604e},
	{"ppc750", CPU_TYPE_POWERPC, CPU_SUBTYPE_POWERPC_750},
	{"ppc7400", CPU_TYPE_POWERPC, CPU_SUBTYPE_POWERPC_7400},
	{"ppc7450", CPU_TYPE_POWERPC, CPU_SUBTYPE_POWERPC_7450},
	{"ppc970", CPU_TYPE_POWERPC, CPU_SUBTYPE_POWERPC_970},
	{"i486", CPU_TYPE_I386, CPU_SUBTYPE_486},
	{"i486SX", CPU_TYPE_I386, CPU_SUBTYPE_486SX},
	{"pentium", CPU_TYPE_I386, CPU_SUBTYPE_PENT},
	{"i586", CPU_TYPE_I386, CPU_SUBTYPE_586},
	{"pentpro", CPU_TYPE_I386, CPU_SUBTYPE_PENTPRO},
	{"i686", CPU_TYPE_I386, CPU_SUBTYPE_PENTPRO},
	{"pentIIm3", CPU_TYPE_I386, CPU_SUBTYPE_PENTII_M3},
	{"pentIIm5", CPU_TYPE_I386, CPU_SUBTYPE_PENTII_M5},
	{"pentium4", CPU_TYPE_I386, CPU_SUBTYPE_PENTIUM_4},
	{"m68030", CPU_TYPE_MC680x0, CPU_SUBTYPE_MC68030_ONLY},
	{"m68040", CPU_TYPE_MC680x0, CPU_SUBTYPE_MC68040},
	{"hppa7100LC", CPU_TYPE_HPPA, CPU_SUBTYPE_HPPA_7100LC},
	{"veo1", CPU_TYPE_VEO, CPU_SUBTYPE_VEO_1},
	{"veo2", CPU_TYPE_VEO, CPU_SUBTYPE_VEO_2},
	{"veo3", CPU_TYPE_VEO, CPU_SUBTYPE_VEO_3},
	{"veo4", CPU_TYPE_VEO, CPU_SUBTYPE_VEO_4},
	{"armv4t", CPU_TYPE_ARM, CPU_SUBTYPE_ARM_V4T},
	{"armv5", CPU_TYPE_ARM, CPU_SUBTYPE_ARM_V5TEJ},
	{"xscale", CPU_TYPE_ARM, CPU_SUBTYPE_ARM_XSCALE},
	{"armv6", CPU_TYPE_ARM, CPU_SUBTYPE_ARM_V6},
	{"armv6m", CPU_TYPE_ARM, CPU_SUBTYPE_ARM_V6M},
	{"armv7", CPU_TYPE_ARM, CPU_SUBTYPE_ARM_V7},
	{"armv7f", CPU_TYPE_ARM, CPU_SUBTYPE_ARM_V7F},
	{"armv7s", CPU_TYPE_ARM, CPU_SUBTYPE_ARM_V7S},
	{"armv7k", CPU_TYPE_ARM, CPU_SUBTYPE_ARM_V7K},
	{"armv7m", CPU_TYPE_ARM, CPU_SUBTYPE_ARM_V7M},
	{"armv7em", CPU_TYPE_ARM, CPU_SUBTYPE_ARM_V7EM},
	{"arm64v8", CPU_TYPE_ARM64, CPU_SUBTYPE_ARM64_V8},
	{NULL, 0, 0}
};

#endif

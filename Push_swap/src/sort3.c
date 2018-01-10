/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 23:52:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/01/07 00:46:22 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define FIRST_A m->a->nbr
#define SECOND_A m->a->next->nbr
#define THIRD_A m->a->next->next->nbr
#define FIRST_B m->b->nbr
#define SECOND_B m->b->next->nbr
#define THIRD_B m->b->next->next->nbr

void	sort3_helper(t_main *m, int flag, int nbr)
{
	if (flag == PA)
		while (--nbr)
			pa_pb(PA, m);
	else if (flag == SA)
	{
		ra_rb_rr(RA, m);
		sa_sb_ss(SA, m);
		rra_rrb_rrr(RRA, m);
	}
	else if (flag == SB)
	{
		ra_rb_rr(RB, m);
		sa_sb_ss(SB, m);
	}
	else if (flag == RRB)
	{
		(m->b_len == 3) ? sa_sb_ss(SB, m) : 0;
		if (m->b_len != 3)
		{
			m->len -= 2;
			sort3_helper(m, SB, 0);
			sort3_helper(m, PA, 3);
		}
		rra_rrb_rrr(RRB, m);
	}
}

void	sort3a(t_main *m)
{
	if (FIRST_A < SECOND_A && SECOND_A > THIRD_A && THIRD_A > FIRST_A)
	{
		(m->a_len == 3) ? rra_rrb_rrr(RRA, m) : sort3_helper(m, SA, 0);
		(m->a_len == 3) ? sa_sb_ss(SA, m) : 0;
	}
	else if (FIRST_A > SECOND_A && SECOND_A < THIRD_A && THIRD_A < FIRST_A)
	{
		(m->a_len == 3) ? ra_rb_rr(RA, m) : sa_sb_ss(SA, m);
		(m->a_len != 3) ? sort3_helper(m, SA, 0) : 0;
	}
	else if (FIRST_A < SECOND_A && SECOND_A > THIRD_A && THIRD_A < FIRST_A)
	{
		(m->a_len == 3) ? rra_rrb_rrr(RRA, m) : sort3_helper(m, SA, 0);
		(m->a_len != 3) ? sa_sb_ss(SA, m) : 0;
	}
	else if (FIRST_A > SECOND_A && SECOND_A > THIRD_A && THIRD_A < FIRST_A)
	{
		(m->a_len == 3) ? ra_rb_rr(RA, m) : sa_sb_ss(SA, m);
		(m->a_len != 3) ? sort3_helper(m, SA, 0) : 0;
		sa_sb_ss(SA, m);
	}
}

void	sort3b(t_main *m)
{
	if (FIRST_B > SECOND_B && FIRST_B > THIRD_B)
	{
		m->len--;
		pa_pb(PA, m);
		(FIRST_B < SECOND_B) ? sa_sb_ss(SB, m) : 0;
	}
	else if (FIRST_B < SECOND_B && SECOND_B > THIRD_B && THIRD_B > FIRST_B)
	{
		m->len -= 2;
		ra_rb_rr(RB, m);
		sort3_helper(m, PA, 3);
		(m->b_len != 1) ? rra_rrb_rrr(RRB, m) : 0;
	}
	else if (FIRST_B > SECOND_B && SECOND_B < THIRD_B && THIRD_B > FIRST_B)
	{
		(m->b_len != 3) ? sort3_helper(m, SB, 0) : 0;
		m->len = (m->b_len == 3) ? m->len : m->len - 1;
		(m->b_len != 3) ? pa_pb(PA, m) : 0;
		rra_rrb_rrr(RRB, m);
	}
	else if (FIRST_B < SECOND_B && SECOND_B < THIRD_B && THIRD_B > FIRST_B)
	{
		sort3_helper(m, RRB, 0);
	}
	sort3_helper(m, PA, m->len + 1);
}

void	sort_3_elem(_Bool stack, t_main *m)
{
	if (m->len == 1 && stack == B)
		pa_pb(PA, m);
	else if (m->len != 1)
	{
		if (m->len == 2 && stack == B)
		{
			if (FIRST_B < SECOND_B)
				sa_sb_ss(SB, m);
			sort3_helper(m, PA, 3);
		}
		else if (m->len == 2 && stack == A && FIRST_A > SECOND_A)
			sa_sb_ss(SA, m);
		else if (m->len == 3 && stack == B)
		{
			if (FIRST_B < SECOND_B && SECOND_B > THIRD_B && THIRD_B < FIRST_B)
				sa_sb_ss(SB, m);
			sort3b(m);
		}
		else if (m->len == 3 && stack == A)
		{
			if (FIRST_A > SECOND_A && SECOND_A < THIRD_A && THIRD_A > FIRST_A)
				sa_sb_ss(SA, m);
			sort3a(m);
		}
	}
}

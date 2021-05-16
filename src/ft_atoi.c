/* ************************************************************************** */
/*                                                                            */
/*       ::::::    ::::::   :::  ::::::::  ::::::::   :::  ::::::    :::::::  */
/*     :+:   :+: :+:   :+: :+: :+:   :+:  :+:    :+: :+: :+:   :+: :+:    :+: */
/*    +:+       +:+       +:+ +:+   +:+  +:+    +:+     +:+       +:+    +:+  */
/*   +#+       +:+       +#+ +:+   +#+  +:+    +#+ +:+ +#+       +#+:+:+#+:   */
/*  +#+       +#+       +#+   +#+#+#+# #+#+#+#+   +#+ +#+       +#+           */
/* #+#   #+# #+#   #+# #+#            #+#    #+# #+# #+#   #+# #+#    #+#     */
/*  ######    ######  ############## ###    ### ###   ######    #######       */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/*   ft_atoi.c                                cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/05/11 16:10:20  /  2021/05/11 16:10:37 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../xtox.h"

/*                                                                            *\
						FT_ATOI (String to Integer)

	The  ft_atoi() function converts the initial portion of the string to
	integer.
	In case of overflow, the function returns the maximum or minimum number
	depending on the sign.

	Cases:
		if number >= +2147483647 function returns +2147483647
		if number <= -2147483648 function returns -2147483648
																   @cclarice
\*                                                                            */

int	ft_atoi(const char *str)
{
	const char	sgn = 1 - ((*str == '-') << 1);
	int			ret;

	ret = 0;
	str += (*str == '+' || *str == '-');
	while (*str == '0')
		++str;
	while ((*str >= '0' && *str <= '9' && ret <= 214748363)
		|| (*str >= '0' && *str <= '7' && ret == 214748364))
	{
		ret *= 10;
		ret += *str - '0';
		++str;
	}
	if (*str >= '0' && *str <= '9')
	{
		if (sgn == 1)
			return (2147483647);
		return (-2147483648);
	}
	return (ret * sgn);
}

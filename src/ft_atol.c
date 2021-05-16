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
/*   ft_atol.c                                cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/05/11 16:21:36  /  2021/05/11 16:21:49 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "../xtox.h"

/*                                                                            *\
					FT_ATOL (String to Long Integer)

	The  ft_atol() function converts the initial portion of the string to
	long integer.
	In case of overflow, the function returns the maximum or minimum number
	depending on the sign.

	Cases:
		if number >= +9223372036854775807 func returns +9223372036854775807
		if number <= -9223372036854775808 func returns -9223372036854775808
																   @cclarice
\*                                                                            */

long	ft_atol(const char *str)
{
	const char	sgn = 1 - ((*str == '-') << 1);
	long		ret;

	ret = 0;
	str += (*str == '+' || *str == '-');
	while (*str == '0')
		++str;
	while ((*str >= '0' && *str <= '9' && ret <= 922337203685477579)
		|| (*str >= '0' && *str <= '7' && ret == 922337203685477580))
	{
		ret *= 10;
		ret += *str - '0';
		++str;
	}
	if (*str >= '0' && *str <= '9')
	{
		if (sgn == 1)
			return (9223372036854775807);
		return (-9223372036854775807 - 1);
	}
	return (ret * sgn);
}

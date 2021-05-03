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
/*   tester_xtox.c                            cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/05/03 05:35:24  /  2021/05/03 05:35:28 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "xtox.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	main(int c, char *v[])
{
	char	*str;

	if (c != 1)
		str = v[1];
	else
		str = "125";
	write(1, "<-Test->\n", 9);
	printf("Origin atoi   : %d\n", atoi(str));
	printf("My Own atoi   : %d\n", ft_atoi(str));
	write(1, "<->\n", 4);
	printf("Origin atol   : %ld\n", atol(str));
	printf("My Own atol   : %ld\n", ft_atol(str));
	write(1, "<->\n", 4);
	printf("!!!!!! strtoul: %ld\n", atol(str));
	printf("My Own strtoui: %u\n", ft_strtoui(str));
	write(1, "<->\n", 4);
	printf("Origin strtoul: %ld\n", atol(str));
	printf("My Own strtoul: %ld\n", ft_strtoul(str));
	write(1, "<-Done->\n", 9);
	return (0);
}
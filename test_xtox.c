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
/*   test_xtox.c                              cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/05/09 14:15:27  /  2021/05/09 14:15:41 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "xtox.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	main(int c, char *v[])
{
	char	*str;
	int		i;
	long	l;

	if (c != 1)
		str = v[1];
	else
		str = "125.521";
	write(1, "<----- < Test > ----->\n", 23);
	printf("Origin atoi   : %d\n", atoi(str));
	printf("My Own atoi   : %d\n", (i = ft_atoi(str)));
	printf("My own itoa   : %s\n", ft_itoa(i));
	write(1, "<-------------------->\n", 23);
	printf("Origin atol   : %ld\n", atol(str));
	printf("My Own atol   : %ld\n", (l = ft_atol(str)));
	printf("My own ltoa   : %s\n",  ft_ltoa(l));
	write(1, "<-------------------->\n", 23);
	printf("Origin atof   : %.50f\n", atof(str));
	printf("My Own atod   : %.50f\n", ft_atod(str));
	write(1, "<-------------------->\n", 23);
	printf("!!!!!! strtoul: %ld\n", atol(str));
	printf("My Own strtoui: %u\n", ft_atoui(str));
	write(1, "<-------------------->\n", 23);
	printf("Origin strtoul: %ld\n", atol(str));
	printf("My Own strtoul: %ld\n", ft_atoul(str));
	write(1, "<----- < Done > ----->\n", 23);
	return (0);
}

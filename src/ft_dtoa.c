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
/*   ft_dtoa.c                                cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/05/10 19:04:31  /  2021/05/10 19:04:45 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

//#include "xtox.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

char *ft_dtoa(double d)
{
	char *str;

	str = (char *)malloc(sizeof(char) * 1 + 1);
	str[1] = 0;
	str[0] = (int)d % 256;
	return (str);
}

int		ft_doublelen(double biba)
{
	int i;

	i = 1;
	while (biba >= 10)
	{
		i++;
		biba /= 10;
	}
	return (i);
}

int main(int c, char *v[])
{
	float  a;
	float b;

	a = 3.402823e+38f;
	b = a;
	a -= 128.f;
	a -= 128.f;
	a -= 128.f;
	a -= 128.f;
	b -= 28.f;
	printf("%f\n\n", 3.402823e+38f);
	printf("%f\n\n", a);
	printf("%f\n", b);
	return (0);
}

//	int main(int c, char *v[])
//	{
//		double		d;
//		long		lli;
//	
//		if (c >= 2)
//			d = atof(v[1]);
//		else
//			d = 1.797693e+308;
//		lli = (long)d;
//		printf("Double: %f\n", d);
//		printf("D to A: %s\n", ft_dtoa(d));
//		printf("After : %ld\n", lli);
//		return (0);
//	}

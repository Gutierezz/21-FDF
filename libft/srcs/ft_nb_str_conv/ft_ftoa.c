/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:45:46 by ttroll            #+#    #+#             */
/*   Updated: 2019/04/12 13:15:12 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_math.h"

static size_t	ft_dbl_ipart_to_arr(double ipart, char **nb_str, int sign)
{
	size_t		size;
	size_t		i;

	i = 0;
	size = 1 + sign;
	while (ipart >= 10.f)
	{
		ipart /= 10;
		size++;
	}
	*nb_str = ft_strnew(size);
	if (sign)
		(*nb_str)[i++] = '-';
	while (i < size)
	{
		(*nb_str)[i++] = HEX_STR[(int)ipart];
		ipart -= (int)ipart;
		ipart *= 10;
	}
	return (ft_strlen(*nb_str));
}

static char		*prec_str(double fpart, size_t prec)
{
	char		*fl_str;
	size_t		i;

	i = 0;
	prec++;
	fl_str = ft_strnew(prec);
	fl_str[i++] = '.';
	while (i < prec)
	{
		fpart *= 10;
		fl_str[i] = HEX_STR[(int)fpart];
		fpart -= (int)fpart;
		i++;
	}
	return (fl_str);
}

static void		ft_exp_handle(double *nb, int *offs, size_t prec)
{
	*offs = 0;
	if (ft_iszero(*nb))
		return ;
	while (FLT_ABS(*nb) < 1.f)
	{
		*nb *= 10;
		(*offs)--;
	}
	while (FLT_ABS(*nb) > 10.f)
	{
		*nb /= 10;
		(*offs)++;
	}
	ft_round_double(nb, prec);
	if ((long long)nb > 9)
	{
		(*offs)++;
		*nb = *nb / 10;
	}
}

char			*ft_ftoa(double nb, size_t prec, size_t *length, int *exp_form)
{
	char	*fl_str;
	char	*nb_str;
	double	ipart;
	double	fpart;

	nb_str = NULL;
	fl_str = NULL;
	if (ft_isnan(nb) || ft_isinf(nb))
	{
		*length = 3;
		return (ft_isnan(nb) ? ft_strdup("nan") : ft_strdup("inf"));
	}
	if (*exp_form)
		ft_exp_handle(&nb, exp_form, prec);
	else
		(!ft_iszero(nb)) ? ft_round_double(&nb, prec) : nb;
	fpart = ft_nullsign_dbl(ft_modf(nb, &ipart));
	fl_str = (prec != 0) ? prec_str(fpart, prec) : NULL;
	*length = prec + \
	ft_dbl_ipart_to_arr(ft_nullsign_dbl(ipart), &nb_str, ft_getsign_dbl(ipart));
	return (ft_strjoin_free(&nb_str, &fl_str));
}

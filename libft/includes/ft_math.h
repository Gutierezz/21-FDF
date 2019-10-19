/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:25:37 by ttroll            #+#    #+#             */
/*   Updated: 2019/10/19 16:26:22 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include "libft.h"

# define FT_LN_2 0.693147180559945286226763982995
# define FT_LN_10 2.302585092994045901093613792909
# define FT_LN_16 2.772588722239781144907055931980

int					ft_sqrt(int nb);
long long			ft_pow(long long nb, unsigned int pow);
double				ft_powf_ip(double x, int pow);
double				ft_exp(double x);
double				ft_ln(double x);
double				ft_log2(double x);
double				ft_log10(double x);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 20:56:58 by afrasch           #+#    #+#             */
/*   Updated: 2021/06/25 19:02:12 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *) malloc(sizeof(char) * 2);
	if (!str)
		return (0);
	else if (n < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		str = ft_strjoin(str, ft_itoa(-n));
	}
	else if (n > 9)
		str = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else
	{
		str[0] = n + '0';
		str[1] = '\0';
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 22:38:42 by tmarchen          #+#    #+#             */
/*   Updated: 2017/08/01 23:10:19 by tmarchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *t;

	t = s1;
	while (*s1 != '\0')
		s1++;
	while (*s2 != '\0' && n--)
		*s1++ = *s2++;
	*s1 = '\0';
	return (t);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:05:54 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/22 15:35:52 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** char *ft_strrev(char *s)
** ---
** dsc: basic string reverse function
**      based on xor swap algorithm
** ---
** par: a pointer to the source string
** ret: a pointer to the source string
** not: n/a
*/

char	*ft_strrev(char *s)
{
	const char	*begin = s;
	char		*end;

	end = s;
	while (*end)
		end++;
	while (s < --end)
	{
		*s ^= *end;
		*end ^= *s;
		*s++ ^= *end;
	}
	return ((char *)begin);
}

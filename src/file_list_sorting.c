/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_list_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboutoil <bboutoil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:13:34 by bboutoil          #+#    #+#             */
/*   Updated: 2019/02/22 19:53:26 by bboutoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		compare_by_ascii(t_fstat *f1, t_fstat *f2)
{
	return (NOT_IMPLEMENTED_FEATURE);
}


t_flist	*partition(t_flist *f_list, t_flist *t_flist_one, t_flist *t_flist_two, t_options *opt)
{
	t_flist	*pivot;

	pivot = f_list;
//	while ()
	return (pivot);
}
/* <principe de l algorithme:
	il faut diviser la liste en deux listes autours d une valeur pivot. Une liste contient les valeurs superieurs 
 au pivot l autre inferieur ou egales.
Une fois fait on fait le tri sur ces listes avant de les rejoindre en une meme liste.
Il est plus rapide de trier deux courtes listes qu une longue.
*/
void	f_list_qsort(t_flist *f_list, t_options *opt)
{
	// exemple d utilisation du ptr de func au cas ou t aurais oublie:
	// if (opt->sort_func(fl[3], fl[12]) == 1)
	// par default sort_func = compare by ascii : voir main.c
}



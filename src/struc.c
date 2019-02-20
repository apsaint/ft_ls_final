/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:14:35 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/20 16:54:23 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/* Initialisation de la structure de chaque element (fichier, repertoire, etc)
 * definit a partir des fonctions readdir et stat
 */
void	init_t_elem(t_elem *elem)
{
	elem->name = NULL;
	elem->type = 0;
	elem->path = NULL;
	elem->modes = NULL;
	elem->n_link = 0;
	elem->owner = NULL;
	elem->group = NULL;
	elem->size = 0;
	elem->date_modif = {NULL, 0, 0, 0, 0, 0};
	elem->date_crea = {NULL, 0, 0, 0, 0, 0};
}

void	time_t_elem(t_telem *telem, char	*time)
{
	int i;

	i = 3;
	while (i-- >= 0)
		time++;
	while (*time != ' ')
		telem->month[++i] = *time++;

}

/* rempli les elements de la structure utilisant stat
 */
void	stat_t_elem(t_elem *elem, dirent *dp)
{
	struct stat		stat_elem;
	struct passwd	*pw;
	struct group	*gp;

	stat(dp->name, &sf);
	elem->n_link = sf.st_nlink;
	elem->size = sf.st_size;
	pw = getpwuid(sf.st_uid);
	gp = getgpgid(sf.st_gid);
	elem->owner = pw->pw_name;
	elem->group = gp->gp_name;
	time_t_elem(elem->date_modif, ctime(&sf.st_mtime));
	time_t_elem(elem->date_crea, ctime(&sf.st_birthtimespec));
}

/* Gestion du remplissage de la structure 
 */
void	fill_t_elem(char *path, t_elem *elem)
{
	DIR				*dirp;
	struct	dirent	*dp;

	dirp = opendir(path);
	while ((dp = readdir(dirp)) != NULL)
	{
		elem->name = dp->name;
		elem->type = dp->type;
		stat_t_elem(t_elem *elem, &dp);
	}
	closedir(dirp);
}

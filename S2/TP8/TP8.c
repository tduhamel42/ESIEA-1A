/**
 * File              : TP8.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 03.05.2019
 * Last Modified Date: 03.05.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>

int		*allocation_tab_dyn(int n)
{
  return (malloc(sizeof(int) * n));
}

void		chargement_tab(int n, int *tab)
{
  for (int i = 0; i < n; i++)
    scanf("%d", &tab[i]);
}

void		affichage_tab(int n, int *tab)
{
  for (int i = 0; i < n; i++)
    printf("%d ", *(tab + i));
  printf("\n");
}

int		**alloc_mat_dyn(int nbl, int nbc)
{
  int		**mat;

  if ((mat = malloc(sizeof(int *) * nbl)) == NULL)
    return (NULL);
  for (int i = 0; i < nbl; i++)
    {
      if ((mat[i] = malloc(sizeof(int) * nbc)) == NULL)
	return (NULL);
    }
  return (mat);
}

void		chargement_mat(int nbl, int nbc, int **mat)
{
  for (int y = 0; y < nbl; y++)
    {
      for (int x = 0; x < nbc; x++)
	scanf("%d", &mat[y][x]);
    }
}

void		affichage_mat(int nbl, int nbc, int **mat)
{
  for (int i = 0; i < nbl; i++)
    affichage_tab(nbc, mat[i]);
}

void		lib_mat(int nbl, int **mat)
{
  for (int i = 0; i < nbl; i++)
    free(mat[i]);
  free(mat);
}

int		main()
{
  int		n, nbl, nbc;
  int		*tab, **mat;

  scanf("%d", &n);
  if ((tab = allocation_tab_dyn(n)) == NULL)
    return (1);
  chargement_tab(n, tab);
  affichage_tab(n, tab);
  free(tab);
  scanf("%d %d", &nbl, &nbc);
  if ((mat = alloc_mat_dyn(nbl, nbc)) == NULL)
    return (1);
  chargement_mat(nbl, nbc, mat);
  affichage_mat(nbl, nbc, mat);
  lib_mat(nbl, mat);
  return (0);
}

/**
 * File              : TP7.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 18.04.2019
 * Last Modified Date: 18.04.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void		chargement_mat(int nbl, int nbc, int mat[nbl][nbc])
{
  for (int y = 0; y < nbl; y++)
    {
      for (int x = 0; x < nbc; x++)
	{
	  scanf("%d", &mat[y][x]);
	}
    }
}

void		affichage_mat(int nbl, int nbc, int mat[nbl][nbc])
{
  for (int y = 0; y < nbl; y++)
    {
      for (int x = 0; x < nbc; x++)
	{
	  printf("%d ", mat[y][x]);
	}
      printf("\n");
    }
}

int		min(int a, int b)
{
  return (a < b ? a : b);
}

int		min3(int a, int b, int c)
{
  return (min(a, min(b, c)));
}

int		plus_grand_sous_carre(int nbl, int nbc, int mat[nbl][nbc])
{
  int		max = 1;
  int		tmp[nbl][nbc];

  for (int i = 0; i < nbl; i++)
    tmp[i][0] = 1;
  for (int i = 0; i < nbc; i++)
    tmp[0][i] = 1;
  for (int y = 1; y < nbl; y++)
    {
      for (int x = 1; x < nbc; x++)
	{
	  if (mat[y][x] == mat[y - 1][x - 1]
	      && mat[y][x] == mat[y][x - 1]
	      && mat[y][x] == mat[y - 1][x])
	    {
	      tmp[y][x] = min3(tmp[y - 1][x - 1], tmp[y - 1][x], tmp[y][x - 1]) + 1;
	      max = tmp[y][x] > max ? tmp[y][x] : max;
	    }
	  else
	    tmp[y][x] = 1;
	}
    }
  return (max);
}

int		plus_grand_sous_carre_2(int nbl, int nbc, int mat[nbl][nbc])
{
  int		max = 1;
  int		tmp[nbl][nbc];
  int		pos[2];
  int		nbr = 0;

  for (int i = 0; i < nbl; i++)
    tmp[i][0] = 1;
  for (int i = 0; i < nbc; i++)
    tmp[0][i] = 1;
  for (int y = 1; y < nbl; y++)
    {
      for (int x = 1; x < nbc; x++)
	{
	  if (mat[y][x] == mat[y - 1][x - 1]
	      && mat[y][x] == mat[y][x - 1]
	      && mat[y][x] == mat[y - 1][x])
	    {
	      tmp[y][x] = min3(tmp[y - 1][x - 1], tmp[y - 1][x], tmp[y][x - 1]) + 1;
	      if (tmp[y][x] > max)
		{
		  max = tmp[y][x];
		  pos[0] = x;
		  pos[1] = y;
		}
	    }
	  else
	    tmp[y][x] = 1;
	}
    }
  printf("Pos = { %d, %d }\n", pos[0], pos[1]);
  for (int y = 1; y < nbl; y++)
    {
      for (int x = 1; x < nbc; x++)
	{
	  if (tmp[y][x] == max)
	    ++nbr;
	}
    }
  printf("Nbr max = %d\n", nbr);
  return (max);
}

void		generation_fic()
{
  int		nbl, nbc;
  int		r;

  dprintf(2, "Taille: ");
  scanf("%d %d", &nbl, &nbc);
  printf("%d %d\n", nbl, nbc);
  for (int y = 0; y < nbl; y++)
    {
      for (int x = 0; x < nbc; x++)
	{
	  r = rand() % 4;
	  if (r == 0)
	    printf("0 ");
	  else
	    printf("1 ");
	}
      printf("\n");
    }
}

void		nbr_de_chaq_ss_car(int nbl, int nbc, int mat[nbl][nbc], int l_max)
{
  int		tmp[nbl][nbc];
  int		nbrs[l_max];

  for (int i = 0; i < nbl; i++)
    tmp[i][0] = 1;
  for (int i = 0; i < nbc; i++)
    tmp[0][i] = 1;
  for (int y = 1; y < nbl; y++)
    {
      for (int x = 1; x < nbc; x++)
	{
	  if (mat[y][x] == mat[y - 1][x - 1]
	      && mat[y][x] == mat[y][x - 1]
	      && mat[y][x] == mat[y - 1][x])
	    tmp[y][x] = min3(tmp[y - 1][x - 1], tmp[y - 1][x], tmp[y][x - 1]) + 1;
	  else
	    tmp[y][x] = 1;
	}
    }
  for (int i = 0; i < l_max; i++)
    nbrs[i] = 0;
  for (int y = 1; y < nbl; y++)
    {
      for (int x = 1; x < nbc; x++)
	{
	  if (tmp[y][x] <= l_max)
	    ++nbrs[tmp[y][x] - 1];
	}
    }
  for (int i = 0; i < l_max; i++)
    printf("%d -> %d\n", i + 1, nbrs[i]);
}

int		main()
{
  int		nbl, nbc, l_max;

  srand(time(NULL));
  scanf("%d %d", &nbl, &nbc);
  int		mat[nbl][nbc];
  chargement_mat(nbl, nbc, mat);
  affichage_mat(nbl, nbc, mat);
  //printf("%d\n", plus_grand_sous_carre_2(nbl, nbc, mat));
  nbr_de_chaq_ss_car(nbl, nbc, mat, plus_grand_sous_carre(nbl, nbc, mat));
  //generation_fic();
  return (0);
}

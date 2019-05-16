/**
 * File              : TP4.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 29.03.2019
 * Last Modified Date: 29.03.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>

void		AFFICHAGE_TAB(int n, int tab[])
{
  for (int i = 0; i < n; i++)
    printf("%d, ", tab[i]);
  printf("\n");
}

int		PARTITION_LOMUTO(int g, int d, int tab[])
{
  int		x = tab[d];
  int		i = g - 1;
  int		tmp;

  for (int j = g; j < d; j++)
    {
      if (tab[j] <= x)
	{
	  ++i;
	  tmp = tab[i];
	  tab[i] = tab[j];
	  tab[j] = tmp;
	}
    }
  tmp = tab[d];
  tab[d] = tab[i + 1];
  tab[i + 1] = tmp;
  return (i + 1);
}

int		PARTITION_LOMUTO_D_G(int g, int d, int tab[])
{
  int		x = tab[g];
  int		i = d + 1;
  int		tmp;

  for (int j = d; j >= g; j--)
    {
      if (tab[j] > x)
	{
	  --i;
	  tmp = tab[i];
	  tab[i] = tab[j];
	  tab[j] = tmp;
	}
    }
  tmp = tab[g];
  tab[g] = tab[i - 1];
  tab[i - 1] = tmp;
  return (i - 1);
}

int		PARTITION_HOARE(int g, int d, int tab[])
{
  int		x = tab[g];
  int		i = g - 1;
  int		j = d + 1;
  int		tmp;

  while (1)
    {
      do 
	{
	  --j;
	} while (tab[j] > x);
      do 
	{
	  ++i;
	} while (tab[i] < x);
      if (i < j)
	{
	  tmp = tab[i];
	  tab[i] = tab[j];
	  tab[j] = tmp;
	}
      else
	return (j);
    }
}

void		TRI_RAPIDE(int g, int d, int tab[])
{
  if (g >= d)
    return ;
  int		m = PARTITION_LOMUTO_D_G(g, d, tab);
  TRI_RAPIDE(g, m - 1, tab);
  TRI_RAPIDE(m + 1, d, tab);
}


void		TRI_RAPIDE_2(int g, int d, int tab[])
{
  if (g >= d)
    return ;
  int		m = PARTITION_HOARE(g, d, tab);
  TRI_RAPIDE(g, m, tab);
  TRI_RAPIDE(m + 1, d, tab);
}

int		main()
{
  /*int		tab[] = { 12, 23, 6, 5, 13, 9, 8, 5, 20, 3, 7, 11 };
  int		tab2[] = { 12, 23, 6, 5, 13, 9, 8, 5, 20, 3, 7, 11 };*/
  /*int		tab[] = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
  int		tab2[] = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};*/
  int		tab[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  int		tab2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

  /*AFFICHAGE_TAB(12, tab);
  printf("RET = %d\n", PARTITION_LOMUTO(0, 11, tab));
  AFFICHAGE_TAB(12, tab);*/

  /*AFFICHAGE_TAB(12, tab);
  TRI_RAPIDE(0, 11, tab);
  AFFICHAGE_TAB(12, tab);*/
  AFFICHAGE_TAB(20, tab2);
  TRI_RAPIDE(0, 19, tab2);
  AFFICHAGE_TAB(20, tab2);
  AFFICHAGE_TAB(20, tab);
  TRI_RAPIDE_2(0, 19, tab);
  AFFICHAGE_TAB(20, tab);
  return (0);
}

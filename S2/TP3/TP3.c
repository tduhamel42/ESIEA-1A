/**
 * File              : TP3.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 22.03.2019
 * Last Modified Date: 22.03.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>

double		Racine_carree(double n, double e)
{
  double	a = 0, b = n, m;

  while ((b - a) > e)
    {
      m = (b + a) / 2;
      if (m * m < n)
	a = m;
      else
	b = m;
    }
  return (a);
}

int		min_TAB(int n, int TAB[])
{
  int		min = TAB[0];

  for (int i = 1; i < n; i++)
    {
      if (TAB[i] < min)
	min = TAB[i];
    }
  return (min);
}

void		print_tab(int n, int TAB[])
{
  printf("[");
  for (int i = 0; i < n - 1; i++)
    printf("%d, ", TAB[i]);
  printf("%d]", TAB[n - 1]);
}

void		Determ_Nbre_Seq(int n, int TAB[])
{
  int i = 1, j = 0, nbr_ss = 1, D_gss = 0, F_gss = 0;

  while (i < n)
    {
      ++j;
      if (TAB[i] < TAB[i - 1])
	{
	  ++nbr_ss;
	  if (j > (F_gss - D_gss))
	    {
	      D_gss = i - j;
	      F_gss = i - 1;
	    }
	   j = 0;
	}
      ++i;
    }
  printf("Nombre de Sequences: %d\nPlus Grosse Sequence: debut = %d, fin = %d\n", nbr_ss, D_gss, F_gss == 0 ? n - 1 : F_gss);
}

int		Recherche_Dicho(int n, int TAB[], int ELT)
{
  int		g = 0, d = n, m;

  while (d >= g)
    {
      m = (d + g) / 2;
      if (ELT < TAB[m])
	d = m - 1;
      else
	g = m + 1;
      if (TAB[m] == ELT)
	return (m);
    }
  return (-1);
}

int		main()
{
  int		n = 10;
  int		TAB[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  printf("Racine_carree(%lf) = %lf\n", 4.0f, Racine_carree(4.0f, 0.1f));
  printf("min_TAB(%d, ", n);
  print_tab(n, TAB);
  printf(") = %d\n", min_TAB(n, TAB));
  Determ_Nbre_Seq(n, TAB);
  printf("Recherche_Dicho(%d, ", n);
  print_tab(n, TAB);
  printf(", %d) = %d\n", 10, Recherche_Dicho(n, TAB, 10));
  return (0);
}

/**
 * File              : TP2.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 15.03.2019
 * Last Modified Date: 15.03.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long long		fibonacci_rec(unsigned long long n)
{
  if (n == 0 || n == 1)
    return (n);
  return (fibonacci_rec(n - 2) + fibonacci_rec(n - 1));
}

unsigned long long		fibonacci_iter(unsigned long long n)
{
  unsigned long long		nb = 0, nb_2 = 0, nb_1 = 1;

  if (n == 0 || n == 1)
    return (n);
  for (unsigned long long i = 2; i <= n; i++)
    {
      nb = nb_2 + nb_1;
      nb_2 = nb_1;
      nb_1 = nb;
    }
  return (nb);
}

unsigned long long	g_e_mod_n_rec(unsigned int g, unsigned int e,
				      unsigned int n, unsigned long long acc)
{
  if (e == 1)
    return ((g * acc) % n);
  return (g_e_mod_n_rec(g, e - 1, n, (g * acc) % n));
}

unsigned long long	g_e_mod_n_iter(unsigned int g, unsigned int e,
				      unsigned int n)
{
  unsigned long long	nb = g;

  for (int i = 1; i < e; i++)
    {
      nb = nb * g % n;
    }
  return (nb % n);
}

unsigned long long	left_right()
{
  unsigned long long	g, e, n, e_mod, ex;
  int			len;

  scanf("%llu %llu %llu", &g, &e, &n);
  scanf("%d", &len);
  char		bin[len];
  scanf("%s", bin);

  e_mod = 1;
  ex = g;
  printf("%llu %llu %llu %s\n", g, e, n, bin);
  for (int i = 0; i < len; i++)
    {
      if (bin[i] == '1')
	e_mod = e_mod * ex % n;
      ex = (unsigned long long) pow(ex, 2) % n;
    }
  return (e_mod);
}

int			ebp(char str[])
{
  int			i = 0;
  int			a = 0;

  while (str[i])
    {
      if (str[i] == '(')
	a++;
      else if (str[i] == ')')
	a--;
      if (a < 0)
	return (0);
      ++i;
    }
  return (1);
}

int			main(int argc, char **argv)
{
  unsigned long long	g, e, n;

  /*while (scanf("%llu", &n) != EOF)
    {
      printf("fibonacci_rec(%llu) = %llu\n", n, fibonacci_rec(n));
      printf("fibonacci_iter(%llu) = %llu\n", n, fibonacci_iter(n));
    }*/
  g = abs(atoi(argv[1]));
  e = abs(atoi(argv[2]));
  n = abs(atoi(argv[3]));
  printf("%llu^%llu mod %llu = %llu\n", g, e, n, g_e_mod_n_rec(g, e, n, 1));
  printf("%llu^%llu mod %llu = %llu\n", g, e, n, g_e_mod_n_iter(g, e, n));
  //printf("left_right = %llu", left_right());
  /*char str[10];
  scanf("%s", str);
  printf("%d\n", ebp(str));*/
  return (0);
}

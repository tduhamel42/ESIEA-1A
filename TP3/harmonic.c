/**
 * File              : harmonic.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 11.10.2018
 * Last Modified Date: 11.10.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>

int		main()
{
  int		ret, nbr;
  double	res = 0, i;

  do
    {
      printf("Rank of the Harmonic serie ? ");
      if ((ret = scanf("%d", &nbr)) != 1)
	{
	  printf("Input error\n");
	  return (-1);
	}
    } while (nbr <= 0);

  for (i = 1; i < nbr; i++)
    {
      res += 1 / i;
      printf("1/%0.lf + ", i); // Pourquoi %.0lf ? Parce qu'on veut afficher que la partie entiere
    }
  res += 1 / i;
  printf("1/%0.lf = %lf", i, res);
  return (0);
}

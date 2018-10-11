/**
 * File              : pyramide.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 11.10.2018
 * Last Modified Date: 11.10.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>

int	main()
{
  int	nbr;

  do
    {
      if (scanf("%d", &nbr) != 1)
	{
	  printf("Input error\n");
	  return (-1);
	}
    } while (nbr <= 0);

  for (int y = 0; y < nbr; y++)
    {
      for (int i = 0; i < (nbr * y) / nbr; i++)
	printf(" ");
      for (int x = 0; x < ((nbr * 2) - 1) - (y * 2); x++)
	{
	  printf("*");
	}
      printf("\n");
    }
  return (0);
}

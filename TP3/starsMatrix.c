/**
 * File              : starsMatrix.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 11.10.2018
 * Last Modified Date: 11.10.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

# define LINE_SIZE 60

int	main()
{
  int	nbr;
  int	rand_num;

  srand(time(NULL)); // Juste pour pas toujours avoir les memes nombres randoms
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
      for (int x = 0; x < LINE_SIZE; x++)
	{
	  if ((rand() % 5) == 3) // Generation d'un nombre random entre 0 et 5 si il est == a 3 alors * sinon espace
	    printf("*");
	  else
	    printf(" ");
	}
      printf("\n");
    }
  return (0);
}

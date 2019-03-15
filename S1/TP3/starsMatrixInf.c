/**
 * File              : starsMatrixInf.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 11.10.2018
 * Last Modified Date: 11.10.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

/*
** Si vous le savez pas deja c'est CTRL+C pour arreter le programme
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

# define LINE_SIZE 60

int	main()
{
  for (;;)
    {
      for (int x = 0; x < LINE_SIZE; x++)
	{
	  if ((rand() % 5) == 3) // Generation d'un nombre random entre 0 et 5 si il est == a 3 alors * sinon espace
	    printf("*");
	  else
	    printf(" ");
	}
      printf("\n");
      usleep(100000); // On attend un peu pour le style
    }
  return (0);
}

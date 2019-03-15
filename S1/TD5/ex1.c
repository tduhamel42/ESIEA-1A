/**
 * File              : ex1.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 11.10.2018
 * Last Modified Date: 11.10.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>

int	main()
{
  int	col, line;

  scanf("%d %d", &line, &col);
  for (int i = 0; i < line; i++)
    {
      for (int j = 0; j < col; j++)
	{
	  printf("*");
	}
      printf("\n");
    }
  return (0);
}

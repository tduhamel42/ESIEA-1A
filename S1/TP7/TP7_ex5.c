/**
 * File              : TP7_ex5.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 15.11.2018
 * Last Modified Date: 15.11.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>

void		getMinMax(int size, int iArray[], int *p_min, int *p_max)
{
  int		i;

  (*p_min) = iArray[0]; (*p_max) = iArray[0];
  for (i = 1; i < size; i++)
    {
      if (iArray[i] < (*p_min))
	(*p_min) = iArray[i];
      else
	{
	  if (iArray[i] > (*p_max))
	    (*p_max) = iArray[i];
	}
    }
}

int		main()
{
  int		iArray[10] = {9, 6, 10, 12, 9, 3, 5, 12, -4, 8};
  int		min = 0, max = 0;

  printf("Min = %d, Max = %d\n", min, max);
  getMinMax(10, iArray, &min, &max);
  printf("Min = %d, Max = %d\n", min, max);
  return (0);
}

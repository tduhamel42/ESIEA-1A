/**
 * File              : TP7_ex10.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 15.11.2018
 * Last Modified Date: 15.11.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>

void		getMinMaxIndex(int size, int iArray[], int *p_max_index, int *p_min_index)
{
  int		i, min, max;

  (*p_min_index) = 0; min = 0; (*p_max_index) = 0, max = 0;
  for (i = 1; i < size; i++)
    {
      if (iArray[i] < min)
	{
	  (*p_min_index) = i;
	  min = iArray[i];
	}
      else
	{
	  if (iArray[i] > max)
	    {
	      (*p_max_index) = i;
	      max = iArray[i];
	    }
	}
    }
}

void		getFirstIndexOfValue(int size, int iArray[], int value, int *p_index)
{
  for (int i = 0; i < size; i++)
    {
      if (iArray[i] == value)
	{
	  *p_index = i;
	  return ;
	}
    }
}

int		main()
{
  int		iArray[10] = {9, 6, 10, 12, 9, 3, 5, 12, -4, 8};
  int		min_index = 0, max_index = 0, index;

  getMinMaxIndex(10, iArray, &min_index, &max_index);
  printf("IndexMin = %d, IndexMax = %d\n", min_index, max_index);
  getFirstIndexOfValue(10, iArray, 12, &index);
  printf("Index of %d = %d\n", 12, index);
  return (0);
}

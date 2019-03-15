/**
 * File              : mean.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 25.10.2018
 * Last Modified Date: 25.10.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>

void		loadArray(int size, int iArray[])
{
  int		ret = 0, nbr;

  printf("Please enter %d integers:\n", size);
  for (int i = 0; i < size; i++)
    {
      ret = scanf("%d", &nbr);
      if (ret == -1)
	{
	  printf("Input Error\n");
	  exit(-1);
	}
      iArray[i] = nbr;
    }
}

void		showArray(int size, int iArray[])
{
  for (int i = 0; i < size; i++)
    printf("%d%s", iArray[i], i != size - 1 ? " " : "");
  printf("\n");
}

double		getMean(int size, int iArray[])
{
  double	sum = 0;

  for (int i = 0; i < size; i++)
    sum += iArray[i];
  return (sum / (double)size);
}

int		main()
{
  int		array[10];

  loadArray(10, array);
  showArray(10, array);
  printf("The mean of the elements equals: %lf\n", getMean(10, array));
  return (0);
}

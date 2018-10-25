/**
 * File              : minmaxmode.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 25.10.2018
 * Last Modified Date: 25.10.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int		getMax(int size, int iArray[])
{
  int		max = iArray[0];

  for (int i = 0; i < size; i++)
    {
      if (iArray[i] > max)
	max = iArray[i];
    }
  return (max);
}

int		getMin(int size, int iArray[])
{
  int		min = iArray[0];

  for (int i = 0; i < size; i++)
    {
      if (iArray[i] < min)
	min = iArray[i];
    }
  return (min);
}

int		getMaxIndex(int size, int iArray[])
{
  int		max = getMax(size, iArray);

  for (int i = 0; i < size; i++)
    {
      if (iArray[i] == max)
	return (i);
    }
  return (0);
}

int		getMinIndex(int size, int iArray[])
{
  int		min = getMin(size, iArray);

  for (int i = 0; i < size; i++)
    {
      if (iArray[i] == min)
	return (i);
    }
  return (0);
}

int		nbrOccurence(int nbr, int size, int iArray[])
{
  int		n = 0;

  for (int i = 0; i < size; i++)
    {
      if (iArray[i] == nbr)
	++n;
    }
  return (n);
}

int		getMode(int size, int iArray[])
{
  int		mode;
  int		occurenceArray[size];

  memset(occurenceArray, 0, size * sizeof(int));
  for (int i = 0; i < size; i++)
    occurenceArray[iArray[i]] = nbrOccurence(iArray[i], size, iArray);
  showArray(size, occurenceArray);
  return (getMaxIndex(size, occurenceArray));
}

int		main()
{
  int		array[10];

  loadArray(10, array);
  showArray(10, array);
  printf("The max is: %d\n", getMax(10, array));
  printf("The min is: %d\n", getMin(10, array));
  printf("The (first) max is at: %d\n", getMaxIndex(10, array));
  printf("The (first) min is at: %d\n", getMinIndex(10, array));
  printf("The mode of the array is: %d\n", getMode(10, array));
  return (0);
}

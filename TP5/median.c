/**
 * File              : median.c
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

int		swap(int iArray[], int index1, int index2)
{
  int		tmp = iArray[index1];

  iArray[index1] = iArray[index2];
  iArray[index2] = tmp;
}

void		bubbleSort(int size, int iArray[])
{
  int		is_sorted;

  do
    {
      is_sorted = 1;
      for (int i = 0; i < size - 1; i++)
	{
	  if (iArray[i] > iArray[i + 1])
	    {
	      swap(iArray, i, i + 1);
	      is_sorted = 0;
	    }
	}
    } while (!is_sorted);
}

int		getMedian(int size, int iArray[])
{
  bubbleSort(size, iArray);
  return (iArray[size / 2]);
}

int		main()
{
  int		array[10];

  loadArray(10, array);
  printf("BEFORE: ");
  showArray(10, array);
  bubbleSort(10, array);
  printf("AFTER: ");
  showArray(10, array);
  printf("The median of the array is: %d\n", getMedian(10, array));
  return (0);
}

/**
 * File              : TD12.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 04.12.2018
 * Last Modified Date: 04.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdlib.h>
#include <stdio.h>

void		initArray(int nbLin, int nbCol, int iArray[nbLin][nbCol])
{
  int		k = 1;

  for (int y = 0; y < nbLin; y++)
    {
      for (int x = 0; x < nbCol; x++)
	{
	  iArray[y][x] = k++;
	}
    }
}

void		showArray(int nbLin, int nbCol, int iArray[nbLin][nbCol])
{
  for (int y = 0; y < nbLin; y++)
    {
      for (int x = 0; x < nbCol; x++)
	{
	  printf("%3d ", iArray[y][x]);
	}
      printf("\n");
    }
}

void		loadArray(int nbLin, int nbCol, int iArray[nbLin][nbCol])
{
  int		tmp;

  for (int y = 0; y < nbLin; y++)
    {
      for (int x = 0; x < nbCol; x++)
	{
	  scanf("%d", &tmp);
	  iArray[y][x] = tmp;
	}
    }
}

int		getSumOfFourNeighbors(int nbLin, int nbCol, int iArray[nbLin][nbCol], int eltLin, int eltCol)
{
  int		sum = 0;

  sum += eltCol - 1 >= 0 ? iArray[eltLin][eltCol - 1] : 0;
  sum += eltCol + 1 < nbCol ? iArray[eltLin][eltCol + 1] : 0;
  sum += eltLin + 1 < nbLin ? iArray[eltLin + 1][eltCol] : 0;
  sum += eltLin - 1 >= 0 ? iArray[eltLin - 1][eltCol] : 0;
  return (sum);
}

int		getSumOfEightNeighbors(int nbLin, int nbCol, int iArray[nbLin][nbCol], int eltLin, int eltCol)
{
  int		sum = getSumOfFourNeighbors(nbLin, nbCol, iArray, eltLin, eltCol);

  sum += eltCol - 1 >= 0 && eltLin - 1 >= 0 ? iArray[eltLin - 1][eltCol - 1] : 0;
  sum += eltCol + 1 < nbCol && eltLin - 1 >= 0 ? iArray[eltLin - 1][eltCol + 1] : 0;
  sum += eltCol - 1 >= 0 && eltLin + 1 < nbLin ? iArray[eltLin + 1][eltCol - 1] : 0;
  sum += eltCol + 1 < nbCol && eltLin + 1 < nbLin ? iArray[eltLin + 1][eltCol + 1] : 0;
  return (sum);
}

int		main(int argc, char **argv)
{
  int		width = atoi(argv[1]), height = atoi(argv[2]);
  int		tab[height][height];
  int		x = 0, y = 0;

  initArray(height, width, tab);
  showArray(height, width, tab);
  loadArray(height, width, tab);
  showArray(height, width, tab);
  printf("At (%d, %d) -> Four: %d, Eight: %d\n", x, y, getSumOfFourNeighbors(height, width, tab, y, x), getSumOfEightNeighbors(height, width, tab, y, x));
  return (0);
}

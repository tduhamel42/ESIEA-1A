/**
 * File              : TP5.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 05.04.2019
 * Last Modified Date: 05.04.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

void		REMPLISSAGE_TAB(int N, int TAB[])
{
  for (int i = 0; i < N; i++)
    TAB[i] = rand() % 100;
}

void		AFFICHAGE_TAB(int N, int TAB[])
{
  for (int i = 0; i < N; i++)
    printf("%d ", TAB[i]);
  printf("\n");
}

/*
void		FUSION(int N, int TAB[], int a, int m, int b)
{
  int		tmp[N];

  printf("BEFORE ");
  AFFICHAGE_TAB(N, TAB);
  printf("m = %d a = %d b = %d\n", m, a, b);
  if (TAB[a] >= TAB[m + 1])
    {
      printf("TAB[m + 1] = %d, A = %d\n", TAB[m + 1], ((b - (m + 1)) + 1));
      memcpy(tmp, &TAB[m + 1], ((b - (m + 1)) + 1) * sizeof(int));
      memcpy(tmp + (m + 1), &TAB[a], (m + 1) * sizeof(int));
      AFFICHAGE_TAB(b - a, tmp);
      printf("DONE A\n");
    }
  else
    {
      printf("B = %d\n", ((b - (m + 1)) + 1));
      memcpy(tmp, &TAB[a], (m + 1) * sizeof(int));
      memcpy(tmp + (m + 1), &TAB[m + 1], (b - (m + 1)) * sizeof(int));
      AFFICHAGE_TAB(b, tmp);
      printf("DONE B\n");
    }
  memcpy(&TAB[a], tmp, b * sizeof(int));
  printf("AFTER ");
  AFFICHAGE_TAB(N, TAB);
}
*/

void		FUSION(int N, int TAB[], int a, int m, int b)
{
  int		i = a, j = m + 1, k = 0, l, TEMP[b - a + 1];

  while (i <= m && j <= b)
    {
      if (TAB[i] < TAB[j])
	TEMP[k] = TAB[i++];
      else
	TEMP[k] = TAB[j++];
      ++k;
    }
  while (i <= m)
    TEMP[k++] = TAB[i++];
  while (j <= b)
    TEMP[k++] = TAB[j++];

  k = 0;
  for (i = a; i <= b; i++)
    TAB[i] = TEMP[k++];
}

void		TRI_FUSION(int N, int TAB[], int a, int b)
{
  if (a != b)
    {
      TRI_FUSION(N, TAB, a, (a + b) / 2);
      TRI_FUSION(N, TAB, ((a + b) / 2) +  1, b);
      FUSION(N, TAB, a, (a + b) / 2, b);
    }
}

int		main()
{
  int		size = 10;
  int		TAB[size];

  srand(time(NULL));
  REMPLISSAGE_TAB(size, TAB);
  AFFICHAGE_TAB(size, TAB);
  TRI_FUSION(size, TAB, 0, 9);
  AFFICHAGE_TAB(size, TAB);
}

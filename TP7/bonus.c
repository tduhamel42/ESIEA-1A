/**
 * File              : bonus.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 16.11.2018
 * Last Modified Date: 16.11.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void		rand_tab(int size, int tab[])
{
  for (int i = 0; i < size; i++)
    tab[i] = rand() % 100;
}

void		show_tab(int size, int tab[])
{
  for (int i = 0; i < size; i++)
    printf("%p ", &tab[i]);
  printf("\n");
  for (int i = 0; i < size; i++)
    printf("%2d ", i);
  printf("\n");
  for (int i = 0; i < size; i++)
    printf("%2d ", tab[i]);
  printf("\n");
}

void		bonus(int size, int tab[], int *index, int *len)
{
  int		tmp_index = 0;
  int		tmp_len = 1;

  *index = 0;
  *len = 0;
  for (int i = 0; i < size - 1; i++)
    {
      if (tab[i] < tab[i + 1])
	{
	  if (!tmp_index)
	    tmp_index = i;
	  ++tmp_len;
	}
      else
	{
	  if (tmp_len > *len)
	    {
	      *index = tmp_index;
	      *len = tmp_len;
	    }
	  tmp_index = 0;
	  tmp_len = 1;
	}
    }
  if (tmp_len > *len)
    {
      *index = tmp_index;
      *len = tmp_len;
    }
}

int		main(int argc, char **argv)
{
  int		size = atoi(argv[1]);
  int		tab[size], index, len;

  srand(time(NULL));
  rand_tab(size, tab);
  show_tab(size, tab);
  bonus(size, tab, &index, &len);
  printf("Index: %d, Len: %d\n", index, len);
  return (0);
}

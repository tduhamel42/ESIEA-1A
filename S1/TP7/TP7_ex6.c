/**
 * File              : TP7_ex6.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 15.11.2018
 * Last Modified Date: 15.11.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>

void		swap(int *a, int *b)
{
  int		tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

int		main()
{
  int		a = 42, b = 84;

  printf("a = %d, b = %d\n", a, b);
  swap(&a, &b);
  printf("a = %d, b = %d\n", a, b);
  return (0);
}

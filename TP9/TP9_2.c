/**
 * File              : TP9_2.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 30.11.2018
 * Last Modified Date: 30.11.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>

int	main()
{
  double   dSum = 0;
  int    i;
  for (i = 0; i < 10; i ++)
    {
      dSum += 0.1;
    }
  printf("dSum = %lf\n ", dSum);
  if (dSum  == 1.0)
    {
      printf("The continum of reality is safe.\n");
    }
  else
    {
      printf("Nothing makes sense anymore... are we in the matrix ?\n");
    }
  printf("0.1 = %.20lf\n", 0.1);
  printf("1.0 − dSum = %.20lf\n", 1.0 - dSum);
  return  0;
}

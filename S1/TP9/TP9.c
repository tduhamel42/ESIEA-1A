/**
 * File              : TP9.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 30.11.2018
 * Last Modified Date: 30.11.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>

# define PI 3.1415926535897932384626L

int		main()
{
  float		fVar = PI;
  double	dVar = PI;
  long double	ldVar = PI;

  printf("fVar = %f\n", fVar);
  printf("dVar = %lf\n", dVar);
  printf("ldVar = %Lf\n", ldVar);
  printf("%.20f %.20lf %.20Lf\n", fVar, dVar, ldVar);
  return (0);
}


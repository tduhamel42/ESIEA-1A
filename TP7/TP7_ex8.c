/**
 * File              : TP7_ex8.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 15.11.2018
 * Last Modified Date: 15.11.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>

void		addToInteger1(int integer1, int integer2)
{
  printf("1/ integer1 = %d integer2 = %d\n", integer1, integer2);
  integer1 += integer2;
  printf("1/ integer1 = %d integer2 = %d\n", integer1, integer2);
}

void		addToInteger2(int var1, int var2)
{
  printf("2/ var1 = %d var2 = %d\n", var1, var2);
  var1 += var2;
  printf("2/ var1 = %d var2 = %d\n", var1, var2);
}

void		addToInteger3(int *p_integer1, int *p_integer2)
{
  printf("3/ (*p_integer1) = %d (*p_integer2) = %d\n", (*p_integer1), (*p_integer2));
  (*p_integer1) += (*p_integer2);
  printf("3/ (*p_integer1) = %d (*p_integer2) = %d\n", (*p_integer1), (*p_integer2));
}

int		main()
{
  int		var1, var2;

  var1 = var2 = 2;
  printf("m/ var1 = %d var2 = %d\n", var1, var2);
  addToInteger1(var1, var2);
  printf("m/ var1 = %d var2 = %d\n", var1, var2);
  addToInteger2(var1, var2);
  printf("m/ var1 = %d var2 = %d\n", var1, var2);
  addToInteger3(&var1, &var2);
  printf("m/ var1 = %d var2 = %d\n", var1, var2);
  return (0);
}

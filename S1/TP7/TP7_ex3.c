/**
 * File              : TP7_ex2.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 15.11.2018
 * Last Modified Date: 15.11.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>

int		main()
{
  int		var = 7;
  int		tmp;
  int		*p_var = &var;

  printf("var = %d, (*p_var) = %d\n", var, (*p_var));
  tmp = (*p_var) + 5;
  printf("var = %d, (*p_var) = %d, tmp = %d\n", var, (*p_var), tmp);
  (*p_var) = tmp;
  printf("var = %d, (*p_var) = %d, tmp = %d\n", var, (*p_var), tmp);
  return (0);
}

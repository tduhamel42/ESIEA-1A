/**
 * File              : TP7.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 15.11.2018
 * Last Modified Date: 15.11.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>

int		main()
{
  int		iVar;
  double	fVar;
  char		cVar;
  int		*p_iVar = NULL;
  double	*p_fVar = NULL;
  char		*p_cVar = NULL;

  printf("The value of &iVar is %p and  p_iVar is %p.\n", &iVar, p_iVar);
  printf("The value of &fVar is %p and  p_iVar is %p.\n", &fVar, p_fVar);
  printf("The value of &cVar is %p and  p_cVar is %p.\n", &cVar, p_cVar);
  p_iVar = &iVar;
  p_fVar = &fVar;
  p_cVar = &cVar;
  printf("The value of &iVar is %p and  p_iVar is %p.\n", &iVar, p_iVar);
  printf("The value of &fVar is %p and  p_iVar is %p.\n", &fVar, p_fVar);
  printf("The value of &cVar is %p and  p_cVar is %p.\n", &cVar, p_cVar);
  return (0);
}

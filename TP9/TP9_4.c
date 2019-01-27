/**
 * File              : TP9_4.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 30.11.2018
 * Last Modified Date: 30.11.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>

int	main()
{
  unsigned  long  long llVal = 0xFFFFFFFFFFFFFFFF;
  unsigned  int iVal = llVal;
  unsigned  short sVal = iVal;
  unsigned  char cVal = sVal;
  printf("llVal = %016llx  %llu\n", llVal, llVal);
  printf("iVal = %016x  %u\n", iVal , iVal);
  printf("sVal = %016x  %u\n", sVal , sVal);
  printf("cVal = %016x  %u\n", cVal , cVal);

  int	val = -12;
  unsigned int uVal = val;
  printf("uVal = %u\n", uVal);
  return 0;
}

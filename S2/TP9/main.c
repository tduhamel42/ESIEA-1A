/**
 * File              : main.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 10.05.2019
 * Last Modified Date: 10.05.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include "fonctions.h"

int		main(int argc, char **argv)
{
  if (argc > 1)
    conduite(argv[1]);
  return (0);
}

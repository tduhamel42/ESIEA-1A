/**
 * File              : fonctions.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 10.05.2019
 * Last Modified Date: 10.05.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>
#include "fonctions.h"

void		avancer(int action)
{
  printf("%s", action ? "Avancer\n" : "");
}

void		reculer(int action)
{
  printf("%s", action ? "Reculer\n" : "");
}

void		tourner_d(int action)
{
  printf("%s", action ? "Tourner à droite\n" : "");
}

void		tourner_g(int action)
{
  printf("%s", action ? "Tourner à gauche\n" : "");
}

void		conduite(char *filename)
{
  FILE		*f;
  int		actions[4];

  if ((f = fopen(filename, "r")) == NULL)
    return ;
  while (fscanf(f, "%d %d %d %d", &actions[0],
		&actions[1],
		&actions[2],
		&actions[3]) != EOF)
    {
      avancer(actions[0]);
      reculer(actions[1]);
      tourner_d(actions[2]);
      tourner_g(actions[3]);
    }
}

/**
 * File              : game.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 11.10.2018
 * Last Modified Date: 11.10.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

/*
** Correction
** Fais le sans regarder c'est mieux
** Si t'as des questions faut pas hesiter
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define PLAYER_HP 100
# define MAX_PLAYER_DAMMAGE 15
# define MAX_MONSTER_HP 30
# define MAX_MONSTER_DAMMAGE 5

int	fight(char *name, int life) // prend le nom et les pv en parametre et les retourne a la fin
{
  int	monster_hp = rand() % MAX_MONSTER_HP;
  int	dammage_player, dammage_monster;

  printf("%s you are under attack !!!!\n", name);
  while (monster_hp > 0)
    {
      dammage_player = rand() % MAX_PLAYER_DAMMAGE;
      monster_hp -= dammage_player;
      printf("You attacked and did %d dammage to the monster. The monster has %d hp.\n", dammage_player, monster_hp);

      dammage_monster = rand() % MAX_MONSTER_DAMMAGE;
      life -= dammage_monster;
      printf("You took %d dammage !! You have %d hp.\n", dammage_monster, life);
      if (life <= 0)
	return (life);
    }
  return (life);
}

int	turn(char *name, int life, char *cmd)
{
  int	rand_nbr; // nombre random

  printf("Well done %s, you are going %s\n", name, cmd);
  if ((rand_nbr = rand() % 10) == 5)
    life = fight(name, life);
  return (life);
}

int	main()
{
  char	cmd[10]; // string pour les commandes
  char	name[10]; // string pour le nom du joueur
  int	life = PLAYER_HP; // vie du joueur
  
  printf("What's your name ? ");
  scanf("%s", name); // on demande son nom au joueur
  printf("Hello %s !\n", name); // on est poli
  while (life > 0)
    {
      printf("> ");
      scanf("%s", cmd);
      if (!strcmp(cmd, "north") // comparaison de l'entree utilisateur avec les commandes qu'on veut
	  || !strcmp(cmd, "south")
	  || !strcmp(cmd, "east")
	  || !strcmp(cmd, "west"))
	life = turn(name, life, cmd);
      else
	printf("Unknown command !!\n");
    }
  printf("Sadly %s died\n", name);
  return (0);
}

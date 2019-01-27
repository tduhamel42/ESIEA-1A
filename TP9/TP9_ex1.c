/**
 * File              : TP9_ex1.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 30.11.2018
 * Last Modified Date: 30.11.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

int		rocketTest(short oldAltitude, short newAltitude)
{
  printf("oldAltitude: %d, newAltitude: %d\n", oldAltitude, newAltitude);
  if (oldAltitude < newAltitude || oldAltitude == newAltitude)
    return (1);
  printf("Falling!\n");
  return (0);
}

int		rocketTestMagic(short oldAltitude, short newAltitude)
{
  if (oldAltitude < newAltitude || oldAltitude == newAltitude)
    return (1);
  return (0);
}

void		runLoop(int speed)
{
  int		altitude = 0, oldAltitude = 0;

  while (altitude <= 300000)
    {
      printf("Actual altitude: %d, ", altitude);
      if (!rocketTest(oldAltitude, altitude))
	{
	  printf("Boom !\n");
	  break ;
	}
      oldAltitude = altitude;
      altitude += speed;
    }
}

void		print_rocket(int x, int y, char c)
{
  printf("\033[%d;%dH%c", y, x, c);
  for (int i = 1; i < 5; i++)
    printf("\033[%d;%dH%c", y, x + i, c);
  for (int j = 0; j < 4; j++)
    {
      for (int i = 1; i < 4; i++)
	printf("\033[%d;%dH%c", y - j, x + i, c);
    }
  printf("\033[%d;%dH%c", y - 4, x + 2, c);
}

void		print_smoke(int x, int y, int old_y)
{
  printf(GRN);
  for (int i = 1; i < 5; i++)
    for (int j = 0; j < 5; j++)
      {
	printf("\033[%d;%dH \n", old_y + i, x + j);
      }
  for (int i = 1; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
	{
	  if (rand() % 5 == 3)
	    printf("\033[%d;%dH*\n", y + i, x + j);
	}
    }
  printf(RESET);
}

void		explode_rocket(int x, int y)
{
  int		i = 0, n_x, n_y;

  printf(RED);
  print_rocket(x, y, ' ');
  while (i < 100)
    {
      n_x = rand() % 8;
      n_y = rand() % 8;
      printf("\033[%d;%dH%c\n", y - n_y, x + n_x, 35 + (rand() % 12));
      usleep(10000);
      printf("\033[%d;%dH \n", y - n_y, x + n_x);
      ++i;
    }
  printf(RESET);
}

void		runLoopMagic(int speed)
{
  int		altitude = 0, oldAltitude = 0;
  int		y = 40, old_y = 40, x = 50;

  system("clear");
  while (altitude <= 300000)
    {
      print_rocket(x, old_y, ' ');
      if (!rocketTestMagic(oldAltitude, altitude))
	{
	  print_smoke(x, y, old_y);
	  explode_rocket(x, y);
	  break ;
	}
      print_rocket(x, y, '#');
      print_smoke(x, y, old_y);
      usleep(80000);
      oldAltitude = altitude;
      altitude += speed;
      old_y = y;
      --y;
      printf("\n");
    }
  printf("\033[41;0H\n");
}

int		main()
{
  runLoopMagic(1000);
  return (0);
}

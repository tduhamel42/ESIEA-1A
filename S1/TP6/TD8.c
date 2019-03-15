/**
 * File              : TD8.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 08.11.2018
 * Last Modified Date: 08.11.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <string.h>
#include <stdio.h>

int		lenght(char str[])
{
  int		i = 0;

  while (str[i])
    ++i;
  return (i);
}

int		digits(char str[])
{
  int		i = 0, nbr = 0;

  while (str[i])
    {
      if (str[i] >= '0' && str[i] <= '9')
	++nbr;
      ++i;
    }
  return (nbr);
}

int		characters(char str[])
{
  int		i = 0, nbr = 0;

  while (str[i])
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	++nbr;
      ++i;
    }
  return (nbr);
}

int		espace(char str[])
{
  int		i = 0, nbr = 0;

  while (str[i])
    {
      if (str[i] == ' ')
	++nbr;
      ++i;
    }
  return (nbr);
}

void		reverse(char str[])
{
  int		i = 0, j = strlen(str) - 1;
  char		tmp;

  while (i < j)
    {
      tmp = str[i];
      str[i] = str[j];
      str[j] = tmp;
      ++i;
      --j;
    }
}

int		find(char str[], char c)
{
  int		i = 0;

  while (str[i])
    {
      if (str[i] == c)
	return (i);
      ++i;
    }
  return (-1);
}

int		count(char str[], char c)
{
  int		i = 0, nbr = 0;

  while (str[i])
    {
      if (str[i] == c)
	++nbr;
      ++i;
    }
  return (nbr);
}

int		main()
{
  char		str[] = "Hello world123";

  printf("Len: %d\n", lenght(str));
  printf("Digits: %d\n", digits(str));
  printf("Characters: %d\n", characters(str));
  printf("Espace: %d\n", espace(str));
  reverse(str);
  printf("Reverse: %s\n", str);
  printf("Find: %d\n", find(str, 'l'));
  printf("Count: %d\n", count(str, 'l'));
  return (0);
}

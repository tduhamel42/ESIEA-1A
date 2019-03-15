/**
 * File              : TP6.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 08.11.2018
 * Last Modified Date: 08.11.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void		loadWord(char word[])
{
  printf("Please enter a word (50 char max): ");
  if (scanf("%50s", word) != 1)
    {
      printf("Error\n");
      exit(-1);
    }
}

void		loadSentence(char sentence[])
{
  printf("Please enter a sentence (50 char max): ");
  if (scanf("\n%50[^\n]", sentence) != 1)
    {
      printf("Error\n");
      exit(-1);
    }
}

void		toUpperCase(char str[])
{
  int		i = 0;

  while (str[i])
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	str[i] = str[i] - 32;
      ++i;
    }
}

void		toLowerCase(char str[])
{
  int		i = 0;

  while (str[i])
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	str[i] = str[i] + 32;
      ++i;
    }
}

void		mirror(char str[])
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

int		main()
{
  char		word[51];
  char		sentence[51];

  loadWord(word);
  printf("You have entered the word: %s\n", word);
  loadSentence(sentence);
  printf("You have entered the sentence: %s\n", sentence);
  toUpperCase(sentence);
  printf("UpperCase: %s\n", sentence);
  toLowerCase(sentence);
  printf("LowerCase: %s\n", sentence);
  mirror(sentence);
  printf("Mirror: %s\n", sentence);
  return (0);
}

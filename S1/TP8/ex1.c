/**
 * File              : ex1.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 20.11.2018
 * Last Modified Date: 24.11.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void		reverse(char str[])
{
  int		i = 0, j = strlen(str) - 1;
  char		tmp;

  while (i < j)
    {
      tmp = str[i];
      str[i] = str[j];
      str[j] = tmp;
      --j;
      ++i;
    }
}

void		decimal_to_binary_horner(unsigned int nbr, char str[])
{
  int		div = nbr, mod = 0, i = 0;

  while (div != 0)
    {
      mod = div % 2;
      div = div / 2;
      str[i++] = mod + 48;
    }
  while (i < 3)
    str[i++] = '0';
  str[i] = 0;
  reverse(str);
}

int		get_max_power(int nbr, int base)
{
  int		max_power = 0, i = 1;

  while (max_power <= nbr)
    max_power = pow(base, i++);
  return (i - 2);
}

void		decimal_to_binary_power(unsigned int nbr, char str[])
{
  int		r = nbr, max_power = get_max_power(nbr, 2);

  while (r != 0)
    {
      max_power = get_max_power(r, 2);
      str[max_power] = '1';
      r -= pow(2, max_power); 
    }
  max_power = get_max_power(nbr, 2);
  str[max_power + 1] = 0;
  reverse(str);
}

void		decimal_to_octal_horner(unsigned int nbr, char str[])
{
  int		div = nbr, mod = 0, i = 0;

  while (div != 0)
    {
      mod = div % 8;
      div = div / 8;
      str[i++] = mod + 48;
    }
  str[i] = 0;
  reverse(str);
}

void		decimal_to_octal_power(unsigned int nbr, char str[])
{
  int		r = nbr, max_power = get_max_power(nbr, 8);
  int		res = 0;

  while (r != 0)
    {
      max_power = log(r) / log(8);
      res = r / pow(8, max_power);
      str[max_power] = res + 48;
      r -= res * pow(8, max_power); 
    }
  max_power = get_max_power(nbr, 2);
  str[max_power + 1] = 0;
  reverse(str);
}

void		decimal_to_hexa(unsigned int nbr, char str[])
{
  int		div = nbr, mod = 0, i = 0;

  while (div != 0)
    {
      mod = div % 16;
      div = div / 16;
      switch (mod)
	{
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
	  str[i++] = mod + ('a' - 10);
	  break;
	default:
	  str[i++] = mod + 48;
	}
    }
  str[i] = 0;
  reverse(str);
}

void		binary_to_decimal(char str[], unsigned int *nbr)
{
  int		i = 0;

  *nbr = 0;
  reverse(str);
  while (str[i])
    {
      if (str[i] == '1')
	{
	  *nbr += pow(2, i);
	}
      ++i;
    }
}

void		get_nbr_base(char str[], unsigned int *res)
{
  int		i = 0;

  *res = 0;
  while (str[i] >= '0' && str[i] <= '9')
    {
      *res = (*res * 10) + str[i] - 48;
      ++i;
    }
}

void		binary_to_octal(char str[], unsigned int *nbr)
{
  *nbr = 0;
  binary_to_decimal(str, nbr);
  bzero(str, strlen(str) - 1);
  decimal_to_octal_horner(*nbr, str);
  get_nbr_base(str, nbr);
}

void		binary_to_hexa(char str[], char res[])
{
  unsigned int	nbr;

  nbr = 0;
  binary_to_decimal(str, &nbr);
  decimal_to_hexa(nbr, res);
}

void		octal_to_decimal(char str[], unsigned int *nbr)
{
  char		tmp[2];
  int		i = 0;
  char		bin[33];
  char		decimal[33];

  bzero(decimal, 33);
  bzero(bin, 33);
  while (str[i])
    {
      tmp[0] = str[i];
      tmp[1] = 0;
      get_nbr_base(tmp, nbr);
      decimal_to_binary_horner(*nbr, bin);
      strcat(decimal, bin);
      ++i;
    }
  binary_to_decimal(decimal, nbr);
}

void		octal_to_hexa(char str[], char res[])
{
  unsigned int	nbr = 0;

  octal_to_decimal(str, &nbr);
  decimal_to_hexa(nbr, res);
}

void		hexa_to_decimal(char str[], unsigned int *nbr)
{
}

int		main(int argc, char **argv)
{
  unsigned int	onbr = atoi(argv[1]), nbr = onbr;
  char		str[33];
  char		res[33];

  // Decimal -> Binary
  decimal_to_binary_horner(nbr, str);
  printf("2 Horner: %d = %s\n", nbr, str);
  memset(str, '0', 31);
  str[32] = 0;
  decimal_to_binary_power(nbr, str);
  printf("2 Power: %d = %s\n", nbr, str);

  // Decimal -> Octal
  decimal_to_octal_horner(nbr, str);
  printf("8 Horner: %d = %s\n", nbr, str);
  bzero(str, 33);
  decimal_to_octal_power(nbr, str);
  printf("8 Power: %d = %s\n", nbr, str);

  // Decimal -> Hexa
  bzero(str, 33);
  decimal_to_hexa(nbr, str);
  printf("16 Horner: %d = 0x%s\n", nbr, str);

  // Decimal -> Binary
  bzero(str, 33);
  decimal_to_binary_horner(nbr, str);
  binary_to_decimal(strdup(str), &nbr);
  printf("Bin %s = %d decimal\n", str, nbr);

  // Decimal -> Octal
  bzero(str, 33);
  decimal_to_binary_horner(nbr, str);
  binary_to_octal(strdup(str), &nbr);
  printf("Bin %s = %d octal\n", str, nbr);

  // Binary -> Hexa
  bzero(str, 33);
  bzero(res, 33);
  nbr = onbr;
  decimal_to_binary_horner(nbr, str);
  binary_to_hexa(strdup(str), res);
  printf("Bin %s = 0x%s hexa\n", str, res);

  // Octal -> Decimal
  bzero(str, 33);
  nbr = onbr;
  decimal_to_octal_horner(nbr, str);
  octal_to_decimal(strdup(str), &nbr);
  printf("Octal %s = %d decimal\n", str, nbr);
  
  // Octal -> Hexa
  bzero(str, 33);
  bzero(res, 33);
  nbr = onbr;
  decimal_to_octal_horner(nbr, str);
  octal_to_hexa(strdup(str), res);
  printf("Octal %s = 0x%s hexa\n", str, res);
  return (0);
}

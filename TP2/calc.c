/**
 * File              : calc.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 05.10.2018
 * Last Modified Date: 05.10.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>

static	int	add(int a, int b)
{
  return (a + b);
}

static	int	sub(int a, int b)
{
  return (a - b);
}

static	int	mul(int a, int b)
{
  return (a * b);
}

static	int	div(int a, int b)
{
  return (a / b);
}

static	int	mod(int a, int b)
{
  return (a % b);
}


int	main()
{
  char	op;
  int	a, b;

  printf("Enter num1 operator num2: ");
  scanf("%d %c %d", &a, &op, &b);

  switch(op)
    {
    case '+':
      printf("%d %c %d = %d", a, op, b, add(a, b));
      break;
    case '-':
      printf("%d %c %d = %d", a, op, b, sub(a, b));
      break;
    case '*':
      printf("%d %c %d = %d", a, op, b, mul(a, b));
      break;
    case '/':
      if (b == 0)
	printf("Division par 0 !!");
      else
	printf("%d %c %d = %d", a, op, b, div(a, b));
      break;
    case '%':
      if (b == 0)
	printf("Division par 0 !!");
      else
	printf("%d %c %d = %d", a, op, b, mod(a, b));
      break;
    }
  return (0);
}

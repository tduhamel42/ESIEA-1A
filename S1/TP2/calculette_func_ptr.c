/** * File              : calculette.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 05.10.2018
 * Last Modified Date: 05.10.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>

typedef int	(*t_func)(int a, int b);

typedef struct	s_funcs
{
  char		op;
  t_func	func;
}		t_funcs;

static int	add(int a, int b)
{
  return (a + b);
}

static int	sub(int a, int b)
{
  return (a - b);
}

static int	mul(int a, int b)
{
  return (a * b);
}

static int	div(int a, int b)
{
  return (a / b);
}

static int	mod(int a, int b)
{
  return (a % b);
}

static t_funcs funcs[] = 
{
    { '+', add },
    { '-', sub },
    { '*', mul },
    { '/', div },
    { '%', mod },
    { 0, NULL }
};

int	main()
{
  int	a, b, i = 0;
  char	op;

  printf("Enter num1 operator num2: ");
  scanf("%d %c %d", &a, &op, &b);
  while (funcs[i].op)
    {
      if (funcs[i].op == op)
	printf("%d %c %d = %d\n", a, op, b, funcs[i].func(a, b));
      ++i;
    }
  return (0);
}


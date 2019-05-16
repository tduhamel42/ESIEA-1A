/**
 * File              : TP6.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 11.04.2019
 * Last Modified Date: 11.04.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

# define NBR_DRINKS 6

typedef struct		s_drink
{
  char			name[32];
  double		price;
}			t_drink;

t_drink			drinks[] = {
    { "Café court", 0.70 },
    { "Café long", 0.80 },
    { "Café au lait", 0.60 },
    { "Chocolat", 0.50 },
    { "Lait", 0.50 },
    { "Thé au miel", 1.40 },
};

int			is_dispo(double monnaie_dispo[], double somme)
{
  for (int i = 0; i < 10; i++)
    {
      if (fabs(monnaie_dispo[i] - somme) < 0.00001)
	return (i);
    }
  return (-1);
}

void			affichage_boissons()
{
  printf("╔══════════════════╦══════╦═════╗\n");
  printf("║    BOISSONS      ║ PRIX ║CHOIX║\n");
  printf("╠══════════════════╬══════╬═════╣\n");
  for (int i = 0; i < NBR_DRINKS; i++)
    printf("║ %-*s ║ %.2f ║ %3d ║\n", strlen(drinks[i].name) < 10 ? 16 : 17, drinks[i].name, drinks[i].price, i);
  printf("╚══════════════════╩══════╩═════╝\n");
} 

void			achat_boisson(double monnaie_dispo[], int choix, double somme)
{
  int			i = 9;
  int			monnaie_choisi[10] = { 0 }; 

  somme -= drinks[choix].price;
  printf("La monnaie a rendre est de : %.2lf\n", somme);
  while (i >= 0 && somme != 0)
    {
      while (somme >= monnaie_dispo[i] || fabs(somme - monnaie_dispo[i]) < 0.001)
	{
	  monnaie_choisi[i] += 1; 
	  somme -= monnaie_dispo[i];
	}
      --i;
    }
  for (int i = 9; i >= 0; i--)
    {
      if (monnaie_choisi[i] > 0)
	printf("%d x %.2lf\n", monnaie_choisi[i], monnaie_dispo[i]);
    }
  printf("Votre boisson est prête !!!\n");
}

void			achat_boisson_2(double monnaie_dispo[], int nb_pieces[], int choix, double somme)
{
  int			i = 9;
  int			monnaie_choisi[10] = { 0 }; 

  somme -= drinks[choix].price;
  printf("La monnaie a rendre est de : %.2lf\n", somme);
  while (i >= 0 && somme != 0)
    {
      while ((somme >= monnaie_dispo[i] || fabs(somme - monnaie_dispo[i]) < 0.001) && nb_pieces[i] > 0)
	{
	  monnaie_choisi[i] += 1; 
	  nb_pieces[i] -= 1; 
	  somme -= monnaie_dispo[i];
	}
      --i;
    }
  if (somme > 0)
    {
      printf("Le distributeur ne dispose pas d'assez de pièces pour vous rendre la monnaie\n");
      return ;
    }
  for (int i = 9; i >= 0; i--)
    {
      if (monnaie_choisi[i] > 0)
	printf("%d x %.2lf\n", monnaie_choisi[i], monnaie_dispo[i]);
    }
  printf("Votre boisson est prête !!!\n");
}

void			achat_boisson_3(double monnaie_dispo[], int nb_pieces[], int choix, double somme, double pref)
{
  int			i = 9;
  int			j = is_dispo(monnaie_dispo, pref);
  int			monnaie_choisi[10] = { 0 }; 

  somme -= drinks[choix].price;
  printf("La monnaie a rendre est de : %.2lf\n", somme);
  while ((somme >= monnaie_dispo[j] || fabs(somme - monnaie_dispo[j]) < 0.001) && nb_pieces[j] > 0)
    {
      monnaie_choisi[j] += 1; 
      nb_pieces[j] -= 1; 
      somme -= monnaie_dispo[j];
    }
  while (i >= 0 && somme != 0)
    {
      while ((somme >= monnaie_dispo[i] || fabs(somme - monnaie_dispo[i]) < 0.001) && nb_pieces[i] > 0)
	{
	  monnaie_choisi[i] += 1; 
	  nb_pieces[i] -= 1; 
	  somme -= monnaie_dispo[i];
	}
      --i;
    }
  if (somme >= 0.01)
    {
      printf("Le distributeur ne dispose pas d'assez de pièces pour vous rendre la monnaie\n");
      return ;
    }
  for (int i = 9; i >= 0; i--)
    {
      if (monnaie_choisi[i] > 0)
	printf("%d x %.2lf\n", monnaie_choisi[i], monnaie_dispo[i]);
    }
  printf("Votre '%s' est prêt !!!\n", drinks[choix].name);
}

int			main()
{
  int			choix;
  double		somme;
  double		pref;
  double		monnaie_dispo[] = { 0.01, 0.02, 0.05, 0.10, 0.20, 0.5, 1, 2, 5, 10 };
  int			nb_pieces[] = { 50, 50, 5, 50, 5, 3, 3, 10, 3, 1 };

  affichage_boissons();
  do
    {
      printf("Quel est votre choix ? (tapez '10' pour quitter)\n");
      scanf("%d", &choix);
      if (choix == 10)
	break;
      printf("Donner votre montant : ");
      scanf("%lf", &somme);
      printf("Quelle est votre pièce ou billet préféré dans la monnaie ? : ");
      scanf("%lf", &pref);
      if (choix < NBR_DRINKS
	  && somme >= drinks[choix].price
	  && is_dispo(monnaie_dispo, pref) != -1)
	achat_boisson_3(monnaie_dispo, nb_pieces, choix, somme, pref);
      else
	printf("ATTENTION : le montant donné est inférieur au prix indiqué / montant pas accepté !!!\n");
    } while (choix != 10);
  return (0);
}

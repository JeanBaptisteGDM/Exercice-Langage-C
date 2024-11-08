/*L'objectif est de faire deviner un nombre à l'utilisateur.

1. Créer le nombre que le joueur devra determiner.
 Ce nombre est censé changer à chaque nouvelle partie (c'est un nombre aleatoire) : voir bibliothèque Math.h
2. Proposer 3 niveaux de difficultés : Facile (30 coups) / Moyen (20 coups) / Difficile (10 coups) / Expert (5 coups).
 Le nombre de coups représente le nombre de tentatives que le joueur a pour trouver le nombre.
3. Regles du jeu : on demande à l'utilisateur de choisir un niveau. Une fois cela fait, on lui demande de deviner le nombre.
 Si sa proposition est plus élevée que le nombre on affiche le message : C'est moins, sinon on affiche C'est plus.
 Quand l'utilisateur trouve le nombre, on affiche bravo, vous avez gagné la partie en x coups, x représente le nombre de coups qu'il lui a fallu pour gagner.
  A chaque mauvaise réponse , on reduit son nombre de coups et à 0 on affichera : Vous avez perdu. Il aura la possibilité de rejouer ou de quitter le jeu dans ce cas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    const int MIN = 1;
    int max = 100;
    srand(time(NULL));

    // Déclaration de variables du jeu
    int nombreMystere, niveauDeJeu, nombreDeTentativesMax, nombreDeTentativesRestantes, nombreSaisi;
    int rejouer = 0;

    do {

        // Choix du niveau
        printf("Bienvenue dans le jeu Devine moi si tu peux.\nVotre objectif est de trouver un nombre mystere en un minimum de coups.\n");
        printf("Taper 1 pour le niveau facile (30 coups) \n");
        printf("Taper 2 pour le niveau moyen (20 coups) \n");
        printf("Taper 3 poyr le niveau niveau difficile (10 coups) \n");
        printf("Taper 4 pour le niveau expert (5 coups) \n");

        do {
            printf("Choisissez votre niveau : ");
            scanf_s("%d", &niveauDeJeu);
            switch (niveauDeJeu) {
            case 1:
                nombreDeTentativesMax = 30;
                printf("Vous avez choisi le niveau facile\n\n");
                break;
            case 2:
                nombreDeTentativesMax = 20;
                printf("Vous avez choisi le niveau moyen\n\n");
                break;
            case 3:
                nombreDeTentativesMax = 10;
                printf("Vous avez choisi le niveau difficile\n\n");
                break;
            case 4:
                nombreDeTentativesMax = 5;
                printf("Vous avez choisi le niveau expert\n\n");
                break;
            default:
                printf("Vous avez entrer un nombre incorrect\n\n");
                break;
            }
        } while (niveauDeJeu < 1 || niveauDeJeu > 4);


        nombreMystere = rand() % (max - MIN + 1) + MIN;
        nombreDeTentativesRestantes = nombreDeTentativesMax;

        // La partie continue tant que l'utilisateur a encore des tentatives possibles


        do {
            printf("Vous avez %d coups\n", nombreDeTentativesRestantes);
            printf("Veuillez saisir le nombre a deviner : ");
            scanf_s("%d", &nombreSaisi);
            printf("\n");

            if (nombreSaisi > nombreMystere) {
                printf("C'est moins!!!\n");
            }
            else if (nombreSaisi < nombreMystere) {
                printf("C'est plus!!!\n");
            }
            else {
                printf("Bravo. Vous avez gagne la partie en %d coups\n\n", nombreDeTentativesMax - nombreDeTentativesRestantes);
            }
            nombreDeTentativesRestantes--;
        } while (nombreSaisi != nombreMystere && nombreDeTentativesRestantes > 0);

        if (nombreDeTentativesRestantes == 0) {
            printf("Vous avez perdu !!! \nLe nombre a deviner etais : %d\n\n", nombreMystere);
        }

        printf("Voulez vous rejouer ?\n");
        printf("Taper 1 : Pour OUI\n");
        printf("taper 2 : Pour NON\n");

        do {
            printf("entrer un nombre :");
            scanf_s("%d\n", &rejouer);
        } while (rejouer < 1 || rejouer > 2);

    } while (rejouer == 1);


    return 0;
}

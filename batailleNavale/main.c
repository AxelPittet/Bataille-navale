/**
 * Libraries
 */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

/**
 * Permet d'afficher les caractères spéciaux
 */
#pragma set_character_execution

/**
 * \project: Bataille navale
 * \author: Axel Pittet
 * \version: version 1.0 du 27.02.2020
 */

/**
 * Constantes
 */
#define NOMBRE_COLONNES 10
#define NOMBRE_LIGNES 10

#define COLONNE_BATEAU5 1
#define LIGNE1_BATEAU5 3
#define LIGNE2_BATEAU5 4
#define LIGNE3_BATEAU5 5
#define LIGNE4_BATEAU5 6
#define LIGNE5_BATEAU5 7

#define COLONNE1_BATEAU4 5
#define COLONNE2_BATEAU4 6
#define COLONNE3_BATEAU4 7
#define COLONNE4_BATEAU4 8
#define LIGNE_BATEAU4 9

#define COLONNE1_BATEAU3A 3
#define COLONNE2_BATEAU3A 4
#define COLONNE3_BATEAU3A 5
#define LIGNE_BATEAU3A 1

#define COLONNE1_BATEAU3B 5
#define COLONNE2_BATEAU3B 6
#define COLONNE3_BATEAU3B 7
#define LIGNE_BATEAU3B 6

#define COLONNE_BATEAU2 5
#define LIGNE1_BATEAU2 3
#define LIGNE2_BATEAU2 4

/**
 * Initioalisations
 */
char carte[NOMBRE_COLONNES][NOMBRE_LIGNES], cibleLigne, b, choixLogin[3] = {0}, pseudo[10] = {0}, verifierPseudo[10] = {
        0}, pseudo2[10] = {0}, anciensPseudos[] = {0}, afficherPseudoBest[10] = {0};
int choixMenu, cibleColonne, bateau5, bateau4, bateau3A, bateau3B, bateau2, win, connection, nbEspaces, nbCarac = 0
, score = 0, caractereActuel = 0, ancienScore, afficherScoreBest[10] = {0}, afficherScoreActuel[10] = {0};

/**
 * Fonction servant à réinitialiser la console
 */
void clear() {
    system("cls");
}

/**
 * Fonction servant à éviter une fermeture brusque
 */
void pause() {
    system("pause");
}

/**
 * Fonction servant à afficher le titre
 */
void afficherTitre() {
    printf("                       .:°       | |\n");
    printf("                   ___|____      | |\n");
    printf("                  / ° ° ° /      | |\n");
    printf("           ---------------------------------\n");
    printf("          <=========Bataille Navale=========>\n");
    printf("            <=============================>\n");
    printf("              <=========================>\n\n");

}

/**
 * Fonction servant à afficher les différents choix du menu
 */
void afficherChoixMenu() {
    printf("                     1 - Jouer\n");
    printf("                     2 - Règles\n");
    printf("                     3 - Scores\n");
    printf("                     4 - Quitter\n\n");
}

/**
 * Fonction servant a demander à l'utilisateur quelle fonctionnalité du menu il veut utiliser
 */
void demanderChoixMenu() {
    printf("                       Choix: ");

    fflush(stdin);
    scanf("%d", &choixMenu);
}

/**
 * Fonction servant à afficher les élements nécessaires lorsque le choix était de quitter
 */
void quitter() {
    clear();

    afficherTitre();

    printf("\n                À une prochaine fois!\n\n\n\n");
    printf("     ");
    pause();
}

/**
 * Fonction servant à afficher les règles
 */
void regles() {
    clear();

    printf("                        Règles\n\n");
    printf("  Sur la carte il y a :      Un bateau de 5 cases\n");
    printf("                             Un bateau de 4 cases\n");
    printf("                             Deux bateaux de 4 cases\n");
    printf("                             Un bateau de 2 cases\n\n");

    printf("  Le joueur doit tirer des obus sur des cases de la carte\n  pour essayer de toucher un bateau\n");
    printf("  Un bateau est touché quand un obus aterrit sur une\n  des cases du bateau.\n");
    printf("  Un bateau est coulé quand toutes ses cases sont touchées.\n");
    printf("  Une partie se termine quand un joueur coule tout les\n  bateaux adverses\n\n");

    printf("                  ");

    pause();
}

/**
 * Fonction servant à donner les valeurs nécessaires à la carte
 */
void remplirCarte() {

    for (int i = 0; i < 10; i++) {
        for (int a = 0; a < 10; a++) {
            carte[i][a] = ' ';
        }
    }
}

/**
 * Fonction servant à afficher la carte
 */
void afficherCarte() {
    printf("    1  2  3  4  5  6  7  8  9  10\n");

    for (int i = 0, b = 'A'; i < 10, b < 'K'; i++, b++) {
        printf(" %c ", b);
        for (int a = 0; a < 10; a++) {
            printf("[%c]", carte[a][i]);
        }
        printf("\n");
    }
}

/**
 * Fonction servant à afficher les indicatins de jeu
 */
void indicationsJeu() {
    printf("  - = tir dans l'eau\n");
    printf("  X = tir touché\n");
    printf("  C = bateau coulé\n\n\n");
}

/**
 * Fonction servant à demander où l'utilisateur veut tirer
 */
void tirer() {
    printf("   Colonne de la cible : ");
    fflush(stdin);
    scanf("%d", &cibleColonne);

    printf("   Ligne de la cible : ");
    fflush(stdin);
    scanf("%c", &cibleLigne);
}

/**
 * Fonction servant à convertir les donnés reçues afin de pouvoir les utiliser dans le tableau (carte)
 */
void convertirTir() {

    if ((cibleLigne >= 'a') && (cibleLigne <= 'j')) {
        cibleLigne -= 97;
    } else if ((cibleLigne >= 'A') && (cibleLigne <= 'J')) {
        cibleLigne -= 65;
    }
    cibleColonne -= 1;
}

/**
 * Fonction servant à savoir si le tir touche un bateau, le coule ou est dans l'eau
 */
void changerValeurCarte() {
    /**
     * Conditions à respecter pour qu'un bateau soit touché
     */
    if (((cibleColonne == COLONNE_BATEAU5) && ((cibleLigne == LIGNE1_BATEAU5) || (cibleLigne == LIGNE2_BATEAU5)
                                               || (cibleLigne == LIGNE3_BATEAU5) || (cibleLigne == LIGNE4_BATEAU5) ||
                                               (cibleLigne == LIGNE5_BATEAU5)))
        || ((cibleLigne == LIGNE_BATEAU4) && ((cibleColonne == COLONNE1_BATEAU4) || (cibleColonne == COLONNE2_BATEAU4)
                                              || (cibleColonne == COLONNE3_BATEAU4) ||
                                              (cibleColonne == COLONNE4_BATEAU4)))
        ||
        ((cibleLigne == LIGNE_BATEAU3A) && ((cibleColonne == COLONNE1_BATEAU3A) || (cibleColonne == COLONNE2_BATEAU3A)
                                            || (cibleColonne == COLONNE3_BATEAU3A)))
        ||
        ((cibleLigne == LIGNE_BATEAU3B) && ((cibleColonne == COLONNE1_BATEAU3B) || (cibleColonne == COLONNE2_BATEAU3B)
                                            || (cibleColonne == COLONNE3_BATEAU3B)))
        || ((cibleColonne == COLONNE_BATEAU2) && ((cibleLigne == LIGNE1_BATEAU2) || (cibleLigne == LIGNE2_BATEAU2)))) {

        carte[cibleColonne][cibleLigne] = 'X';
        score += 7;

        /**
         * Conditions à respecter pour que le bateau de 5 cases soit coulé
         */
        if ((carte[COLONNE_BATEAU5][LIGNE1_BATEAU5] == 'X') && (carte[COLONNE_BATEAU5][LIGNE2_BATEAU5] == 'X')
            && (carte[COLONNE_BATEAU5][LIGNE3_BATEAU5] == 'X') && (carte[COLONNE_BATEAU5][LIGNE4_BATEAU5] == 'X')
            && (carte[COLONNE_BATEAU5][LIGNE5_BATEAU5] == 'X')) {

            for (int i = 3; i < 8; i++) {
                carte[COLONNE_BATEAU5][i] = 'C';
            }

            printf("   Coulé\n\n");

            /**
             * Permet de savoir que le bateau de 5 cases est coulé
             */
            bateau5 = 1;

            /**
            * Conditions à respecter pour que le bateau de 4 cases soit coulé
            */
        } else if ((carte[COLONNE1_BATEAU4][LIGNE_BATEAU4] == 'X') && (carte[COLONNE2_BATEAU4][LIGNE_BATEAU4] == 'X')
                   && (carte[COLONNE3_BATEAU4][LIGNE_BATEAU4] == 'X') &&
                   (carte[COLONNE4_BATEAU4][LIGNE_BATEAU4] == 'X')) {

            for (int i = 5; i < 9; i++) {
                carte[i][LIGNE_BATEAU4] = 'C';
            }

            printf("   Coulé\n\n");

            /**
            * Permet de savoir que le bateau de 4 cases est coulé
            */
            bateau4 = 1;

            /**
            * Conditions à respecter pour que le premier bateau de 3 cases soit coulé
            */
        } else if ((carte[COLONNE1_BATEAU3A][LIGNE_BATEAU3A] == 'X') &&
                   (carte[COLONNE2_BATEAU3A][LIGNE_BATEAU3A] == 'X')
                   && (carte[COLONNE3_BATEAU3A][LIGNE_BATEAU3A] == 'X')) {

            for (int i = 3; i < 6; i++) {
                carte[i][LIGNE_BATEAU3A] = 'C';
            }

            printf("   Coulé\n\n");

            /**
            * Permet de savoir que le premier bateau de 3 cases est coulé
            */
            bateau3A = 1;

            /**
            * Conditions à respecter pour que le deuxième bateau de 3 cases soit coulé
            */
        } else if ((carte[COLONNE1_BATEAU3B][LIGNE_BATEAU3B] == 'X') &&
                   (carte[COLONNE2_BATEAU3B][LIGNE_BATEAU3B] == 'X') &&
                   (carte[COLONNE3_BATEAU3B][LIGNE_BATEAU3B] == 'X')) {

            for (int i = 5; i < 8; i++) {
                carte[i][LIGNE_BATEAU3B] = 'C';
            }

            printf("   Coulé\n\n");

            /**
            * Permet de savoir que le dexième bateau de 3 cases est coulé
            */
            bateau3B = 1;

            /**
            * Conditions à respecter pour que le bateau de 2 cases soit coulé
            */
        } else if ((carte[COLONNE_BATEAU2][LIGNE1_BATEAU2] == 'X') && (carte[COLONNE_BATEAU2][LIGNE2_BATEAU2] == 'X')) {

            for (int i = 3; i < 5; i++) {
                carte[COLONNE_BATEAU2][i] = 'C';
            }

            printf("   Coulé !\n\n");

            /**
            * Permet de savoir que le bateau de 2 cases est coulé
            */
            bateau2 = 1;

        } else {
            printf("   Touché !\n\n");
        }

    } else {
        carte[cibleColonne][cibleLigne] = '-';

        printf("   Dans l'eau !\n\n");
    }
    printf("   ");
}

/**
 * Fonction servant à savoir si un tir est valide
 */
void verfierTir() {
    if ((cibleColonne < 0) || (cibleColonne > 9) || (cibleLigne < 0) || (cibleLigne > 9) ||
        (carte[cibleColonne][cibleLigne] == '-') || (carte[cibleColonne][cibleLigne] == 'X') ||
        (carte[cibleColonne][cibleLigne] == 'C')) {
        printf("   Tir non valide\n\n");
    } else {
        changerValeurCarte();
        score -= 1;
    }
}

/**
 * Fonction servant à vérifier si les conditions de victoire sont remplies
 */
void conditionsVictoire() {
    if ((bateau5 == 1) && (bateau4 == 1) && (bateau3A == 1) && (bateau3B == 1) && (bateau2 == 1)) {
        /**
         * Permet de savoir si les conditions sont remplies
         */
        win = 1;
    }
}

/**
 * Fonction servant à s'identifier si l'utilisateur le désire
 */
void Login() {
    do {
        do {
            clear();

            printf("Voulez-vous vous identifier (oui/non): ");
            scanf("%s", &choixLogin);

        } while ((strcmp(choixLogin, "oui") != 0) && (strcmp(choixLogin, "non") != 0));

        if (strcmp(choixLogin, "oui") == 0) {
            do {
                clear();

                printf("Possedez-vous déjà un compte (oui/non): ");
                scanf("%s", &choixLogin);

            } while ((strcmp(choixLogin, "oui") != 0) && (strcmp(choixLogin, "non") != 0));

            clear();

            if (strcmp(choixLogin, "oui") == 0) {

                printf("Quel est votre nom d'utilsateur: ");
                scanf("%s", &pseudo);

                FILE *verificationPseudo = NULL;

                verificationPseudo = fopen("verificationPseudo.txt", "w");

                if (verificationPseudo != NULL) {

                    nbCarac = 0;
                    for (int i = 0; pseudo[i] != 0; i++) {
                        nbCarac++;
                    }
                    nbEspaces = 10 - nbCarac;

                    fprintf(verificationPseudo, "%s", pseudo);

                    for (int i = nbEspaces; i > 0; i--) {
                        fprintf(verificationPseudo, " ");
                    }
                    fclose(verificationPseudo);
                }
                FILE *verificationPseudo2 = NULL;

                verificationPseudo2 = fopen("verificationPseudo.txt", "r");

                if (verificationPseudo2 != NULL) {
                    fgets(pseudo, 11, verificationPseudo2);

                    fclose(verificationPseudo2);
                }

                FILE *pseudos = NULL;

                pseudos = fopen("scores.txt", "r");

                if (pseudos != NULL) {

                    while ((fgets(verifierPseudo, 11, pseudos) != 0) && (strcmp(verifierPseudo, pseudo) != 0)) {

                    }
                    fscanf(pseudos, "%d", &ancienScore);
                    if (strcmp(pseudo, verifierPseudo) != 0) {
                        printf("Ce nom d'utilisateur n'est pas valide\n\n");
                    } else {
                        connection = 1;
                        printf("Connexion réussie !\n");

                    }

                    fclose(pseudos);

                    if (score > ancienScore) {
                        FILE *nouveauScore = NULL;

                        nouveauScore = fopen("scores.txt", "w");

                        if (nouveauScore != 0) {
                            fprintf(nouveauScore, "%d", score);
                        }
                        printf("Votre score a été mis à jour !\n");

                        fclose(nouveauScore);
                    }
                    printf("\n");
                    pause();
                }
            } else {
                do {
                    clear();
                    printf("Création d'un compte(tapez 'annuler' pour reveir en arrière)\n\n");
                    printf("Choississez un nom d'utilsateur : ");
                    scanf("%s", &pseudo);

                    if (strcmp(pseudo, "annuler") != 0) {

                        FILE *adapterPseudo = NULL;

                        adapterPseudo = fopen("verificationPseudo.txt", "w");

                        if (adapterPseudo != NULL) {

                            nbCarac = 0;
                            for (int i = 0; pseudo[i] != 0; i++) {
                                nbCarac++;
                            }
                            nbEspaces = 10 - nbCarac;

                            fprintf(adapterPseudo, "%s", pseudo);

                            for (int i = nbEspaces; i > 0; i--) {
                                fprintf(adapterPseudo, " ");
                            }
                            fclose(adapterPseudo);
                        }
                        FILE *adapterPseudo2 = NULL;

                        adapterPseudo2 = fopen("verificationPseudo.txt", "r");

                        if (adapterPseudo2 != NULL) {

                            fgets(pseudo, 11, adapterPseudo);
                            fscanf(adapterPseudo, "%s", &pseudo);

                            fclose(adapterPseudo2);
                        }
                        FILE *verificationPseudoExisteDeja = NULL;

                        verificationPseudoExisteDeja = fopen("scores.txt", "r");

                        if (verificationPseudoExisteDeja != NULL) {

                            while ((fgets(verifierPseudo, 11, verificationPseudoExisteDeja) != NULL) &&
                                   (strcmp(pseudo, verifierPseudo) != 0)) {

                            }
                            if (strcmp(pseudo, verifierPseudo) == 0) {
                                printf("Ce pseudo est déjà utilisé\n\n");
                            } else {
                                FILE *nouveauPseudo = NULL;

                                nouveauPseudo = fopen("scores.txt", "a");

                                if (nouveauPseudo != 0) {
                                    fseek(nouveauPseudo, 0, SEEK_END);

                                    nbCarac = 0;
                                    for (int i = 0; pseudo[i] != 0; i++) {
                                        nbCarac++;
                                    }
                                    nbEspaces = 10 - nbCarac;

                                    fprintf(nouveauPseudo, "%s", pseudo);

                                    for (int i = nbEspaces; i > 0; i--) {
                                        fprintf(nouveauPseudo, " ");
                                    }
                                    fprintf(nouveauPseudo, "%d\n", score);

                                    printf("Votre compte a été créé!\n\n");
                                    connection = 1;

                                    fclose(nouveauPseudo);
                                }
                            }
                            pause();
                            fclose(verificationPseudoExisteDeja);
                        }
                    }
                } while ((strcmp(pseudo, "annuler") != 0) && (strcmp(pseudo, verifierPseudo) == 0));
            }
        } else {
            connection = 1;
        }
    } while (connection != 1);
}

/**
 * Fonction contenant d'autres fonctions qui réunies permettent de jouer à la bataille navale
 */
void jouer() {
    remplirCarte();

    do {
        clear();

        indicationsJeu();

        afficherCarte();

        tirer();

        convertirTir();

        verfierTir();

        conditionsVictoire();

        pause();
    } while (win != 1);
    clear();

    /**
     * Affichage du message de victoire
     */
    printf(".______   .______           ___      ____    ____   ______      .___________. __    __          ___"
           "           _______      ___        _______ .__   __.  _______     __   __   __  \n"
           "|   _  \\  |   _  \\         /   \\     \\   \\  /   /  /  __  \\     |           ||  |  |  |        /   \\"
           "         /  _____|    /   \\      /  _____||  \\ |  | |   ____|   |  | |  | |  | \n"
           "|  |_)  | |  |_)  |       /  ^  \\     \\   \\/   /  |  |  |  |    `---|  |----`|  |  |  |       /  ^  \\"
           "       |  |  __     /  ^  \\    |  |  __  |   \\|  | |  |__      |  | |  | |  | \n"
           "|   _  <  |      /       /  /_\\  \\     \\      /   |  |  |  |        |  |     |  |  |  |      /  /_\\"
           "  \\      |  | |_ |   /  /_\\  \\   |  | |_ | |  . `  | |   __|     |  | |  | |  | \n"
           "|  |_)  | |  |\\  \\----. /  _____  \\     \\    /    |  `--'  |        |  |     |  `--'  |     /  _____"
           "  \\     |  |__| |  /  _____  \\  |  |__| | |  |\\   | |  |____    |__| |__| |__| \n"
           "|______/  | _| `._____|/__/     \\__\\     \\__/      \\______/         |__|      \\______/     /__/"
           "     \\__\\     \\______| /__/     \\__\\  \\______| |__| \\__| |_______|   (__) (__) (__) \n\n\n\n\n\n\n");

    pause();

    Login();
}

void scores() {
    clear();

    FILE *afficherScores = NULL;

    afficherScores = fopen("scores.txt", "r");

    if (afficherScores != 0) {
        for (int a = 0; a < 10; a++) {
            for (int i = 10; i < 1000; i = i + 10) {
                fseek(afficherScores, +i, SEEK_SET);

                fscanf(afficherScores, "%d", &afficherScoreActuel[a]);

                if ((afficherScoreActuel[a] > afficherScoreBest[a]) &&
                    (afficherScoreActuel[a] != afficherScoreBest[0]) &&
                    (afficherScoreActuel[a] > afficherScoreBest[a]) &&
                    (afficherScoreActuel[a] != afficherScoreBest[1]) &&
                    (afficherScoreActuel[a] > afficherScoreBest[a]) &&
                    (afficherScoreActuel[a] != afficherScoreBest[2]) &&
                    (afficherScoreActuel[a] > afficherScoreBest[a]) &&
                    (afficherScoreActuel[a] != afficherScoreBest[3]) &&
                    (afficherScoreActuel[a] > afficherScoreBest[a]) &&
                    (afficherScoreActuel[a] != afficherScoreBest[4]) &&
                    (afficherScoreActuel[a] > afficherScoreBest[a]) &&
                    (afficherScoreActuel[a] != afficherScoreBest[5]) &&
                    (afficherScoreActuel[a] > afficherScoreBest[a]) &&
                    (afficherScoreActuel[a] != afficherScoreBest[6]) &&
                    (afficherScoreActuel[a] > afficherScoreBest[a]) &&
                    (afficherScoreActuel[a] != afficherScoreBest[7]) &&
                    (afficherScoreActuel[a] > afficherScoreBest[a]) &&
                    (afficherScoreActuel[a] != afficherScoreBest[8]) &&
                    (afficherScoreActuel[a] > afficherScoreBest[a]) &&
                    (afficherScoreActuel[a] != afficherScoreBest[9])) {

                    afficherScoreBest[a] = afficherScoreActuel[a];

                    fseek(afficherScores, -14, SEEK_CUR);
                    fgets(afficherPseudoBest[a], 11, afficherScores);
                }
            }
            printf("%d - %s : %d\n", a + 1, afficherPseudoBest[a], afficherScoreBest[a]);
        }
        fclose(afficherScores);
    }
    pause();
}

int main() {
    /**
     * permet d'afficher les caractères spéciaux
     */
    SetConsoleOutputCP(65001);

    /**
     * Boucle principale revenant toujours au menu tant que le choix n'est pas de quitter
     */
    do {

        clear();

        afficherTitre();

        afficherChoixMenu();

        demanderChoixMenu();

        /**
         * Switch contenant les différentes fonctions
         */
        switch (choixMenu) {
            case 1:
                jouer();
                break;
            case 2:
                regles();

                break;
            case 3:
                scores();
                break;
            case 4:
                quitter();
                break;
        }

    } while (choixMenu != 4);

    return 0;
}

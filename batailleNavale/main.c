#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

#pragma set_character_execution

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

char carte[NOMBRE_COLONNES][NOMBRE_LIGNES], cibleLigne, b;
int choixMenu, cibleColonne;

void clear() {
    system("cls");
}

void pause() {
    system("pause");
}

void afficherTitre() {
    printf("                       .:°       | |\n");
    printf("                   ___|____      | |\n");
    printf("                  / ° ° ° /      | |\n");
    printf("           ---------------------------------\n");
    printf("          <=========Bataille Navale=========>\n");
    printf("            <=============================>\n");
    printf("              <=========================>\n\n");

}

void afficherChoixMenu() {
    printf("                     1 - Jouer\n");
    printf("                     2 - Règles\n");
    printf("                     3 - Scores\n");
    printf("                     4 - Quitter\n\n");
}

void demanderChoixMenu() {
    printf("                       Choix: ");

    fflush(stdin);
    scanf("%d", &choixMenu);
}

void quitter() {
    clear();

    afficherTitre();

    printf("\n                À une prochaine fois!\n\n\n\n");
    printf("     ");
    pause();
}

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

void remplirCarte() {
    for (int i = 0; i < 10; i++) {
        for (int a = 0; a < 10; a++) {
            carte[i][a] = ' ';
        }
    }
}

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

void indicationsJeu() {
    printf("  O = tir dans l'eau\n");
    printf("  X = tir touché\n");
    printf("  C = bateau coulé\n\n\n");
}

void tirer() {
    printf("   Colonne de la cible : ");
    fflush(stdin);
    scanf("%d", &cibleColonne);

    printf("   Ligne de la cible : ");
    fflush(stdin);
    scanf("%c", &cibleLigne);
}

void convertirTir() {
    if ((cibleLigne >= 'a') && (cibleLigne <= 'j')) {
        cibleLigne -= 97;
    } else if ((cibleLigne >= 'A') && (cibleLigne <= 'J')) {
        cibleLigne -= 65;
    }
    cibleColonne -= 1;
}

void changerValeurCarte() {
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

        if ((carte[COLONNE_BATEAU5][LIGNE1_BATEAU5] == 'X') && (carte[COLONNE_BATEAU5][LIGNE2_BATEAU5] == 'X')
            && (carte[COLONNE_BATEAU5][LIGNE3_BATEAU5] == 'X') && (carte[COLONNE_BATEAU5][LIGNE4_BATEAU5] == 'X')
            && (carte[COLONNE_BATEAU5][LIGNE5_BATEAU5] == 'X')) {

            for (int i = 3; i < 8; i++) {
                carte[COLONNE_BATEAU5][i] = 'C';
            }

            printf("   Coulé\n\n");

        } else if ((carte[COLONNE1_BATEAU4][LIGNE_BATEAU4] == 'X') && (carte[COLONNE2_BATEAU4][LIGNE_BATEAU4] == 'X')
                   && (carte[COLONNE3_BATEAU4][LIGNE_BATEAU4] == 'X') &&
                   (carte[COLONNE4_BATEAU4][LIGNE_BATEAU4] == 'X')) {

            for (int i = 5; i < 9; i++) {
                carte[i][LIGNE_BATEAU4] = 'C';
            }

            printf("   Coulé\n\n");

        } else if ((carte[COLONNE1_BATEAU3A][LIGNE_BATEAU3A] == 'X') &&
                   (carte[COLONNE2_BATEAU3A][LIGNE_BATEAU3A] == 'X')
                   && (carte[COLONNE3_BATEAU3A][LIGNE_BATEAU3A] == 'X')) {

            for (int i = 3; i < 6; i++) {
                carte[i][LIGNE_BATEAU3A] = 'C';
            }

            printf("   Coulé\n\n");

        } else if ((carte[COLONNE1_BATEAU3B][LIGNE_BATEAU3B] == 'X') &&
                   (carte[COLONNE2_BATEAU3B][LIGNE_BATEAU3B] == 'X') &&
                   (carte[COLONNE3_BATEAU3B][LIGNE_BATEAU3B] == 'X')) {

            for (int i = 5; i < 8; i++) {
                carte[i][LIGNE_BATEAU3B] = 'C';
            }

            printf("   Coulé\n\n");

        } else if ((carte[COLONNE_BATEAU2][LIGNE1_BATEAU2] == 'X') && (carte[COLONNE_BATEAU2][LIGNE2_BATEAU2] == 'X')) {

            for (int i = 3; i < 5; i++) {
                carte[COLONNE_BATEAU2][i] = 'C';
            }

            printf("   Coulé !\n\n");

        } else {

            printf("   Touché !\n\n");
        }

    } else {
        printf("   Dans l'eau !\n\n");
    }
}

void verfierTir() {
    if ((cibleColonne < 1) || (cibleColonne > 10) || (cibleLigne < 0) || (cibleLigne > 9)) {
        printf("   Tir non valide\n\n");
    } else {
        changerValeurCarte();
    }
}

void jouer() {
    remplirCarte();

    do {
        clear();

        indicationsJeu();

        afficherCarte();

        tirer();

        convertirTir();

        verfierTir();

        pause();
    } while (cibleColonne != 20000000);

}

int main() {

    SetConsoleOutputCP(65001);

    do {

        clear();

        afficherTitre();

        afficherChoixMenu();

        demanderChoixMenu();

        switch (choixMenu) {
            case 1:
                jouer();
                break;
            case 2:
                regles();

                break;
            case 3:

                break;
            case 4:
                quitter();
                break;
        }

    } while (choixMenu != 4);

    return 0;
}

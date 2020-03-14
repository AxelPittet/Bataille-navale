#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

#pragma set_character_execution

#define NOMBRE_COLONNES 10
#define NOMBRE_LIGNES 10

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
    printf(" Chaque joueur possède:      Un bateau de 5 cases\n");
    printf("                             Un bateau de 4 cases\n");
    printf("                             Deux bateaux de 4 cases\n");
    printf("                             Un bateau de 2 cases\n\n");

    printf(" Chacun son tour chaque joueur tire un obus sur une\n case de la carte adverse.\n");
    printf(" Un bateau est touché quand un obus aterrit sur une\n des cases du bateau.\n");
    printf(" Un bateau est coulé quand toutes ses cases sont touchées.\n");
    printf(" Une partie se termine quand un joueur coule tout les\n bateaux adverses\n\n");

    printf("                  ");

    pause();
}

void remplirTableau() {
    for (int i = 0; i < 10; i++) {
        for (int a = 0; a < 10; a++) {
            carte[i][a] = ' ';
        }
    }
}

void afficherCarte() {
    printf("   1  2  3  4  5  6  7  8  9  10\n");

    for (int i = 0, b = 'A'; i < 10, b < 'K'; i++, b++) {
        printf("%c ", b);
        for (int a = 0; a < 10; a++) {
            printf("[%c]", carte[i][a]);
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
    printf("Colonne de la cible : ");
    fflush(stdin);
    scanf("%d", &cibleColonne);
    printf("Ligne de la cible : ");
    fflush(stdin);
    scanf("%c", &cibleLigne);
}

void jouer() {
    clear();

    indicationsJeu();

    remplirTableau();

    afficherCarte();

    pause();
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
